#pragma once
#include "GameNode.h"
#include "Unit.h"

#define UNITMAX 200

class Enemy;
class Shop;

//��Ÿ� �񱳸� ���� ��
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

	//����Ÿ�� �Ѱ��ָ� ���Ϳ� �߰������ִ� �Լ�
	void createUnit(UnitType type, bool player, bool isDead);

	void SetShop(Shop* shop) { m_shop = shop; }
	void SetEnemy(Enemy* emy) { m_enemy = emy; }
private:
	void checkInter();
	//���� �������� üũ���ִ� �Լ�
	void checkAtt();
	void checkErase();
	//���Ϳ� ��� ����(��ġ,��Ʈ,�������� ��)�� �迭�� �Ű��ִ� �Լ�
	void refreshInfo();
};

