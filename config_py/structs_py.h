
#pragma once
#include <string>
#include <set>
#include "type.h"
using namespace std;

struct STestInfo {
	int count;
	int id;
};
struct	SHeroQualityUpTest
{
	//索引ID
	int		id;
	//英雄ID
	int		hero_id;
	//英雄品质
	int		quality;
	//符文
	STestInfo		arrSTestInfo[2];
	//升阶金钱
	int		gold;
	//生命值
	int		maxHP;
	//攻击
	float		attack;
	//防御
	float		defense;
};
struct	SVipLevelTest
{
	//索引ID
	int		id;
	//VIP等级
	int		vip_level;
	//VIP升级所需经验
	int		vip_exp;
	//扫荡券
	int		sweeper;
	//可购买体力次数
	int		purchase_energy_count;
	//可使用点金手次数
	int		purchase_midas_count;
	//可重置精英关卡的次数
	int		reset_elite_count;
	//可重置竞技场挑战的次数
	int		reset_arena_count;
	//远征的次数
	int		reset_expedition_count;
	//VIP月签到可补签次数
	int		signpatch;
	//特殊功能解锁（0无;1开启单次扫荡;2开启多次扫荡;3开启购买技能点数;4技能点上限增加至20点;5解锁重置竞技场CD（废弃）;6远征次数增加至2次（废弃）;7商店类型2永久开放;8商店类型3永久开放;9月签到可补签次数增加（废弃））
	string		unlock_function;
	//特殊功能参数
	string		unlock_fuction_att;
	//技能点恢复时间(填写的秒数）
	int		skillpoint_restore_time;
	//点金手暴击概率
	float		midas_crit_rate;
	//竞技场购买次数
	int		add_arena_count;
	//竞技场挑战CD
	int		arena_cd;
	//奖励道具5
	string		item5;
	//奖励道具6
	string		item6;
	//等价价值
	int		equivalent_value;
	//可购买活力次数
	int		purchase_huoli_count;
	//可使用水晶次数
	int		purchase_cristal_count;
	//水晶暴击概率
	float		cristal_crit_rate;
	//可购买组队副本的次数
	int		reset_dungeon_count;
};
