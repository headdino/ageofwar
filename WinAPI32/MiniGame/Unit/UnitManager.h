#pragma once
#include "GameNode.h"
#include "Unit.h"

#define UNITMAX 200

class Enemy;
class Shop;

//사거리 비교를 위한 놈
struct ST_TEMP
{
	FRECT rc;
	float posX;
	float range;
	bool isDead;
};

class UnitManager : public GameNode
{
private:
	//Unit* mUnit;
	//vector<Unit*> mvPUnit;
	//vector<Unit*> mvEUnit;
	//typedef vector<Unit*>::iterator mviUnit;

	Unit* maPUint;
	Unit* maEUint;

	ST_TEMP mPTemp[UNITMAX];
	ST_TEMP mETemp[UNITMAX];

	Enemy* m_enemy;
	Shop* m_shop;

public:
	UnitManager();
	~UnitManager() override;
	HRESULT init() override;
	void release() override;
	void update() override;
	void render() override;

	//유닛타입 넘겨주면 벡터에 추가시켜주는 함수
	void createUnit(UnitType type, bool player, bool isDead);

	void SetShop(Shop* shop) { m_shop = shop; }
	void SetEnemy(Enemy* emy) { m_enemy = emy; }
private:
	void checkInter();
	//공격 가능한지 체크해주는 함수
	void checkAtt();
	void checkErase();
	//벡터에 담긴 정보(위치,렉트,생존여부 등)을 배열로 옮겨주는 함수
	void refreshInfo();
};

