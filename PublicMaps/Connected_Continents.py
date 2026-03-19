#
# FILE: Connected_Continents.py
# PURPOSE: Custom Continents variant with galley-traversable intercontinental routes.
#

from CvPythonExtensions import *
from CvMapGeneratorUtil import TerrainGenerator, FeatureGenerator
import Custom_Continents

addedIslandPlots = {}


def getDescription():
	return "like Custom Continents, but all continents are connected by a thin strip of land"


def isAdvancedMap():
	return Custom_Continents.isAdvancedMap()


def getNumCustomMapOptions():
	return Custom_Continents.getNumCustomMapOptions()


def getCustomMapOptionName(argsList):
	return Custom_Continents.getCustomMapOptionName(argsList)


def getNumCustomMapOptionValues(argsList):
	return Custom_Continents.getNumCustomMapOptionValues(argsList)


def getCustomMapOptionDescAt(argsList):
	return Custom_Continents.getCustomMapOptionDescAt(argsList)


def getCustomMapOptionDefault(argsList):
	return Custom_Continents.getCustomMapOptionDefault(argsList)


def isRandomCustomMapOption(argsList):
	return Custom_Continents.isRandomCustomMapOption(argsList)


def minStartingDistanceModifier():
	return Custom_Continents.minStartingDistanceModifier()


def beforeGeneration():
	return Custom_Continents.beforeGeneration()


def _index(x, y, w):
	return y * w + x


def _plot(plotTypes, w, x, y):
	return plotTypes[_index(x, y, w)]


def _set_plot(plotTypes, w, h, x, y, plotType):
	if x < 1 or y < 1 or x >= w - 1 or y >= h - 1:
		return
	plotTypes[_index(x, y, w)] = plotType
	addedIslandPlots[(x, y)] = plotType


def _find_land_bands(plotTypes, w, h, x):
	bands = []
	in_band = False
	start = 0
	for y in range(h):
		is_land = (_plot(plotTypes, w, x, y) != PlotTypes.PLOT_OCEAN)
		if is_land and not in_band:
			in_band = True
			start = y
		elif not is_land and in_band:
			bands.append((start, y - 1))
			in_band = False
	if in_band:
		bands.append((start, h - 1))
	return bands


def _band_center(band):
	return (band[0] + band[1]) // 2


def _pick_band_near(bands, targetY):
	if not bands:
		return None
	best = bands[0]
	best_d = abs(_band_center(best) - targetY)
	for band in bands[1:]:
		d = abs(_band_center(band) - targetY)
		if d < best_d:
			best = band
			best_d = d
	return best


def _random_plot_type(dice):
	roll = dice.get(100, "Traversable island plot type")
	if roll < 6:
		return PlotTypes.PLOT_PEAK
	if roll < 30:
		return PlotTypes.PLOT_HILLS
	return PlotTypes.PLOT_LAND


def _carve_island_cluster(plotTypes, w, h, cx, cy, size, dice):
	# Strictly bounded cluster growth.
	cells = [(cx, cy)]
	seen = {(cx, cy): True}
	attempts = 0
	max_attempts = size * 4
	while len(cells) < size and attempts < max_attempts:
		attempts += 1
		bx, by = cells[dice.get(len(cells), "Traversable cluster seed")]
		dirs = [(1,0),(-1,0),(0,1),(0,-1),(1,1),(1,-1),(-1,1),(-1,-1)]
		dx, dy = dirs[dice.get(len(dirs), "Traversable cluster dir")]
		nx, ny = bx + dx, by + dy
		if nx < 1 or ny < 1 or nx >= w - 1 or ny >= h - 1:
			continue
		if (nx, ny) in seen:
			continue
		seen[(nx, ny)] = True
		cells.append((nx, ny))
	for i, (x, y) in enumerate(cells):
		ptype = _random_plot_type(dice)
		if i == 0 and ptype == PlotTypes.PLOT_PEAK:
			ptype = PlotTypes.PLOT_HILLS
		_set_plot(plotTypes, w, h, x, y, ptype)


def _connect_with_random_islands(plotTypes, w, h, x1, y1, x2, y2, dice, maxStep=3):
	cx, cy = x1, y1
	guard = 0
	while (abs(cx - x2) > maxStep or abs(cy - y2) > maxStep) and guard < 40:
		guard += 1
		dx = x2 - cx
		dy = y2 - cy
		stepx = min(maxStep, max(1, abs(dx)))
		stepy = min(maxStep, max(1, abs(dy)))
		if dx > 0:
			nx = cx + stepx
		elif dx < 0:
			nx = cx - stepx
		else:
			nx = cx
		if dy > 0:
			ny = cy + stepy
		elif dy < 0:
			ny = cy - stepy
		else:
			ny = cy
		nx += dice.get(3, "Traversable x jitter") - 1
		ny += dice.get(5, "Traversable y jitter") - 2
		nx = max(1, min(w - 2, nx))
		ny = max(1, min(h - 2, ny))
		size = 4 + dice.get(9, "Traversable island size")
		_carve_island_cluster(plotTypes, w, h, nx, ny, size, dice)
		cx, cy = nx, ny
	_carve_island_cluster(plotTypes, w, h, x2, y2, 6 + dice.get(5, "Traversable endpoint size"), dice)


def _is_land(plotTypes, w, x, y):
	return _plot(plotTypes, w, x, y) != PlotTypes.PLOT_OCEAN


def _neighbors8(x, y, w, h):
	for dx in (-1, 0, 1):
		for dy in (-1, 0, 1):
			if dx == 0 and dy == 0:
				continue
			nx, ny = x + dx, y + dy
			if nx < 0 or ny < 0 or nx >= w or ny >= h:
				continue
			yield (nx, ny)


def _compute_land_components(plotTypes, w, h):
	compByTile = {}
	components = []
	for y in range(h):
		for x in range(w):
			if not _is_land(plotTypes, w, x, y):
				continue
			if (x, y) in compByTile:
				continue
			cid = len(components)
			stack = [(x, y)]
			compByTile[(x, y)] = cid
			tiles = []
			while stack:
				tx, ty = stack.pop()
				tiles.append((tx, ty))
				for nx, ny in _neighbors8(tx, ty, w, h):
					if not _is_land(plotTypes, w, nx, ny):
						continue
					if (nx, ny) in compByTile:
						continue
					compByTile[(nx, ny)] = cid
					stack.append((nx, ny))
			components.append(tiles)
	return compByTile, components


def _coastline_tiles(plotTypes, w, h, compTiles):
	coast = []
	for x, y in compTiles:
		for nx, ny in _neighbors8(x, y, w, h):
			if not _is_land(plotTypes, w, nx, ny):
				coast.append((x, y))
				break
	return coast


def _step_toward(a, b):
	ax, ay = a
	bx, by = b
	dx = 0
	dy = 0
	if bx > ax:
		dx = 1
	elif bx < ax:
		dx = -1
	if by > ay:
		dy = 1
	elif by < ay:
		dy = -1
	return (ax + dx, ay + dy)


def _nearest_pair(pointsA, pointsB):
	best = None
	bestD = 10 ** 9
	for ax, ay in pointsA:
		for bx, by in pointsB:
			d = max(abs(ax - bx), abs(ay - by))
			if d < bestD:
				bestD = d
				best = (ax, ay, bx, by)
	return best, bestD


def _ensure_all_continents_galley_connected(plotTypes, w, h, dice):
	# Connect every land component to the largest one.
	for passNum in range(8):
		compByTile, comps = _compute_land_components(plotTypes, w, h)
		if len(comps) <= 1:
			return
		mainId = 0
		mainSize = len(comps[0])
		for i in range(1, len(comps)):
			sz = len(comps[i])
			if sz > mainSize:
				mainSize = sz
				mainId = i
		mainCoast = _coastline_tiles(plotTypes, w, h, comps[mainId])
		if not mainCoast:
			return
		changed = False
		for cid in range(len(comps)):
			if cid == mainId:
				continue
			coast = _coastline_tiles(plotTypes, w, h, comps[cid])
			if not coast:
				continue
			pair, dist = _nearest_pair(coast, mainCoast)
			if pair is None:
				continue
			ax, ay, bx, by = pair
			if dist <= 2:
				mx, my = _step_toward((ax, ay), (bx, by))
				_set_plot(plotTypes, w, h, mx, my, PlotTypes.PLOT_LAND)
			else:
				_connect_with_random_islands(plotTypes, w, h, ax, ay, bx, by, dice, maxStep=4)
			changed = True
		if not changed:
			return


def generatePlotTypes():
	NiTextOut("Setting Plot Types (Python Traversable Continents) ...")
	NiTextOut("Traversable Continents: base Custom Continents plot generation...")
	plotTypes = Custom_Continents.generatePlotTypes()
	map = CyMap()
	dice = CyGlobalContext().getGame().getMapRand()
	w = map.getGridWidth()
	h = map.getGridHeight()
	global addedIslandPlots
	addedIslandPlots = {}

	NiTextOut("Traversable Continents: building horizontal galley lanes...")
	# Fewer, broader lanes to keep runtime bounded and still bridge upper/lower continents.
	anchorXs = [int(w * 0.22), int(w * 0.5), int(w * 0.78)]
	target_rows = [h // 3, (2 * h) // 3]

	for row in target_rows:
		prev = None
		for x in anchorXs:
			bands = _find_land_bands(plotTypes, w, h, x)
			band = _pick_band_near(bands, row)
			if band is None:
				continue
			point = (x, _band_center(band))
			if prev is not None:
				_connect_with_random_islands(plotTypes, w, h, prev[0], prev[1], point[0], point[1], dice, maxStep=4)
			prev = point

	NiTextOut("Traversable Continents: building vertical galley bridges...")
	# Explicit top-to-bottom bridges in multiple columns.
	for x in [int(w * 0.28), int(w * 0.5), int(w * 0.72)]:
		bands = _find_land_bands(plotTypes, w, h, x)
		top_band = _pick_band_near(bands, h // 4)
		bot_band = _pick_band_near(bands, (3 * h) // 4)
		if top_band is not None and bot_band is not None:
			_connect_with_random_islands(plotTypes, w, h, x, _band_center(top_band), x + (dice.get(5, "Top-bottom x shift") - 2), _band_center(bot_band), dice, maxStep=4)

	NiTextOut("Traversable Continents: ensuring all continents are coast-connected...")
	_ensure_all_continents_galley_connected(plotTypes, w, h, dice)

	NiTextOut("Traversable Continents: plot generation complete.")
	return plotTypes


class ReducedClimateTerrainGenerator(TerrainGenerator):
	def __init__(self):
		TerrainGenerator.__init__(self, iDesertPercent=16, iPlainsPercent=22,
			fSnowLatitude=0.82, fTundraLatitude=0.72,
			fGrassLatitude=0.1,
			fDesertBottomLatitude=0.24, fDesertTopLatitude=0.44,
			fracXExp=-1, fracYExp=-1, grain_amount=4)


def generateTerrainTypes():
	NiTextOut("Generating Terrain (Python Traversable Continents) ...")
	NiTextOut("Traversable Continents: assigning terrain types...")
	terrainTypes = ReducedClimateTerrainGenerator().generateTerrain()
	gc = CyGlobalContext()
	map = CyMap()
	w = map.getGridWidth()
	terrainGrass = gc.getInfoTypeForString("TERRAIN_GRASS")
	terrainPlains = gc.getInfoTypeForString("TERRAIN_PLAINS")
	terrainTundra = gc.getInfoTypeForString("TERRAIN_TUNDRA")
	dice = gc.getGame().getMapRand()
	for (x, y), ptype in addedIslandPlots.items():
		idx = _index(x, y, w)
		if ptype == PlotTypes.PLOT_PEAK:
			if dice.get(100, "Peak island terrain") < 10:
				terrainTypes[idx] = terrainTundra
			else:
				terrainTypes[idx] = terrainPlains
		elif ptype == PlotTypes.PLOT_HILLS:
			if dice.get(100, "Hill island terrain") < 70:
				terrainTypes[idx] = terrainPlains
			else:
				terrainTypes[idx] = terrainGrass
		else:
			if dice.get(100, "Land island terrain") < 45:
				terrainTypes[idx] = terrainGrass
			else:
				terrainTypes[idx] = terrainPlains
	NiTextOut("Traversable Continents: terrain generation complete.")
	return terrainTypes


class ReducedJungleFeatureGenerator(FeatureGenerator):
	def __init__(self):
		FeatureGenerator.__init__(self, iJunglePercent=48, iForestPercent=57,
			jungle_grain=5, forest_grain=6,
			fracXExp=-1, fracYExp=-1)


def addFeatures():
	NiTextOut("Adding Features (Python Traversable Continents) ...")
	NiTextOut("Traversable Continents: adding features...")
	ReducedJungleFeatureGenerator().addFeatures()
	map = CyMap()
	gc = CyGlobalContext()
	jungle = gc.getInfoTypeForString("FEATURE_JUNGLE")
	for (x, y), ptype in addedIslandPlots.items():
		plot = map.plot(x, y)
		if plot.getFeatureType() == jungle:
			plot.setFeatureType(FeatureTypes.NO_FEATURE, -1)
	NiTextOut("Traversable Continents: feature generation complete.")
	return 0


def assignStartingPlots():
	return Custom_Continents.assignStartingPlots()


def findStartingPlot(argsList):
	return Custom_Continents.findStartingPlot(argsList)


def normalizeStartingPlotLocations():
	return Custom_Continents.normalizeStartingPlotLocations()
