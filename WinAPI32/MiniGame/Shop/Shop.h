#pragma once
#include "GameNode.h"
class UnitManager;

enum slot
{
	emain,
	eUnit,
	eTower,
	eUpgrade,
};


struct Shoplist
{
	FRECT index;
	bool shopping;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
};

struct ShoplistUnit
{
	FRECT index;
	bool buy;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
	float time;
	int price;
	UnitType unitType;
};

struct ShoplistUpgrade
{
	FRECT index;
	bool buy;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
};

struct Nexus
{
	FRECT index;
	int level;
	float Hp;
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
};

class Shop : public GameNode
{
private:
	//상점 상태 이넘문
	slot m_slot;

	//상점 메인메뉴 구조체
	Shoplist* shoplist;
	//유닛 상점 리스트 구조체
	ShoplistUnit* ShopUnit;
	//업그레이드 상점 리스트 구조체
	ShoplistUpgrade* ShopUpgrade;

	//상점 골드 테두리
	Image* ShopE;
	Image* goldE;

	//넥서스구조체
	Nexus* m_nexus;
	int NexusHp;
	bool m_Alive;

	//충돌 박스용 rc
	FRECT m_rc;

	//돈표시 변수
	int	  getgold;
	int one, ten, hundred, thousand;
	float g_time;

	UnitManager* m_unitManager;
public:
	Shop();
	~Shop() override;
	HRESULT init() override;
	void release() override;
	void update() override;
	void render() override;

	void buyUnit(ShoplistUnit shopUnit);

	void damagged(float damage);

	MAKEGETSET(FRECT, m_rc);
	MAKEGETSET(bool, m_Alive);
	void SetUnitManager(UnitManager* unitManager) { m_unitManager = unitManager; }
};

