#include "CvGameCoreDLL.h"
#include "CyCity.h"
#include "CyPlot.h"
#include "CyArea.h"
#include "CvInfos.h"

void CyCityPythonInterface1_Chunk6(python::class_<CyCity>& x)
{
    x.def("isSpecialistValid", &CyCity::isSpecialistValid, "bool (int /*SpecialistTypes*/ eIndex, int iExtra)");
    x.def("getForceSpecialistCount", &CyCity::getForceSpecialistCount, "int (int /*SpecialistTypes*/ eIndex)");
    x.def("isSpecialistForced", &CyCity::isSpecialistForced, "bool ()");
    x.def("setForceSpecialistCount", &CyCity::setForceSpecialistCount, "int (int /*SpecialistTypes*/ eIndex, int iNewValue");
    x.def("changeForceSpecialistCount", &CyCity::changeForceSpecialistCount, "int (int /*SpecialistTypes*/ eIndex, int iChange");
    x.def("getFreeSpecialistCount", &CyCity::getFreeSpecialistCount, "int (int /*SpecialistTypes*/ eIndex");
    x.def("setFreeSpecialistCount", &CyCity::setFreeSpecialistCount, "int (int /*SpecialistTypes*/ eIndex, iNewValue");
    x.def("changeFreeSpecialistCount", &CyCity::changeFreeSpecialistCount, "int (int /*SpecialistTypes*/ eIndex, iChange");
    x.def("getAddedFreeSpecialistCount", &CyCity::getAddedFreeSpecialistCount, "int (int /*SpecialistTypes*/ eIndex");
    x.def("getImprovementFreeSpecialists", &CyCity::getImprovementFreeSpecialists, "int (ImprovementID)");
    x.def("changeImprovementFreeSpecialists", &CyCity::changeImprovementFreeSpecialists, "void (ImprovementID, iChange) - adjust ImprovementID free specialists by iChange");
    x.def("getReligionInfluence", &CyCity::getReligionInfluence, "int (ReligionID) - value of influence from ReligionID");
    x.def("changeReligionInfluence", &CyCity::changeReligionInfluence, "void (ReligionID, iChange) - adjust ReligionID influence by iChange");
    x.def("getCurrentStateReligionHappiness", &CyCity::getCurrentStateReligionHappiness, "int ()");
    x.def("getStateReligionHappiness", &CyCity::getStateReligionHappiness, "int (int /*ReligionTypes*/ ReligionID)");
    x.def("changeStateReligionHappiness", &CyCity::changeStateReligionHappiness, "void (int /*ReligionTypes*/ ReligionID, iChange)");
    x.def("getUnitCombatFreeExperience", &CyCity::getUnitCombatFreeExperience, "int (int /*UnitCombatTypes*/ eIndex)");
    x.def("getFreePromotionCount", &CyCity::getFreePromotionCount, "int (int /*PromotionTypes*/ eIndex)");
    x.def("isFreePromotion", &CyCity::isFreePromotion, "bool (int /*PromotionTypes*/ eIndex)");
    x.def("getSpecialistFreeExperience", &CyCity::getSpecialistFreeExperience, "int ()");
    x.def("getEspionageDefenseModifier", &CyCity::getEspionageDefenseModifier, "int ()");
    x.def("isWorkingPlotByIndex", &CyCity::isWorkingPlotByIndex, "bool (iIndex) - true if a worker is working this city's plot iIndex");
    x.def("isWorkingPlot", &CyCity::isWorkingPlot, "bool (iIndex) - true if a worker is working this city's pPlot");
    x.def("alterWorkingPlot", &CyCity::alterWorkingPlot, "void (iIndex)");
    x.def("getNumRealBuilding", &CyCity::getNumRealBuilding, "int (BuildingID) - get # real building of this type");
    x.def("setNumRealBuilding", &CyCity::setNumRealBuilding, "(BuildingID, iNum) - Sets number of buildings in this city of BuildingID type");
    x.def("getNumFreeBuilding", &CyCity::getNumFreeBuilding, "int (BuildingID) - # of free Building ID (ie: from a Wonder)");
    x.def("isHasReligion", &CyCity::isHasReligion, "bool (ReligionID) - does city have ReligionID?");
    x.def("setHasReligion", &CyCity::setHasReligion, "void (ReligionID, bool bNewValue, bool bAnnounce, bool bArrows) - religion begins to spread");
    x.def("isHasCorporation", &CyCity::isHasCorporation, "bool (CorporationID) - does city have CorporationID?");
    x.def("setHasCorporation", &CyCity::setHasCorporation, "void (CorporationID, bool bNewValue, bool bAnnounce, bool bArrows) - corporation begins to spread");
    x.def("isActiveCorporation", &CyCity::isActiveCorporation, "bool (CorporationID) - does city have active CorporationID?");
    x.def("getTradeCity", &CyCity::getTradeCity, python::return_value_policy<python::manage_new_object>(), "CyCity (int iIndex) - remove SpecialistType[iIndex]");
    x.def("getTradeRoutes", &CyCity::getTradeRoutes, "int ()");
    x.def("clearOrderQueue", &CyCity::clearOrderQueue, "void ()");
    x.def("pushOrder", &CyCity::pushOrder, "void (OrderTypes eOrder, int iData1, int iData2, bool bSave, bool bPop, bool bAppend, bool bForce)");
    x.def("popOrder", &CyCity::popOrder, "int (int iNum, bool bFinish, bool bChoose)");
    x.def("getOrderQueueLength", &CyCity::getOrderQueueLength, "void ()");
    x.def("getOrderFromQueue", &CyCity::getOrderFromQueue, python::return_value_policy<python::manage_new_object>(), "OrderData* (int iIndex)");
    x.def("setWallOverridePoints", &CyCity::setWallOverridePoints, "setWallOverridePoints(const python::tuple& kPoints)");
    x.def("getWallOverridePoints", &CyCity::getWallOverridePoints, "python::tuple getWallOverridePoints()");
    x.def("AI_avoidGrowth", &CyCity::AI_avoidGrowth, "bool ()");
    x.def("AI_isEmphasize", &CyCity::AI_isEmphasize, "bool (int iEmphasizeType)");
    x.def("AI_countBestBuilds", &CyCity::AI_countBestBuilds, "int (CyArea* pArea)");
    x.def("AI_cityValue", &CyCity::AI_cityValue, "int ()");
    x.def("getScriptData", &CyCity::getScriptData, "str () - Get stored custom data (via pickle)");
    x.def("setScriptData", &CyCity::setScriptData, "void (str) - Set stored custom data (via pickle)");
    x.def("visiblePopulation", &CyCity::visiblePopulation, "int ()");
    x.def("getBuildingYieldChange", &CyCity::getBuildingYieldChange, "int (int /*BuildingClassTypes*/ eBuildingClass, int /*YieldTypes*/ eYield)");
    x.def("setBuildingYieldChange", &CyCity::setBuildingYieldChange, "void (int /*BuildingClassTypes*/ eBuildingClass, int /*YieldTypes*/ eYield, int iChange)");
    x.def("getBuildingCommerceChange", &CyCity::getBuildingCommerceChange, "int (int /*BuildingClassTypes*/ eBuildingClass, int /*CommerceTypes*/ eCommerce)");
    x.def("setBuildingCommerceChange", &CyCity::setBuildingCommerceChange, "void (int /*BuildingClassTypes*/ eBuildingClass, int /*CommerceTypes*/ eCommerce, int iChange)");
    x.def("getBuildingHappyChange", &CyCity::getBuildingHappyChange, "int (int /*BuildingClassTypes*/ eBuildingClass)");
    x.def("setBuildingHappyChange", &CyCity::setBuildingHappyChange, "void (int /*BuildingClassTypes*/ eBuildingClass, int iChange)");
    x.def("getBuildingHealthChange", &CyCity::getBuildingHealthChange, "int (int /*BuildingClassTypes*/ eBuildingClass)");
    x.def("setBuildingHealthChange", &CyCity::setBuildingHealthChange, "void (int /*BuildingClassTypes*/ eBuildingClass, int iChange)");
    x.def("getLiberationPlayer", &CyCity::getLiberationPlayer, "int ()");
    x.def("liberate", &CyCity::liberate, "void ()");
}
