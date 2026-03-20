#include "CvGameCoreDLL.h"
#include "CyCity.h"
#include "CyPlot.h"
#include "CyArea.h"
#include "CvInfos.h"

void CyCityPythonInterface1_Chunk4(python::class_<CyCity>& x)
{
    x.def("getMaxFoodKeptPercent", &CyCity::getMaxFoodKeptPercent, "int ()");
    x.def("getOverflowProduction", &CyCity::getOverflowProduction, "int () - value of overflow production");
    x.def("setOverflowProduction", &CyCity::setOverflowProduction, "void (iNewValue) - set overflow production to iNewValue");
    x.def("getFeatureProduction", &CyCity::getFeatureProduction, "int () - value of feature production");
    x.def("setFeatureProduction", &CyCity::setFeatureProduction, "void (iNewValue) - set feature production to iNewValue");
    x.def("getMilitaryProductionModifier", &CyCity::getMilitaryProductionModifier, "int () - value of adjustments to military production");
    x.def("getSpaceProductionModifier", &CyCity::getSpaceProductionModifier, "int ()");
    x.def("getExtraTradeRoutes", &CyCity::getExtraTradeRoutes, "int () - returns the number of extra trade routes this city has");
    x.def("changeExtraTradeRoutes", &CyCity::changeExtraTradeRoutes, "void (iChange) - Change the number of trade routes this city has");
    x.def("getTradeRouteModifier", &CyCity::getTradeRouteModifier, "int ()");
    x.def("getForeignTradeRouteModifier", &CyCity::getForeignTradeRouteModifier, "int ()");
    x.def("getBuildingDefense", &CyCity::getBuildingDefense, "int () - building defense");
    x.def("getAdditionalDefenseByBuilding", &CyCity::getAdditionalDefenseByBuilding, "int (int /*BuildingTypes*/) - additional building defense");
    x.def("getBuildingBombardDefense", &CyCity::getBuildingBombardDefense, "int () - building defense");
    x.def("getAdditionalBombardDefenseByBuilding", &CyCity::getAdditionalBombardDefenseByBuilding, "int (int /*BuildingTypes*/) - additional building bombard defense");
    x.def("getFreeExperience", &CyCity::getFreeExperience, "int () - # of free experience newly trained units receive");
    x.def("getCurrAirlift", &CyCity::getCurrAirlift, "int ()");
    x.def("getMaxAirlift", &CyCity::getMaxAirlift, "int ()");
    x.def("getAirModifier", &CyCity::getAirModifier, "int () - returns the air defense modifier");
    x.def("getAirUnitCapacity", &CyCity::getAirUnitCapacity, "int (int /*TeamTypes*/ eTeam) - returns the number of air units allowed here");
    x.def("getNukeModifier", &CyCity::getNukeModifier, "int ()");
    x.def("getFreeSpecialist", &CyCity::getFreeSpecialist, "int ()");
    x.def("isPower", &CyCity::isPower, "bool ()");
    x.def("isAreaCleanPower", &CyCity::isAreaCleanPower, "bool ()");
    x.def("isDirtyPower", &CyCity::isDirtyPower, "bool ()");
    x.def("getDefenseDamage", &CyCity::getDefenseDamage, "int () - value of damage city defenses can receive");
    x.def("changeDefenseDamage", &CyCity::changeDefenseDamage, "void (iChange) - adjust damage value by iChange");
    x.def("isBombardable", &CyCity::isBombardable, "bool (CyUnit* pUnit)");
    x.def("getNaturalDefense", &CyCity::getNaturalDefense, "int ()");
    x.def("getTotalDefense", &CyCity::getTotalDefense, "int (bool bIgnoreBuilding)");
    x.def("getDefenseModifier", &CyCity::getDefenseModifier, "int (bool bIgnoreBuilding)");
    x.def("getOccupationTimer", &CyCity::getOccupationTimer, "int () - total # of turns remaining on occupation timer");
    x.def("isOccupation", &CyCity::isOccupation, "bool () - is the city under occupation?");
    x.def("setOccupationTimer", &CyCity::setOccupationTimer, "void (iNewValue) - set the Occupation Timer to iNewValue");
    x.def("changeOccupationTimer", &CyCity::changeOccupationTimer, "void (iChange) - adjusts the Occupation Timer by iChange");
    x.def("getCultureUpdateTimer", &CyCity::getCultureUpdateTimer, "int () - Culture Update Timer");
    x.def("changeCultureUpdateTimer", &CyCity::changeCultureUpdateTimer, "void (iChange) - adjusts the Culture Update Timer by iChange");
    x.def("isNeverLost", &CyCity::isNeverLost, "bool ()");
    x.def("setNeverLost", &CyCity::setNeverLost, "void (iNewValue)");
    x.def("isBombarded", &CyCity::isBombarded, "bool ()");
    x.def("setBombarded", &CyCity::setBombarded, "void (iNewValue)");
    x.def("isDrafted", &CyCity::isDrafted, "bool ()");
    x.def("setDrafted", &CyCity::setDrafted, "void (iNewValue)");
    x.def("isAirliftTargeted", &CyCity::isAirliftTargeted, "bool ()");
    x.def("setAirliftTargeted", &CyCity::setAirliftTargeted, "void (iNewValue)");
    x.def("isCitizensAutomated", &CyCity::isCitizensAutomated, "bool () - are citizens under automation?");
    x.def("setCitizensAutomated", &CyCity::setCitizensAutomated, "void (bool bNewValue) - set city animation bNewValue");
    x.def("isProductionAutomated", &CyCity::isProductionAutomated, "bool () - is production under automation?");
    x.def("setProductionAutomated", &CyCity::setProductionAutomated, "void (bool bNewValue) - set city production automation to bNewValue");
    x.def("isWallOverride", &CyCity::isWallOverride, "bool isWallOverride()");
    x.def("setWallOverride", &CyCity::setWallOverride, "setWallOverride(bool bOverride)");
    x.def("setCitySizeBoost", &CyCity::setCitySizeBoost, "setCitySizeBoost(int iBoost)");
    x.def("isPlundered", &CyCity::isPlundered, "bool ()");
    x.def("setPlundered", &CyCity::setPlundered, "void (iNewValue)");
    x.def("getOwner", &CyCity::getOwner, "int /*PlayerTypes*/ ()");
    x.def("getTeam", &CyCity::getTeam, "int /*TeamTypes*/ ()");
    x.def("getPreviousOwner", &CyCity::getPreviousOwner, "int /*PlayerTypes*/ ()");
    x.def("getOriginalOwner", &CyCity::getOriginalOwner, "int /*PlayerTypes*/ ()");
    x.def("getCultureLevel", &CyCity::getCultureLevel, "int /*CultureLevelTypes*/ ()");
    x.def("getCultureThreshold", &CyCity::getCultureThreshold);
    x.def("getSeaPlotYield", &CyCity::getSeaPlotYield, "int (int /*YieldTypes*/) - total YieldType for water plots");
    x.def("getRiverPlotYield", &CyCity::getRiverPlotYield, "int (int /*YieldTypes*/) - total YieldType for river plots");
    x.def("getAdditionalYieldByBuilding", &CyCity::getAdditionalYieldByBuilding, "int (int /*YieldTypes*/, int /*BuildingTypes*/) - total change of YieldType from adding one BuildingType");
    x.def("getAdditionalBaseYieldRateByBuilding", &CyCity::getAdditionalBaseYieldRateByBuilding, "int (int /*YieldTypes*/, int /*BuildingTypes*/) - base rate change of YieldType from adding one BuildingType");
    x.def("getAdditionalYieldRateModifierByBuilding", &CyCity::getAdditionalYieldRateModifierByBuilding, "int (int /*YieldTypes*/, int /*BuildingTypes*/) - rate modifier change of YieldType from adding one BuildingType");
    x.def("getBaseYieldRate", &CyCity::getBaseYieldRate, "int (int /*YieldTypes*/) - base rate for YieldType");
    x.def("setBaseYieldRate", &CyCity::setBaseYieldRate, "int (int /*YieldTypes*/, int iNewValue) - sets the base rate for YieldType");
    x.def("changeBaseYieldRate", &CyCity::changeBaseYieldRate, "int (int /*YieldTypes*/, int iChange) - changes the base rate for YieldType");
    x.def("getBaseYieldRateModifier", &CyCity::getBaseYieldRateModifier);
    x.def("getYieldRate", &CyCity::getYieldRate, "int (int /*YieldTypes*/) - total value of YieldType");
    x.def("getYieldRateModifier", &CyCity::getYieldRateModifier, "int (int /*YieldTypes*/) - yield rate modifier for YieldType");
    x.def("getTradeYield", &CyCity::getTradeYield, "int (int /*YieldTypes*/) - trade adjustment to YieldType");
    x.def("totalTradeModifier", &CyCity::totalTradeModifier, "int () - total trade adjustment");
#ifdef _MOD_FRACTRADE
    x.def("calculateTradeProfitTimes100", &CyCity::calculateTradeProfitTimes100, "int (CyCity) - returns the unrounded trade profit created by CyCity");
#endif
    x.def("calculateTradeProfit", &CyCity::calculateTradeProfit, "int (CyCity) - returns the trade profit created by CyCity");
    x.def("calculateTradeYield", &CyCity::calculateTradeYield, "int (YieldType, int iTradeProfit) - calculates Trade Yield");
    x.def("getExtraSpecialistYield", &CyCity::getExtraSpecialistYield, "int (int /*YieldTypes*/ eIndex)");
    x.def("getExtraSpecialistYieldOfType", &CyCity::getExtraSpecialistYieldOfType, "int (int /*YieldTypes*/ eIndex, int /*SpecialistTypes*/ eSpecialist)");
    x.def("getCommerceRate", &CyCity::getCommerceRate, "int (int /*CommerceTypes*/) - total Commerce rate");
    x.def("getCommerceRateTimes100", &CyCity::getCommerceRateTimes100, "int (int /*CommerceTypes*/) - total Commerce rate");
}
