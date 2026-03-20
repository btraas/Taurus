#include "CvGameCoreDLL.h"
#include "CyCity.h"
#include "CyPlot.h"
#include "CyArea.h"
#include "CvInfos.h"

void CyCityPythonInterface1_Chunk5(python::class_<CyCity>& x)
{
    x.def("getCommerceFromPercent", &CyCity::getCommerceFromPercent, "int (int /*CommerceTypes*/, int iYieldRate)");
    x.def("getBaseCommerceRate", &CyCity::getBaseCommerceRate, "int (int /*CommerceTypes*/)");
    x.def("getBaseCommerceRateTimes100", &CyCity::getBaseCommerceRateTimes100, "int (int /*CommerceTypes*/)");
    x.def("getTotalCommerceRateModifier", &CyCity::getTotalCommerceRateModifier, "int (int /*CommerceTypes*/)");
    x.def("getProductionToCommerceModifier", &CyCity::getProductionToCommerceModifier, "int (int /*CommerceTypes*/) - value of production to commerce modifier");
    x.def("getBuildingCommerce", &CyCity::getBuildingCommerce, "int (int /*CommerceTypes*/) - total effect of cities buildings on CommerceTypes");
    x.def("getBuildingCommerceByBuilding", &CyCity::getBuildingCommerceByBuilding, "int (int /*CommerceTypes*/, BuildingTypes) - total value of CommerceType from BuildingTypes");
    x.def("getAdditionalCommerceByBuilding", &CyCity::getAdditionalCommerceByBuilding, "int (int /*CommerceTypes*/, int /*BuildingTypes*/) - rounded change of CommerceType from adding one BuildingType");
    x.def("getAdditionalCommerceTimes100ByBuilding", &CyCity::getAdditionalCommerceTimes100ByBuilding, "int (int /*CommerceTypes*/, int /*BuildingTypes*/) - total change of CommerceType from adding one BuildingType");
    x.def("getAdditionalBaseCommerceRateByBuilding", &CyCity::getAdditionalBaseCommerceRateByBuilding, "int (int /*CommerceTypes*/, int /*BuildingTypes*/) - base rate change of CommerceType from adding one BuildingType");
    x.def("getAdditionalCommerceRateModifierByBuilding", &CyCity::getAdditionalCommerceRateModifierByBuilding, "int (int /*CommerceTypes*/, int /*BuildingTypes*/) - rate modifier change of CommerceType from adding one BuildingType");
    x.def("getSpecialistCommerce", &CyCity::getSpecialistCommerce, "int (int /*CommerceTypes*/) - value of CommerceType adjustment from Specialists");
    x.def("changeSpecialistCommerce", &CyCity::changeSpecialistCommerce, "void (int /*CommerceTypes*/, iChange) - adjusts Specialist contribution to CommerceType by iChange");
    x.def("getReligionCommerce", &CyCity::getReligionCommerce, "int (int /*CommerceTypes*/) - effect on CommerceType by Religions");
    x.def("getReligionCommerceByReligion", &CyCity::getReligionCommerceByReligion, "int (int /*CommerceTypes*/, ReligionType) - CommerceType effect from ReligionType");
    x.def("getCorporationCommerce", &CyCity::getCorporationCommerce, "int (int /*CommerceTypes*/) - effect on CommerceType by Corporation");
    x.def("getCorporationCommerceByCorporation", &CyCity::getCorporationCommerceByCorporation, "int (int /*CommerceTypes*/, CorporationType) - CommerceType effect from CorporationType");
    x.def("getCorporationYield", &CyCity::getCorporationYield, "int (int /*CommerceTypes*/) - effect on YieldTypes by Corporation");
    x.def("getCorporationYieldByCorporation", &CyCity::getCorporationYieldByCorporation, "int (int /*YieldTypes*/, CorporationType) - YieldTypes effect from CorporationType");
    x.def("getCommerceRateModifier", &CyCity::getCommerceRateModifier, "int (int /*CommerceTypes*/) - indicates the total rate modifier on CommerceType");
    x.def("getCommerceHappinessPer", &CyCity::getCommerceHappinessPer, "int (int /*CommerceTypes*/) - happiness from each level of entertainment");
    x.def("getCommerceHappinessByType", &CyCity::getCommerceHappinessByType, "int (int /*CommerceTypes*/) - happiness from CommerceType");
    x.def("getCommerceHappiness", &CyCity::getCommerceHappiness, "int () - happiness from all CommerceTypes");
    x.def("getDomainFreeExperience", &CyCity::getDomainFreeExperience, "int (int /*DomainTypes*/)");
    x.def("getDomainProductionModifier", &CyCity::getDomainProductionModifier, "int (int /*DomainTypes*/)");
    x.def("getCulture", &CyCity::getCulture, "int /*PlayerTypes*/ ()");
    x.def("getCultureTimes100", &CyCity::getCultureTimes100, "int /*PlayerTypes*/ ()");
    x.def("countTotalCultureTimes100", &CyCity::countTotalCultureTimes100, "int ()");
    x.def("findHighestCulture", &CyCity::findHighestCulture, "PlayerTypes ()");
    x.def("calculateCulturePercent", &CyCity::calculateCulturePercent, "int (int eIndex)");
    x.def("calculateTeamCulturePercent", &CyCity::calculateTeamCulturePercent, "int /*TeamTypes*/ ()");
    x.def("setCulture", &CyCity::setCulture, "void (int PlayerTypes eIndex`, bool bPlots)");
    x.def("setCultureTimes100", &CyCity::setCultureTimes100, "void (int PlayerTypes eIndex, int iNewValue, bool bPlots)");
    x.def("changeCulture", &CyCity::changeCulture, "void (int PlayerTypes eIndex, int iChange, bool bPlots)");
    x.def("changeCultureTimes100", &CyCity::changeCultureTimes100, "void (int PlayerTypes eIndex, int iChange, bool bPlots)");
    x.def("isTradeRoute", &CyCity::isTradeRoute, "bool ()");
    x.def("isEverOwned", &CyCity::isEverOwned, "bool ()");
    x.def("isRevealed", &CyCity::isRevealed, "bool (int /*TeamTypes*/ eIndex, bool bDebug)");
    x.def("setRevealed", &CyCity::setRevealed, "void (int /*TeamTypes*/ eIndex, bool bNewValue)");
    x.def("getEspionageVisibility", &CyCity::getEspionageVisibility, "bool (int /*TeamTypes*/ eIndex)");
    x.def("getName", &CyCity::getName, "string () - city name");
    x.def("getNameForm", &CyCity::getNameForm, "string () - city name");
    x.def("getNameKey", &CyCity::getNameKey, "string () - city name");
    x.def("setName", &CyCity::setName, "void (TCHAR szNewValue, bool bFound) - sets the name to szNewValue");
    x.def("isNoBonus", &CyCity::isNoBonus, "bool (int eIndex)");
    x.def("changeNoBonusCount", &CyCity::changeNoBonusCount, "void (int eIndex, int iChange)");
    x.def("getFreeBonus", &CyCity::getFreeBonus, "int (int eIndex)");
    x.def("changeFreeBonus", &CyCity::changeFreeBonus, "void (int eIndex, int iChange)");
    x.def("getNumBonuses", &CyCity::getNumBonuses, "int (PlayerID)");
    x.def("hasBonus", &CyCity::hasBonus, "bool - (BonusID) - is BonusID connected to the city?");
    x.def("getBuildingProduction", &CyCity::getBuildingProduction, "int (BuildingID) - current production towards BuildingID");
    x.def("setBuildingProduction", &CyCity::setBuildingProduction, "void (BuildingID, iNewValue) - set progress towards BuildingID as iNewValue");
    x.def("changeBuildingProduction", &CyCity::changeBuildingProduction, "void (BuildingID, iChange) - adjusts progress towards BuildingID by iChange");
    x.def("getBuildingProductionTime", &CyCity::getBuildingProductionTime, "int (int eIndex)");
    x.def("setBuildingProductionTime", &CyCity::setBuildingProductionTime, "int (int eIndex, int iNewValue)");
    x.def("changeBuildingProductionTime", &CyCity::changeBuildingProductionTime, "int (int eIndex, int iChange)");
    x.def("isBuildingProductionDecay", &CyCity::isBuildingProductionDecay, "bool (int /*BuildingTypes*/ eIndex)");
    x.def("getBuildingProductionDecay", &CyCity::getBuildingProductionDecay, "int (int /*BuildingTypes*/ eIndex)");
    x.def("getBuildingProductionDecayTurns", &CyCity::getBuildingProductionDecayTurns, "int (int /*BuildingTypes*/ eIndex)");
    x.def("getBuildingOriginalOwner", &CyCity::getBuildingOriginalOwner, "int (BuildingType) - index of original building owner");
    x.def("getBuildingOriginalTime", &CyCity::getBuildingOriginalTime, "int (BuildingType) - original build date");
    x.def("getUnitProduction", &CyCity::getUnitProduction, "int (UnitID) - gets current production towards UnitID");
    x.def("setUnitProduction", &CyCity::setUnitProduction, "void (UnitID, iNewValue) - sets production towards UnitID as iNewValue");
    x.def("changeUnitProduction", &CyCity::changeUnitProduction, "void (UnitID, iChange) - adjusts production towards UnitID by iChange");
    x.def("getUnitProductionTime", &CyCity::getUnitProductionTime, "int (int /*UnitTypes*/ eIndex)");
    x.def("setUnitProductionTime", &CyCity::setUnitProductionTime, "int (int /*UnitTypes*/ eIndex, int iNewValue)");
    x.def("changeUnitProductionTime", &CyCity::changeUnitProductionTime, "int (int /*UnitTypes*/ eIndex, int iChange)");
    x.def("isUnitProductionDecay", &CyCity::isUnitProductionDecay, "bool (int /*UnitTypes*/ eIndex)");
    x.def("getUnitProductionDecay", &CyCity::getUnitProductionDecay, "int (int /*UnitTypes*/ eIndex)");
    x.def("getUnitProductionDecayTurns", &CyCity::getUnitProductionDecayTurns, "int (int /*UnitTypes*/ eIndex)");
    x.def("getProjectProduction", &CyCity::getProjectProduction, "int (int /*ProjectTypes*/ eIndex)");
    x.def("setProjectProduction", &CyCity::setProjectProduction, "void (int /*ProjectTypes*/ eIndex, int iNewValue)");
    x.def("changeProjectProduction", &CyCity::changeProjectProduction, "void (int /*ProjectTypes*/ eIndex, int iChange)");
    x.def("getGreatPeopleUnitRate", &CyCity::getGreatPeopleUnitRate, "int (int /*UnitTypes*/ iIndex)");
    x.def("getGreatPeopleUnitProgress", &CyCity::getGreatPeopleUnitProgress, "int (int /*UnitTypes*/ iIndex)");
    x.def("setGreatPeopleUnitProgress", &CyCity::setGreatPeopleUnitProgress, "int (int /*UnitTypes*/ iIndex, int iNewValue)");
    x.def("changeGreatPeopleUnitProgress", &CyCity::changeGreatPeopleUnitProgress, "int (int /*UnitTypes*/ iIndex, int iChange)");
    x.def("getSpecialistCount", &CyCity::getSpecialistCount, "int (int /*SpecialistTypes*/ eIndex)");
    x.def("alterSpecialistCount", &CyCity::alterSpecialistCount, "int (int /*SpecialistTypes*/ eIndex, int iChange)");
    x.def("getMaxSpecialistCount", &CyCity::getMaxSpecialistCount, "int (int /*SpecialistTypes*/ eIndex)");
}
