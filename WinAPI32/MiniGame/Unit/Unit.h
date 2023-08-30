#pragma once
#include "GameNode.h"

enum UnitState
{
	US_STOP,
	US_MOVE,
	US_ATTACK,
	US_DIE
};

class Unit : public GameNode
{
private:
	Image* m_unit;
	bool m_isPlayer;

	D3DXVECTOR2 m_pos;
	D3DXVECTOR2 m_size;
	D3DXCOLOR m_col;
	UnitType m_type;
	UnitState m_state;
	float  m_range;
	float m_speed;
	float m_hp;
	float m_maxHp;
	float m_damage;

	bool m_isCollision;
	bool m_isInRange;
	bool m_isAttackFinish;
	bool m_isDead;
	bool m_isCollisionMouse;
	bool m_isAttackSound;
	bool m_isNotGive = false;
	//충돌 박스용 rc
	FRECT m_rc;


	float m_attackDelay;
	float m_attackTime;
	bool m_attackFrameStart;
	float m_dieAngle = 0.0f;
	float m_alpha = 1.0f;

//프레임관련된 
private:
	float m_frameTime;
	float m_frameTick;
	int m_frameX;
	int m_frameY;

public:
	Unit();
	~Unit() override;
	
	HRESULT init() override;
	HRESULT init(UnitType type, bool isPlayer, bool isDead);
	void release() override;
	void update() override;
	void render() override;
	void damagged(float damage);
	void stopMove(float x);
	void giveMoney();

	MAKEGETSET(UnitState, m_state);
	MAKEGETSET(FRECT, m_rc);
	MAKEGETSET(float, m_damage);
	MAKEGETSET(float, m_range);
	MAKEGETSET(bool, m_isInRange);
	MAKEGETSET(bool, m_isPlayer);
	MAKEGETSET(bool, m_isCollision);
	MAKEGETSET(bool, m_isAttackFinish);
	MAKEGETSET(bool, m_isDead);
	MAKEGETSET(bool, m_isCollisionMouse);

private:
	void switchType();
	void switchState();
	void frameMove();
	void changeState(UnitState state,string str, int frameY);
	void attack();

};

