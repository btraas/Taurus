#include "CvGameCoreDLL.h"
#include "CyCity.h"
#include "CyPlot.h"
#include "CyArea.h"
#include "CvInfos.h"

void CyCityPythonInterface1_Chunk1(python::class_<CyCity>& x)
{
    x.def("isNone", &CyCity::isNone, "void () - is the instance valid?");
    x.def("kill", &CyCity::kill, "void () - kill the city");
    x.def("doTask", &CyCity::doTask, "void (int eTaskTypes, int iData1, int iData2, bool bOption) - Enacts the TaskType passed");
    x.def("chooseProduction", &CyCity::chooseProduction, "void (int /*UnitTypes*/ eTrainUnit, int /*BuildingTypes*/ eConstructBuilding, int /*ProjectTypes*/ eCreateProject, bool bFinish, bool bFront) - Chooses production for a city");
    x.def("createGreatPeople", &CyCity::createGreatPeople, "void (int /*UnitTypes*/ eGreatPersonUnit, bool bIncrementThreshold) - Creates a great person in this city and whether it should increment the threshold to the next level");
    x.def("getCityPlotIndex", &CyCity::getCityPlotIndex, "int (CyPlot* pPlot)");
    x.def("getCityIndexPlot", &CyCity::getCityIndexPlot, python::return_value_policy<python::manage_new_object>(), "CyPlot* (int iIndex)");
    x.def("canWork", &CyCity::canWork, "bool (CyPlot*) - can the city work the plot?");
    x.def("clearWorkingOverride", &CyCity::clearWorkingOverride, "void (int iIndex)");
    x.def("countNumImprovedPlots", &CyCity::countNumImprovedPlots, "int ()");
    x.def("countNumWaterPlots", &CyCity::countNumWaterPlots, "int ()");
    x.def("countNumRiverPlots", &CyCity::countNumRiverPlots, "int ()");
    x.def("findPopulationRank", &CyCity::findPopulationRank, "int ()");
    x.def("findBaseYieldRateRank", &CyCity::findBaseYieldRateRank, "int (int /*YieldTypes*/ eYield)");
    x.def("findYieldRateRank", &CyCity::findYieldRateRank, "int (int /*YieldTypes*/ eYield)");
    x.def("findCommerceRateRank", &CyCity::findCommerceRateRank, "int (int /*CommerceTypes*/ eCommerce)");
    x.def("allUpgradesAvailable", &CyCity::allUpgradesAvailable, "int UnitTypes (int eUnit, int iUpgradeCount)");
    x.def("isWorldWondersMaxed", &CyCity::isWorldWondersMaxed, "bool ()");
    x.def("isTeamWondersMaxed", &CyCity::isTeamWondersMaxed, "bool ()");
    x.def("isNationalWondersMaxed", &CyCity::isNationalWondersMaxed, "bool ()");
    x.def("isBuildingsMaxed", &CyCity::isBuildingsMaxed, "bool ()");
    x.def("canTrain", &CyCity::canTrain, "bool (int eUnit, bool bContinue, bool bTestVisible)");
    x.def("canConstruct", &CyCity::canConstruct, "bool (int eBuilding, bool bContinue, bool bTestVisible, bool bIgnoreCost)");
    x.def("canCreate", &CyCity::canCreate, "bool (int eProject, bool bContinue, bool bTestVisible)");
    x.def("canMaintain", &CyCity::canMaintain, "bool (int eProcess, bool bContinue)");
    x.def("canJoin", &CyCity::canJoin, "bool () - can a Great Person join the city");
    x.def("getFoodTurnsLeft", &CyCity::getFoodTurnsLeft, "int () - how many food turns remain?");
    x.def("isProduction", &CyCity::isProduction, "bool () - is city producing?");
    x.def("isProductionLimited", &CyCity::isProductionLimited, "bool ()");
    x.def("isProductionUnit", &CyCity::isProductionUnit, "bool () - is city training a unit?");
    x.def("isProductionBuilding", &CyCity::isProductionBuilding, "bool () - is city constructing a building?");
    x.def("isProductionProject", &CyCity::isProductionProject, "bool ()");
    x.def("isProductionProcess", &CyCity::isProductionProcess, "bool () - is city maintaining a process?");
    x.def("canContinueProduction", &CyCity::canContinueProduction, "bool (OrderData order)");
    x.def("getProductionExperience", &CyCity::getProductionExperience, "int (int /*UnitTypes*/ eUnit)");
    x.def("addProductionExperience", &CyCity::addProductionExperience, "void (CyUnit* pUnit, bool bConscript)");
    x.def("getProductionUnit", &CyCity::getProductionUnit, "UnitID () - ID for unit that is being trained");
    x.def("getProductionUnitAI", &CyCity::getProductionUnitAI, "int eUnitAIType ()");
    x.def("getProductionBuilding", &CyCity::getProductionBuilding, "BuildingID () - ID for building that is under construction");
    x.def("getProductionProject", &CyCity::getProductionProject, "int /*ProjectTypes*/ ()");
    x.def("getProductionProcess", &CyCity::getProductionProcess, "int /*ProcessTypes*/ ()");
    x.def("getProductionName", &CyCity::getProductionName, "str () - description of item that the city is working on");
    x.def("getGeneralProductionTurnsLeft", &CyCity::getGeneralProductionTurnsLeft, "int - # of production turns left for the top order node item in a city...");
    x.def("getProductionNameKey", &CyCity::getProductionNameKey, "str () - description of item that the city is working on");
    x.def("isFoodProduction", &CyCity::isFoodProduction, "bool () - is item under construction being created with food instead of production?");
    x.def("getFirstUnitOrder", &CyCity::getFirstUnitOrder, "int (int /*UnitTypes*/ eUnit)");
    x.def("getFirstBuildingOrder", &CyCity::getFirstBuildingOrder, "int (int /*BuildingTypes*/ eBuilding)");
    x.def("getFirstProjectOrder", &CyCity::getFirstProjectOrder, "int (int /*ProjectTypes*/ eProject)");
    x.def("isUnitFoodProduction", &CyCity::isUnitFoodProduction, "bool (UnitID) - does UnitID require food to be trained?");
    x.def("getProduction", &CyCity::getProduction, "int () - returns the current production towards whatever is top of this city's OrderQueue");
    x.def("getProductionNeeded", &CyCity::getProductionNeeded, "int () - # of production needed to complete construction");
    x.def("getProductionTurnsLeft", &CyCity::getProductionTurnsLeft, "int () - # of turns remaining until item is completed");
    x.def("getUnitProductionTurnsLeft", &CyCity::getUnitProductionTurnsLeft, "int (UnitID, int iNum) - # of turns remaining to complete UnitID");
    x.def("getBuildingProductionTurnsLeft", &CyCity::getBuildingProductionTurnsLeft, "int (BuildingID, int iNum) - # of turns remaining to complete UnitID");
    x.def("getProjectProductionTurnsLeft", &CyCity::getProjectProductionTurnsLeft, "int (int /*ProjectTypes*/ eProject, int iNum)");
    x.def("setProduction", &CyCity::setProduction, "void (int iNewValue)");
    x.def("changeProduction", &CyCity::changeProduction, "void (int iChange)");
    x.def("getProductionModifier", &CyCity::getProductionModifier, "int () - multiplier (if any) for item being produced");
    x.def("getCurrentProductionDifference", &CyCity::getCurrentProductionDifference, "int (bool bIgnoreFood, bool bOverflow)");
    x.def("getUnitProductionModifier", &CyCity::getUnitProductionModifier, "int (UnitID) - production multiplier for UnitID");
    x.def("getBuildingProductionModifier", &CyCity::getBuildingProductionModifier, "int (BuildingID) - production multiplier for BuildingID");
    x.def("getProjectProductionModifier", &CyCity::getProductionModifier, "int (int /*ProjectTypes*/ eProject)");
    x.def("getExtraProductionDifference", &CyCity::getExtraProductionDifference, "int (int iExtra)");
    x.def("canHurry", &CyCity::canHurry, "bool (HurryTypes eHurry, bool bTestVisible = 0) - can player eHurry in this city?");
    x.def("hurry", &CyCity::hurry, "void (HurryTypes eHurry) - forces the city to rush production using eHurry");
    x.def("getConscriptUnit", &CyCity::getConscriptUnit, "UnitID () - UnitID for the best unit the city can conscript");
    x.def("getConscriptPopulation", &CyCity::getConscriptPopulation, "int ()");
    x.def("conscriptMinCityPopulation", &CyCity::conscriptMinCityPopulation, "int ()");
    x.def("flatConscriptAngerLength", &CyCity::flatConscriptAngerLength, "int ()");
    x.def("canConscript", &CyCity::canConscript, "bool () - can the city conscript units?");
    x.def("conscript", &CyCity::conscript, "void () - conscripts a unit");
    x.def("getBonusHealth", &CyCity::getBonusHealth, "int (BonusID) - total health bonus from BonusID");
    x.def("getBonusHappiness", &CyCity::getBonusHappiness, "int (BonusID) - total happiness bonus from BonusID");
    x.def("getBonusPower", &CyCity::getBonusPower, "int (int /*BonusTypes*/ eBonus, bool bDirty)");
    x.def("getBonusYieldRateModifier", &CyCity::getBonusYieldRateModifier, "int (int /*YieldTypes*/ eIndex, int /*BonusTypes*/ eBonus)");
    x.def("getHandicapType", &CyCity::getHandicapType, "HandicapType () - owners difficulty level");
    x.def("getCivilizationType", &CyCity::getCivilizationType, "CivilizationID () - owners CivilizationID");
    x.def("getPersonalityType", &CyCity::getPersonalityType, "int /*LeaderHeadTypes*/ ()");
    x.def("getArtStyleType", &CyCity::getArtStyleType, "int /*ArtStyleTypes*/ ()");
    x.def("getCitySizeType", &CyCity::getCitySizeType, "int /*CitySizeTypes*/ ()");
}
