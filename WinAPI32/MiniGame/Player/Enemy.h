#pragma once
#include "GameNode.h"
class UnitManager;

class Enemy : public GameNode
{
private:
	UnitManager* m_unitManager;

	Image* m_goal;
	int NexusHp;
	bool m_Alive;
	float m_Hp;
	D3DXVECTOR2 m_pos;
	D3DXVECTOR2 m_size;

	//충돌 박스용 rc
	FRECT m_rc;

private:
	bool m_aiOn;

	float m_spawnTime;

	bool m_isCow;
	bool m_isMage;
	bool m_isLooser;
	bool m_isCuteGirl;
	bool m_isStone;

	float m_cowTime = 0.0f;
	float m_mageTime = 0.0f;
	float m_looserTime = 0.0f;
	float m_cuteGirlTime = 0.0f;
	float m_stoneTime = 0.0f;

public:
	Enemy();
	~Enemy() override;
	HRESULT init() override;
	void release() override;
	void update() override;
	void render() override;

	void damagged(float damage);

	MAKEGETSET(FRECT, m_rc);
	MAKEGETSET(bool, m_Alive);


	void SetUnitManager(UnitManager* unitManager) { m_unitManager = unitManager; }

private:
	void spawn();

};

