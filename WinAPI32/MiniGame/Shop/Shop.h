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
	//���� ���� �̳ѹ�
	slot m_slot;

	//���� ���θ޴� ����ü
	Shoplist* shoplist;
	//���� ���� ����Ʈ ����ü
	ShoplistUnit* ShopUnit;
	//���׷��̵� ���� ����Ʈ ����ü
	ShoplistUpgrade* ShopUpgrade;

	//���� ��� �׵θ�
	Image* ShopE;
	Image* goldE;

	//�ؼ�������ü
	Nexus* m_nexus;
	int NexusHp;
	bool m_Alive;

	//�浹 �ڽ��� rc
	FRECT m_rc;

	//��ǥ�� ����
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

