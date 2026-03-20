#include "CvGameCoreDLL.h"
#include "CyCity.h"
#include "CyPlot.h"
#include "CyArea.h"
#include "CvInfos.h"

void CyCityPythonInterface1_Chunk3(python::class_<CyCity>& x)
{
    x.def("getNumNationalWonders", &CyCity::getNumNationalWonders, "int ()");
    x.def("getNumBuildings", &CyCity::getNumBuildings, "int ()");
    x.def("changeGreatPeopleProgress", &CyCity::changeGreatPeopleProgress, "void (int iChange) - adjusts great person progress by iChange");
    x.def("isGovernmentCenter", &CyCity::isGovernmentCenter, "bool () - is city the government center?");
    x.def("getSavedMaintenanceByBuilding", &CyCity::getSavedMaintenanceByBuilding, "int (int /*BuildingTypes*/)");
    x.def("getSavedMaintenanceTimes100ByBuilding", &CyCity::getSavedMaintenanceTimes100ByBuilding, "int (int /*BuildingTypes*/)");
    x.def("getMaintenance", &CyCity::getMaintenance, "int () - cities current maintenance cost");
    x.def("getMaintenanceTimes100", &CyCity::getMaintenanceTimes100, "int () - cities current maintenance cost");
    x.def("calculateDistanceMaintenance", &CyCity::calculateDistanceMaintenance, "int ()");
    x.def("calculateDistanceMaintenanceTimes100", &CyCity::calculateDistanceMaintenanceTimes100, "int ()");
    x.def("calculateNumCitiesMaintenance", &CyCity::calculateNumCitiesMaintenance, "int ()");
    x.def("calculateNumCitiesMaintenanceTimes100", &CyCity::calculateNumCitiesMaintenanceTimes100, "int ()");
    x.def("calculateColonyMaintenance", &CyCity::calculateColonyMaintenance, "int ()");
    x.def("calculateColonyMaintenanceTimes100", &CyCity::calculateColonyMaintenanceTimes100, "int ()");
    x.def("calculateCorporationMaintenance", &CyCity::calculateCorporationMaintenance, "int ()");
    x.def("calculateCorporationMaintenanceTimes100", &CyCity::calculateCorporationMaintenanceTimes100, "int ()");
    x.def("getMaintenanceModifier", &CyCity::getMaintenanceModifier, "int () - total value of the city maintenance modifier");
    x.def("getWarWearinessModifier", &CyCity::getWarWearinessModifier);
    x.def("getHurryAngerModifier", &CyCity::getHurryAngerModifier);
    x.def("changeHealRate", &CyCity::changeHealRate, "void (int iChange) - changes the heal rate of this city to iChange");
    x.def("getEspionageHealthCounter", &CyCity::getEspionageHealthCounter, "int ()");
    x.def("changeEspionageHealthCounter", &CyCity::changeEspionageHealthCounter, "void (int iChange)");
    x.def("getEspionageHappinessCounter", &CyCity::getEspionageHappinessCounter, "int ()");
    x.def("changeEspionageHappinessCounter", &CyCity::changeEspionageHappinessCounter, "void (int iChange)");
    x.def("getFreshWaterGoodHealth", &CyCity::getFreshWaterGoodHealth, "int ()");
    x.def("getFreshWaterBadHealth", &CyCity::getFreshWaterBadHealth, "int ()");
    x.def("getBuildingGoodHealth", &CyCity::getBuildingGoodHealth, "int ()");
    x.def("getBuildingBadHealth", &CyCity::getBuildingBadHealth, "int ()");
    x.def("getFeatureGoodHealth", &CyCity::getFeatureGoodHealth, "int () - returns the good health provided by the feature this city is built on");
    x.def("getFeatureBadHealth", &CyCity::getFeatureBadHealth, "int () - returns the bad health provided by the feature this city is built on");
    x.def("getAdditionalHealthByFeature", &CyCity::getAdditionalHealthByFeature, "int (int /*FeatureTypes*/ eFeature, int iChange) - additional healthiness minus additional unhealthiness");
    x.def("getAdditionalGoodHealthByFeature", &CyCity::getAdditionalGoodHealthByFeature, "int (int /*FeatureTypes*/ eFeature, int iChange) - additional healthiness");
    x.def("getAdditionalBadHealthByFeature", &CyCity::getAdditionalBadHealthByFeature, "int (int /*FeatureTypes*/ eFeature, int iChange) - additional unhealthiness");
    x.def("getBuildingHealth", &CyCity::getBuildingHealth, "int (int eBuilding)");
    x.def("getAdditionalHealthByBuilding", &CyCity::getAdditionalHealthByBuilding, "int (int /*BuildingTypes*/ eBuilding) - additional healthiness minus additional unhealthiness");
    x.def("getAdditionalGoodHealthByBuilding", &CyCity::getAdditionalGoodHealthByBuilding, "int (int /*BuildingTypes*/ eBuilding) - additional healthiness");
    x.def("getAdditionalBadHealthByBuilding", &CyCity::getAdditionalBadHealthByBuilding, "int (int /*BuildingTypes*/ eBuilding) - additional unhealthiness");
    x.def("getAdditionalSpoiledFoodByBuilding", &CyCity::getAdditionalSpoiledFoodByBuilding, "int (int /*BuildingTypes*/ eBuilding) - additional spoiled food");
    x.def("getAdditionalStarvationByBuilding", &CyCity::getAdditionalStarvationByBuilding, "int (int /*BuildingTypes*/ eBuilding) - additional starvation");
    x.def("getPowerGoodHealth", &CyCity::getPowerGoodHealth, "int ()");
    x.def("getPowerBadHealth", &CyCity::getPowerBadHealth, "int ()");
    x.def("getBonusGoodHealth", &CyCity::getBonusGoodHealth, "int ()");
    x.def("getBonusBadHealth", &CyCity::getBonusBadHealth, "int ()");
    x.def("getMilitaryHappiness", &CyCity::getMilitaryHappiness, "int () - happiness created by military units stationed in the city");
    x.def("getMilitaryHappinessUnits", &CyCity::getMilitaryHappinessUnits, "number of military units creating happiness");
    x.def("getBuildingGoodHappiness", &CyCity::getBuildingGoodHappiness, "int ()");
    x.def("getBuildingBadHappiness", &CyCity::getBuildingBadHappiness, "int ()");
    x.def("getBuildingHappiness", &CyCity::getBuildingHappiness, "int (int eBuilding)");
    x.def("getAdditionalHappinessByBuilding", &CyCity::getAdditionalHappinessByBuilding, "int (int /*BuildingTypes*/ eBuilding) - additional happiness minus additional unhappiness");
    x.def("getAdditionalGoodHappinessByBuilding", &CyCity::getAdditionalGoodHappinessByBuilding, "int (int /*BuildingTypes*/ eBuilding) - additional happiness");
    x.def("getAdditionalBadHappinessByBuilding", &CyCity::getAdditionalBadHappinessByBuilding, "int (int /*BuildingTypes*/ eBuilding) - additional unhappiness");
    x.def("getAdditionalAngryPopulationByBuilding", &CyCity::getAdditionalAngryPopulationByBuilding, "int (int /*BuildingTypes*/ eBuilding) - additional angry population");
    x.def("getExtraBuildingGoodHappiness", &CyCity::getExtraBuildingGoodHappiness, "int ()");
    x.def("getExtraBuildingBadHappiness", &CyCity::getExtraBuildingBadHappiness, "int ()");
    x.def("getFeatureGoodHappiness", &CyCity::getFeatureGoodHappiness, "int ()");
    x.def("getFeatureBadHappiness", &CyCity::getFeatureBadHappiness, "int ()");
    x.def("getBonusGoodHappiness", &CyCity::getBonusGoodHappiness, "int ()");
    x.def("getReligionGoodHappiness", &CyCity::getReligionGoodHappiness, "int ()");
    x.def("getReligionBadHappiness", &CyCity::getReligionBadHappiness, "int ()");
    x.def("getReligionHappiness", &CyCity::getReligionHappiness, "int (int eReligion)");
    x.def("getExtraHappiness", &CyCity::getExtraHappiness, "int ()");
    x.def("getExtraHealth", &CyCity::getExtraHealth, "int ()");
    x.def("changeExtraHealth", &CyCity::changeExtraHealth, "void (int iChange)");
    x.def("changeExtraHappiness", &CyCity::changeExtraHappiness, "void (int iChange)");
    x.def("getHurryAngerTimer", &CyCity::getHurryAngerTimer, "int () - Anger caused by Hurrying timer");
    x.def("changeHurryAngerTimer", &CyCity::changeHurryAngerTimer, "void (iChange) - adjust Hurry Angry timer by iChange");
    x.def("getConscriptAngerTimer", &CyCity::getConscriptAngerTimer, "int () - returns the amount of time left on the conscript anger timer");
    x.def("changeConscriptAngerTimer", &CyCity::changeConscriptAngerTimer, "void (int iChange) -changes the amount of time left on the conscript anger timer");
    x.def("getDefyResolutionAngerTimer", &CyCity::getDefyResolutionAngerTimer, "int () - returns the amount of time left on the anger timer");
    x.def("changeDefyResolutionAngerTimer", &CyCity::changeDefyResolutionAngerTimer, "void (int iChange) -changes the amount of time left on the anger timer");
    x.def("flatDefyResolutionAngerLength", &CyCity::flatDefyResolutionAngerLength, "int ()");
    x.def("getHappinessTimer", &CyCity::getHappinessTimer, "int () - Temporary Happiness timer");
    x.def("changeHappinessTimer", &CyCity::changeHappinessTimer, "void (iChange) - adjust Happiness timer by iChange");
    x.def("isNoUnhappiness", &CyCity::isNoUnhappiness, "bool () - is the city unaffected by unhappiness?");
    x.def("isNoUnhealthyPopulation", &CyCity::isNoUnhealthyPopulation, "bool () - is the city unaffected by unhealthiness?");
    x.def("isBuildingOnlyHealthy", &CyCity::isBuildingOnlyHealthy, "bool () - is the city ?");
    x.def("getFood", &CyCity::getFood, "int () - stored food");
    x.def("setFood", &CyCity::setFood, "void (iNewValue) - set stored food to iNewValue");
    x.def("changeFood", &CyCity::changeFood, "void (iChange) - adjust stored food by iChange");
    x.def("getFoodKept", &CyCity::getFoodKept, "int ()");
}
