
#pragma once
#include "structs_py.h"
#include "detail_config_py.h"

class CConfigPy
{
public:
	bool BaseLoad();

public:

	const CHeroQualityUpTestTemplate &GetHeroQualityUpTestConfig() const {
		return m_oHeroQualityUpTestConfig;	}
	const CVipLevelTestTemplate &GetVipLevelTestConfig() const {
		return m_oVipLevelTestConfig;	}
	//Merge1
//private:

	CHeroQualityUpTestTemplate m_oHeroQualityUpTestConfig;
	CVipLevelTestTemplate m_oVipLevelTestConfig;
	//Merge2
};
