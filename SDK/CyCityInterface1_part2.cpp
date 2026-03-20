#include "CvGameCoreDLL.h"
#include "CyCity.h"
#include "CyPlot.h"
#include "CyArea.h"
#include "CvInfos.h"

void CyCityPythonInterface1_Chunk2(python::class_<CyCity>& x)
{
    x.def("hasTrait", &CyCity::hasTrait, "bool (TraitID) - does owner have TraitID?");
    x.def("isBarbarian", &CyCity::isBarbarian, "bool () - is owner a barbarian?");
    x.def("isHuman", &CyCity::isHuman, "bool () - is owner human?");
    x.def("isVisible", &CyCity::isVisible, "bool (int /*TeamTypes*/ eTeam, bool bDebug)");
    x.def("isCapital", &CyCity::isCapital, "bool () - is city the owners capital?");
    x.def("isCoastal", &CyCity::isCoastal, "bool (int) - is the city on the coast?");
    x.def("isDisorder", &CyCity::isDisorder, "bool () - is the city in disorder?");
    x.def("isHolyCityByType", &CyCity::isHolyCityByType, "bool (ReligionID) - is the city ReligionID's holy city?");
    x.def("isHolyCity", &CyCity::isHolyCity, "bool () - is the city ReligionID's holy city?");
    x.def("isHeadquartersByType", &CyCity::isHeadquartersByType, "bool (CorporationID) - is the city CorporationID's headquarters?");
    x.def("isHeadquarters", &CyCity::isHeadquarters, "bool () - is the city CorporationID's headquarters?");
    x.def("getOvercrowdingPercentAnger", &CyCity::getOvercrowdingPercentAnger, "int (iExtra)");
    x.def("getNoMilitaryPercentAnger", &CyCity::getNoMilitaryPercentAnger, "int ()");
    x.def("getCulturePercentAnger", &CyCity::getCulturePercentAnger, "int ()");
    x.def("getReligionPercentAnger", &CyCity::getReligionPercentAnger, "int ()");
    x.def("getWarWearinessPercentAnger", &CyCity::getWarWearinessPercentAnger, "int ()");
    x.def("getLargestCityHappiness", &CyCity::getLargestCityHappiness, "int ()");
    x.def("unhappyLevel", &CyCity::unhappyLevel, "int (int iExtra)");
    x.def("happyLevel", &CyCity::happyLevel, "int ()");
    x.def("angryPopulation", &CyCity::angryPopulation, "int (iExtra) - # of unhappy citizens");
    x.def("totalFreeSpecialists", &CyCity::totalFreeSpecialists);
    x.def("extraFreeSpecialists", &CyCity::extraFreeSpecialists, "int () - # of specialist that are allowed for free");
    x.def("extraPopulation", &CyCity::extraPopulation, "int () - # of extra/available citizens");
    x.def("extraSpecialists", &CyCity::extraSpecialists, "int () - # of extra/available specialists");
    x.def("unhealthyPopulation", &CyCity::unhealthyPopulation, "int (bool bNoAngry), int (iExtra)");
    x.def("totalGoodBuildingHealth", &CyCity::totalGoodBuildingHealth, "int ()");
    x.def("totalBadBuildingHealth", &CyCity::totalBadBuildingHealth, "int ()");
    x.def("goodHealth", &CyCity::goodHealth, "int () - total health");
    x.def("badHealth", &CyCity::badHealth, "int (bool bNoAngry) - total unhealthiness");
    x.def("healthRate", &CyCity::healthRate, "int (bool bNoAngry, int iExtra)");
    x.def("foodConsumption", &CyCity::foodConsumption, "int (bool bNoAngry, int iExtra)");
    x.def("foodDifference", &CyCity::foodDifference, "int (bool bBottom) - result of getYieldRate(Food) - foodConsumption()");
    x.def("growthThreshold", &CyCity::growthThreshold, "int () - value needed for growth");
    x.def("productionLeft", &CyCity::productionLeft, "int () - result of (getProductionNeeded() - getProduction()");
    x.def("hurryCost", &CyCity::hurryCost, "int (bool bExtra)");
    x.def("hurryGold", &CyCity::hurryGold, "int (HurryID) - total value of gold when hurrying");
    x.def("hurryPopulation", &CyCity::hurryPopulation, "int (HurryID) - value of each pop when hurrying");
    x.def("hurryProduction", &CyCity::hurryProduction, "int (HurryID)");
    x.def("flatHurryAngerLength", &CyCity::flatHurryAngerLength, "int ()");
    x.def("hurryAngerLength", &CyCity::hurryAngerLength, "int (HurryID)");
    x.def("maxHurryPopulation", &CyCity::maxHurryPopulation, "int ()");
    x.def("cultureDistance", &CyCity::cultureDistance, "int (iDX, iDY) - culture distance");
    x.def("cultureStrength", &CyCity::cultureStrength, "int (ePlayer)");
    x.def("cultureGarrison", &CyCity::cultureGarrison, "int (ePlayer)");
    x.def("getNumBuilding", &CyCity::getNumBuilding, "int - (BuildingID) - How many BuildingID does this city have (real or free)?");
    x.def("isHasBuilding", &CyCity::isHasBuilding, "bool (int iBuildingID) - This function actually no longer exists in C++, this is a helper function which hooks up to getNumBuilding() to help mod backwards compatibility");
    x.def("getNumActiveBuilding", &CyCity::getNumActiveBuilding, "bool (BuildingID) - is BuildingID active in the city (present & not obsolete)?");
    x.def("getID", &CyCity::getID, "int () - index ID # for the city - use with pPlayer.getCity(ID) to obtain city instance");
    x.def("getX", &CyCity::getX, "int () - X coordinate for the cities plot");
    x.def("getY", &CyCity::getY, "int () - Y coordinate for the cities plot");
    x.def("at", &CyCity::at, "bool (iX, iY) - is the city at (iX, iY) ?");
    x.def("atPlot", &CyCity::atPlot, "bool (CyPlot) - is pPlot the cities plot?");
    x.def("plot", &CyCity::plot, python::return_value_policy<python::manage_new_object>(), "CyPlot () - returns cities plot instance");
    x.def("isConnectedTo", &CyCity::isConnectedTo, "bool (CyCity*) - is city connected to CyCity* via the Trade Network?");
    x.def("isConnectedToCapital", &CyCity::isConnectedToCapital, "bool (iOwner) - connected to the capital?");
    x.def("area", &CyCity::area, python::return_value_policy<python::manage_new_object>(), "CyArea() () - returns CyArea instance for location of city");
    x.def("waterArea", &CyCity::waterArea, python::return_value_policy<python::manage_new_object>(), "CyArea* ()");
    x.def("getRallyPlot", &CyCity::getRallyPlot, python::return_value_policy<python::manage_new_object>(), "CyPlot () - returns city's rally plot instance");
    x.def("getGameTurnFounded", &CyCity::getGameTurnFounded, "int () - GameTurn the city was founded");
    x.def("getGameTurnAcquired", &CyCity::getGameTurnAcquired, "int ()");
    x.def("getPopulation", &CyCity::getPopulation, "int () - total city population");
    x.def("setPopulation", &CyCity::setPopulation, "void (int iNewValue) - sets the city population to iNewValue");
    x.def("changePopulation", &CyCity::changePopulation, "void (int iChange) - adjusts the city population by iChange");
    x.def("getRealPopulation", &CyCity::getRealPopulation, "int () - total city population in \"real\" numbers");
    x.def("getHighestPopulation", &CyCity::getHighestPopulation, "int () ");
    x.def("setHighestPopulation", &CyCity::setHighestPopulation, "void (iNewValue)");
    x.def("getWorkingPopulation", &CyCity::getWorkingPopulation, "int () - # of citizens who are working");
    x.def("getSpecialistPopulation", &CyCity::getSpecialistPopulation, "int () - # of specialists");
    x.def("getNumGreatPeople", &CyCity::getNumGreatPeople, "int () - # of great people who are joined to the city");
    x.def("getBaseGreatPeopleRate", &CyCity::getBaseGreatPeopleRate, "int () - base great person rate");
    x.def("getGreatPeopleRate", &CyCity::getGreatPeopleRate, "int () - total Great Person rate");
    x.def("getTotalGreatPeopleRateModifier", &CyCity::getTotalGreatPeopleRateModifier, "int ()");
    x.def("changeBaseGreatPeopleRate", &CyCity::changeBaseGreatPeopleRate);
    x.def("getGreatPeopleProgress", &CyCity::getGreatPeopleProgress, "int () - current great person progress");
    x.def("getGreatPeopleRateModifier", &CyCity::getGreatPeopleRateModifier, "int ()");
    x.def("getAdditionalGreatPeopleRateByBuilding", &CyCity::getAdditionalGreatPeopleRateByBuilding, "int (int /*BuildingTypes*/)");
    x.def("getAdditionalBaseGreatPeopleRateByBuilding", &CyCity::getAdditionalBaseGreatPeopleRateByBuilding, "int (int /*BuildingTypes*/)");
    x.def("getAdditionalGreatPeopleRateModifierByBuilding", &CyCity::getAdditionalGreatPeopleRateModifierByBuilding, "int (int /*BuildingTypes*/)");
    x.def("getNumWorldWonders", &CyCity::getNumWorldWonders, "int ()");
    x.def("getNumTeamWonders", &CyCity::getNumTeamWonders, "int ()");
}
