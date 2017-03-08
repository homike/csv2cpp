
#include "detail_config_py.h"
#include "markupstl.h"
#include "utility.h"
#include "utf.h"
#include "csv.h"
#include "stream_string.h"
#include "tinyxml/tinyxml.h"

#if defined(WIN32) || defined(WIN64)
#else
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <assert.h>
#endif
bool CHeroQualityUpTestTemplate::Load(const char* szFileName)
{
	CCSVParser oParser;
	if (!oParser.Load(szFileName))
	{
		return false;
	}
	for (int i = 3; i < oParser.GetLineCount(); ++i) {
		SHeroQualityUpTest stHeroQualityUpTest;
		int nColumn = 1;
		int hero_id = atoi(oParser.GetField(i, nColumn++).c_str());
		int quality = atoi(oParser.GetField(i, nColumn++).c_str());
		stHeroQualityUpTest.hero_id = hero_id;
		stHeroQualityUpTest.quality = quality;
		uint64 llKey = GNDP::GetUint64(quality,hero_id);

		nColumn++;
		for (size_t j = 0; j < MyArraySize(stHeroQualityUpTest.arrSTestInfo); j++)
		{
			nColumn++;
			stHeroQualityUpTest.arrSTestInfo[j].count = atoi(oParser.GetField(i, nColumn++).c_str());
			stHeroQualityUpTest.arrSTestInfo[j].id = atoi(oParser.GetField(i, nColumn++).c_str());
		}

		stHeroQualityUpTest.gold = atoi(oParser.GetField(i, nColumn++).c_str());
		stHeroQualityUpTest.maxHP = atoi(oParser.GetField(i, nColumn++).c_str());
		stHeroQualityUpTest.attack = (float)atof(oParser.GetField(i, nColumn++).c_str());
		stHeroQualityUpTest.defense = (float)atof(oParser.GetField(i, nColumn++).c_str());
		m_mapHeroQualityUpTestTemplate[llKey] = stHeroQualityUpTest;
	}
	return true;
}
const SHeroQualityUpTest *CHeroQualityUpTestTemplate::FindHeroQualityUpTestTemplate(int	quality,int	hero_id) const
{
	uint64 llKey = GNDP::GetUint64(quality,hero_id);

	map<uint64, SHeroQualityUpTest>::const_iterator it = m_mapHeroQualityUpTestTemplate.find(llKey);
	if (it != m_mapHeroQualityUpTestTemplate.end())
	{
		return &it->second;
	}
	return NULL;
}
bool CVipLevelTestTemplate::Load(const char* szFileName)
{
	CCSVParser oParser;
	if (!oParser.Load(szFileName))
	{
		return false;
	}
	for (int i = 3; i < oParser.GetLineCount(); ++i) {
		SVipLevelTest stVipLevelTest;
		int nColumn = 1;
		int vip_level = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.vip_level = vip_level;
		int llKey = vip_level;

		stVipLevelTest.vip_exp = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.sweeper = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.purchase_energy_count = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.purchase_midas_count = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.reset_elite_count = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.reset_arena_count = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.reset_expedition_count = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.signpatch = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.unlock_function = oParser.GetField(i, nColumn++).c_str();
		stVipLevelTest.unlock_fuction_att = oParser.GetField(i, nColumn++).c_str();
		stVipLevelTest.skillpoint_restore_time = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.midas_crit_rate = (float)atof(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.add_arena_count = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.arena_cd = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.item5 = oParser.GetField(i, nColumn++).c_str();
		stVipLevelTest.item6 = oParser.GetField(i, nColumn++).c_str();
		stVipLevelTest.equivalent_value = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.purchase_huoli_count = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.purchase_cristal_count = atoi(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.cristal_crit_rate = (float)atof(oParser.GetField(i, nColumn++).c_str());
		stVipLevelTest.reset_dungeon_count = atoi(oParser.GetField(i, nColumn++).c_str());
		m_mapVipLevelTestTemplate[llKey] = stVipLevelTest;
	}
	return true;
}
const SVipLevelTest *CVipLevelTestTemplate::FindVipLevelTestTemplate(int	vip_level) const
{
	int llKey = vip_level;

	map<int, SVipLevelTest>::const_iterator it = m_mapVipLevelTestTemplate.find(llKey);
	if (it != m_mapVipLevelTestTemplate.end())
	{
		return &it->second;
	}
	return NULL;
}
