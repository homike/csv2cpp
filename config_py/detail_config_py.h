
#pragma once
#include "type.h"
#include "structs_py.h"
#include <map>
using namespace std;

class CHeroQualityUpTestTemplate 
{
public:
	CHeroQualityUpTestTemplate() {};
	~CHeroQualityUpTestTemplate(){};
	
	bool Load(const char* szFileName);
	void Clear() { m_mapHeroQualityUpTestTemplate.clear(); }
	
public:
	const SHeroQualityUpTest *FindHeroQualityUpTestTemplate(int	quality,int	hero_id) const;

	map<uint64, SHeroQualityUpTest> m_mapHeroQualityUpTestTemplate;
};
class CVipLevelTestTemplate 
{
public:
	CVipLevelTestTemplate() {};
	~CVipLevelTestTemplate(){};
	
	bool Load(const char* szFileName);
	void Clear() { m_mapVipLevelTestTemplate.clear(); }
	
public:
	const SVipLevelTest *FindVipLevelTestTemplate(int	vip_level) const;

	map<int, SVipLevelTest> m_mapVipLevelTestTemplate;
};
