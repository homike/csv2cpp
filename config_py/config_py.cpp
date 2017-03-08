
#include "stdafx.h"
#include "config_py.h"
#include "markupstl.h"
#include "stdlib.h"
#include "utility.h"

bool CConfigPy::BaseLoad()
{
	char szFileExePath[MAX_PATH] = {0};
	const char *pszExePath = GNDP::GetExePath();
	

	snprintf(szFileExePath, sizeof(szFileExePath) - 1, "%s/%s", pszExePath, "../../config/hero_quality_up_test.csv");
	if (!m_oHeroQualityUpTestConfig.Load(szFileExePath)){
		USR_CRITICALEX(true, "load %s error", szFileExePath);
		return false;
	}



	snprintf(szFileExePath, sizeof(szFileExePath) - 1, "%s/%s", pszExePath, "../../config/vip_level_test.csv");
	if (!m_oVipLevelTestConfig.Load(szFileExePath)){
		USR_CRITICALEX(true, "load %s error", szFileExePath);
		return false;
	}


	//Merge3
	return true;
}
