#include "stdafx.h"
#include "Unit.h"


Unit::Unit()
{
}


Unit::~Unit()
{
	cout << "유닛이 소멸된다!!" << endl;
	m_unit = nullptr;
}

void Unit::switchType()
{
	switch (m_type)
	{
	case cow:
		
		if (m_isPlayer)
		{
			m_unit = IMGMANAGER->GetImage("Pcow_move");
			m_frameY = 2;
		}
		else
		{
			m_unit = IMGMANAGER->GetImage("Ecow_move");
			m_frameY = 1;
		}
		m_unit->GetRefCurrentFrameY() = m_frameY;
		m_speed = 60.0f;
		m_hp = 100.0f;
		m_maxHp = 100.0f;
		m_attackDelay = 1.2f;
		m_damage = 30.0f;
		m_range = 100.0f;
		m_frameTick = 0.45f;
		m_size = D3DXVECTOR2(100.0f, 100.0f);
		m_rc = RectMakeCenter(m_pos.x, m_pos.y, m_size.x, m_size.y);
		break;
	case mage:
		if (m_isPlayer)
		{
			m_unit = IMGMANAGER->GetImage("Pmage_move");
			m_frameY = 2;
		}
		else
		{
			m_unit = IMGMANAGER->GetImage("Emage_move");
			m_frameY = 1;
		}
		m_unit->GetRefCurrentFrameY() = m_frameY;
		m_speed = 80.0f;
		m_hp = 70.0f;
		m_maxHp = 70.0f;
		m_attackDelay = 2.1f;
		m_damage = 35.0f;
		m_range = 200.0f;
		m_frameTick = 0.35f;
		m_size = D3DXVECTOR2(70.0f, 100.0f);
		m_rc = RectMakeCenter(m_pos.x, m_pos.y, m_size.x, m_size.y);
		break;
	case stone:
		if (m_isPlayer)
		{
			m_unit = IMGMANAGER->GetImage("Pstone_move");
			m_frameY = 2;
			m_pos = D3DXVECTOR2(100.0f, 150.0f);
		}
		else
		{
			m_unit = IMGMANAGER->GetImage("Estone_move");
			m_frameY = 1;
			m_pos = D3DXVECTOR2(1500.0f, 150.0f);
		}
		m_unit->GetRefCurrentFrameY() = m_frameY;
		m_speed = 30.0f;
		m_hp = 600.0f;
		m_maxHp = 600.0f;
		m_attackDelay = 4.0f;
		m_damage = 250.0f;
		m_range = 200.0f;
		m_frameTick = 1.85f;
		m_size = D3DXVECTOR2(200.0f, 200.0f);
		m_rc = RectMakeCenter(m_pos.x, m_pos.y, m_size.x, m_size.y);
		break;
	case looser:
		if (m_isPlayer)
		{
			m_unit = IMGMANAGER->GetImage("Plooser_move");
			m_frameY = 2;
		}
		else
		{
			m_unit = IMGMANAGER->GetImage("Elooser_move");
			m_frameY = 1;
		}
		m_unit->GetRefCurrentFrameY() = m_frameY;
		m_speed = 60.0f;
		m_hp = 300.0f;
		m_maxHp = 300.0f;
		m_attackDelay = 0.4f;
		m_damage = 25.0f;
		m_range = 100.0f;
		m_frameTick = 0.2f;
		m_size = D3DXVECTOR2(100.0f, 100.0f);
		m_rc = RectMakeCenter(m_pos.x, m_pos.y, m_size.x, m_size.y);
		break;
	case cuteGirl:
		if (m_isPlayer)
		{
			m_unit = IMGMANAGER->GetImage("PcuteGirl_move");
			m_frameY = 2;
		}
		else
		{
			m_unit = IMGMANAGER->GetImage("EcuteGirl_move");
			m_frameY = 1;
		}
		m_unit->GetRefCurrentFrameY() = m_frameY;
		m_speed = 120.0f;
		m_hp = 150.0f;
		m_maxHp = 150.0f;
		m_attackDelay = 0.25f;
		m_damage = 70.0f;
		m_range = 100.0f;
		m_frameTick = 0.15f;
		m_size = D3DXVECTOR2(70.0f, 100.0f);
		m_rc = RectMakeCenter(m_pos.x, m_pos.y, m_size.x, m_size.y);
		break;
	}
}



HRESULT Unit::init()
{



	return S_OK;
}

HRESULT Unit::init(UnitType type, bool isPlayer, bool isDead)
{

	m_type = type;

	m_isPlayer = isPlayer;

	if (m_isPlayer)
	{
		m_pos = D3DXVECTOR2(100.0f, 120.0f);
	}
	else
	{
		m_pos = D3DXVECTOR2(1500.0f, 120.0f);
	}
	m_col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_state = US_MOVE;

	m_frameTime = 0.0f;
	m_attackTime = 0.0f;
	m_attackFrameStart = true;
	m_frameX = 0;
	m_isCollision = false;
	m_isInRange = false;
	m_isAttackFinish = false;
	m_isCollisionMouse = false;
	m_isAttackSound = true;
	m_isNotGive = false;
	m_isDead = isDead;
	m_alpha = 1.0f;
	m_dieAngle = 0.0f;

	switchType();

	//죽은 상태로 초기화면
	//즉 처음 초기화할때면
	if (isDead)
	{
		m_pos = D3DXVECTOR2(-500.0f, 120.0f);
		m_rc = RectMakeCenter(m_pos.x, m_pos.y, m_size.x, m_size.y);
		m_rc.left = -500.0f;
	}


	return S_OK;
}

void Unit::release()
{
}

void Unit::update()
{
	switchState();
	frameMove();

	//cout << m_hp << endl;
	//cout << m_isCollision << endl;

	if (m_state != US_DIE) m_alpha = 1.0f;

	m_rc = RectMakeCenter(m_pos.x, m_pos.y, m_size.x, m_size.y);

}

void Unit::render()
{

	m_unit->Position(m_pos);
	m_unit->Color(0.0f, 0.0f, 0.0f, m_alpha);
	m_unit->GetRefCurrentFrameX() = m_frameX;
	m_unit->Render();

	if (m_isCollisionMouse)
	{
		IMGMANAGER->GetImage("hpBarBottom")->Position(m_pos.x + (m_maxHp / 4 - 50.0f), m_pos.y + 100.0f);
		IMGMANAGER->GetImage("hpBarBottom")->Scale(m_maxHp / 2.0f, 10);
		IMGMANAGER->GetImage("hpBarBottom")->Render();
		IMGMANAGER->GetImage("hpBarTop")->Position(m_pos.x + (m_hp / 4 - 50.0f), m_pos.y + 100.0f);
		IMGMANAGER->GetImage("hpBarTop")->Scale(m_hp / 2.0f, 10);
		IMGMANAGER->GetImage("hpBarTop")->Render();
	}

	if (m_state == US_DIE && !m_isPlayer)
	{
		Image* image;
		switch (m_type)
		{
		case cow:
			image = IMGMANAGER->GetImage("미노2");
			image->Position(150.0f + g_ptCam.x, 540.0f);
			image->Scale(40.0f, 40.0f);
			image->Render();
			break;
		case mage:
			image = IMGMANAGER->GetImage("드라이어드2");
			image->Position(150.0f + g_ptCam.x, 540.0f);
			image->Scale(40.0f, 40.0f);
			image->Render();
			break;
		case stone:
			image = IMGMANAGER->GetImage("힐 자이언트2");
			image->Position(150.0f + g_ptCam.x, 540.0f);
			image->Scale(40.0f, 40.0f);
			image->Render();
			break;
		case looser:
			image = IMGMANAGER->GetImage("챔피언2");
			image->Position(150.0f + g_ptCam.x, 540.0f);
			image->Scale(40.0f, 40.0f);
			image->Render();
			break;
		case cuteGirl:
			image = IMGMANAGER->GetImage("암살자2");
			image->Position(150.0f + g_ptCam.x, 540.0f);
			image->Scale(40.0f, 40.0f);
			image->Render();
			break;
		case ENDUNITTYPE:
			break;
		default:
			break;
		}

	}


	//m_unit->PlayAnimation(ANI_LOOP, true, 0.35f);
}

void Unit::switchState()
{
	switch (m_state)
	{
	case US_STOP:
		if (!m_isCollision)
		{
			switch (m_type)
			{
			case cow:
				if (m_isPlayer)changeState(US_MOVE, "Pcow_move", 2);
				else changeState(US_MOVE, "Ecow_move", 1);
				break;
			case mage:
				if (m_isPlayer)changeState(US_MOVE, "Pmage_move", 2);
				else changeState(US_MOVE, "Emage_move", 1);
				break;
			case stone:
				if (m_isPlayer)changeState(US_MOVE, "Pstone_move", 2);
				else changeState(US_MOVE, "Estone_move", 1);
				break;
			case looser:
				if (m_isPlayer)changeState(US_MOVE, "Plooser_move", 2);
				else changeState(US_MOVE, "Elooser_move", 1);
				break;
			case cuteGirl:
				if (m_isPlayer)changeState(US_MOVE, "PcuteGirl_move", 2);
				else changeState(US_MOVE, "EcuteGirl_move", 1);
				break;
			default:
				break;
			}
			
		}
		else if (m_isInRange)
		{
			switch (m_type)
			{
			case cow:
				if (m_isPlayer)changeState(US_ATTACK, "Pcow_attack", 2);
				else changeState(US_ATTACK, "Ecow_attack", 1);
				break;
			case mage:
				if (m_isPlayer)changeState(US_ATTACK, "Pmage_attack", 2);
				else changeState(US_ATTACK, "Emage_attack", 1);
				break;
			case stone:
				if (m_isPlayer)changeState(US_ATTACK, "Pstone_attack", 1);
				else changeState(US_ATTACK, "Estone_attack", 0);
				break;
			case looser:
				if (m_isPlayer)changeState(US_ATTACK, "Plooser_attack", 1);
				else changeState(US_ATTACK, "Elooser_attack", 0);
				break;
			case cuteGirl:
				if (m_isPlayer)changeState(US_ATTACK, "PcuteGirl_attack", 2);
				else changeState(US_ATTACK, "EcuteGirl_attack", 1);
				break;
			default:
				break;
			}
		
		}
		break;
	case US_MOVE:
		if (m_isPlayer)
		{
			//테스트용
			//if (m_pos.x >= 500) break;
			m_pos.x += m_speed * g_ETime;
		}
		else
		{
			//if (m_pos.x <= 1200) break;
			m_pos.x -= m_speed * g_ETime;
		}
		
		if (m_isCollision)
		{
			switch (m_type)
			{
			case cow:
				if (m_isPlayer)changeState(US_STOP, "Pcow_stop", 2);
				else changeState(US_STOP, "Ecow_stop", 1);
				break;
			case mage:
				if (m_isPlayer)changeState(US_STOP, "Pmage_stop", 2);
				else changeState(US_STOP, "Emage_stop", 1);
				break;
			case stone:
				if (m_isPlayer)changeState(US_STOP, "Pstone_stop", 2);
				else changeState(US_STOP, "Estone_stop", 1);
				break;
			case looser:
				if (m_isPlayer)changeState(US_STOP, "Plooser_stop", 2);
				else changeState(US_STOP, "Elooser_stop", 1);
				break;
			case cuteGirl:
				if (m_isPlayer)changeState(US_STOP, "PcuteGirl_stop", 2);
				else changeState(US_STOP, "EcuteGirl_stop", 1);
				break;
			default:
				break;
			}
			
		}
		if (m_isInRange)
		{
			switch (m_type)
			{
			case cow:
				if (m_isPlayer)changeState(US_ATTACK, "Pcow_attack", 2);
				else changeState(US_ATTACK, "Ecow_attack", 1);
				break;
			case mage:
				if (m_isPlayer)changeState(US_ATTACK, "Pmage_attack", 2);
				else changeState(US_ATTACK, "Emage_attack", 1);
				break;
			case stone:
				if (m_isPlayer)changeState(US_ATTACK, "Pstone_attack", 1);
				else changeState(US_ATTACK, "Estone_attack", 0);
				break;
			case looser:
				if (m_isPlayer)changeState(US_ATTACK, "Plooser_attack", 1);
				else changeState(US_ATTACK, "Elooser_attack", 0);
				break;
			case cuteGirl:
				if (m_isPlayer)changeState(US_ATTACK, "PcuteGirl_attack", 2);
				else changeState(US_ATTACK, "EcuteGirl_attack", 1);
				break;
			default:
				break;
			}
			
			
		}
		break;
	case US_ATTACK:
		attack();

		if (!m_isInRange)
		{
			m_attackFrameStart = true;
			switch (m_type)
			{
			case cow:
				if (m_isPlayer)changeState(US_STOP, "Pcow_stop", 2);
				else changeState(US_STOP, "Ecow_stop", 1);
				break;
			case mage:
				if (m_isPlayer)changeState(US_STOP, "Pmage_stop", 2);
				else changeState(US_STOP, "Emage_stop", 1);
				break;
			case stone:
				if (m_isPlayer)changeState(US_STOP, "Pstone_stop", 2);
				else changeState(US_STOP, "Estone_stop", 1);
				break;
			case looser:
				if (m_isPlayer)changeState(US_STOP, "Plooser_stop", 2);
				else changeState(US_STOP, "Elooser_stop", 1);
				break;
			case cuteGirl:
				if (m_isPlayer)changeState(US_STOP, "PcuteGirl_stop", 2);
				else changeState(US_STOP, "EcuteGirl_stop", 1);
				break;
			default:
				break;
			}
		}
		break;
	case US_DIE:
		if (!m_isNotGive && !m_isPlayer)
		{
			giveMoney();
			m_isNotGive = true;
		}
		m_unit->Rotate(0.0f, 0.0f, m_dieAngle);

		if (m_dieAngle <= PI + PI / 2.0f)
		{
			m_dieAngle += 5.0f * g_ETime;
		}
		else if (m_alpha >= 0.2f)
		{
			m_alpha -= 1.0f * g_ETime;
		}
		else
		{
			m_isDead = true;
		}
		

		break;
	}

}

void Unit::frameMove()
{
	if (m_frameTime >= m_frameTick && m_attackFrameStart)
	{
		m_frameTime = 0.0f;
		m_frameX++;
		if (m_frameX >= static_cast<int>(m_unit->GetRefmaxFrameX()))
		{
			m_frameX = 0;
		}
	}
	else
	{
		m_frameTime += g_ETime;
	}


}

void Unit::changeState(UnitState state, string str, int frameY)
{
	m_state = state;
	m_unit = IMGMANAGER->GetImage(str);
	m_unit->GetRefCurrentFrameY() = frameY;
	m_unit->GetRefCurrentFrameX() = 0;
	m_frameX = 0;
}

void Unit::attack()
{
	if (!m_attackFrameStart)
	{
		if (m_attackTime >= m_attackDelay)
		{
			m_attackTime = 0.0f;
			m_attackFrameStart = true;
		}
		else
		{
			m_attackTime += g_ETime;
		}
	}

	if (m_attackFrameStart && m_isAttackSound)
	{
		switch (m_type)
		{
		case cow:
		case mage:
		case stone:
		case looser:
			SOUNDMANAGER->play("normalAtt", 0.5f);
			m_isAttackSound = false;
			break;
		case cuteGirl:
			SOUNDMANAGER->play("knifAtt", 0.5f);
			m_isAttackSound = false;
			break;
		}
	}
	


	//공격 모션이 끝나면
	if(m_frameX >= static_cast<int>(m_unit->GetRefmaxFrameX() - 1))
	{
		m_isAttackFinish = true;
		m_attackFrameStart = false;
		m_isAttackSound = true;
		m_frameX = 0;
		
	}


}

void Unit::stopMove(float x)
{
	m_isCollision = true;

	if (m_isPlayer)
	{
		m_pos.x = x - (m_size.x / 2.0f) - 5.0f;
	}
	else
	{
		m_pos.x = x + (m_size.x / 2.0f) + 5.0f;
	}
	
}

void Unit::giveMoney()
{
	switch (m_type)
	{
	case cow:
		g_gold += 100;
		break;
	case mage:
		g_gold += 200;
		break;
	case stone:
		g_gold += 500;
		break;
	case looser:
		g_gold += 300;
		break;
	case cuteGirl:
		g_gold += 400;
		break;
	case ENDUNITTYPE:
		break;
	default:
		break;
	}
}

void Unit::damagged(float damage)
{
	if (m_type == stone)
	{
		m_hp -= damage - 25.0f;
	}
	else
	{
		m_hp -= damage;
	}

	if (m_hp <= 0)
	{
		m_hp = 0;
		switch (m_type)
		{
		case cow:
			if (m_isPlayer)changeState(US_DIE, "Pcow_die", 2);
			else changeState(US_DIE, "Ecow_die", 1);
			break;
		case mage:
			if (m_isPlayer)changeState(US_DIE, "Pmage_die", 2);
			else changeState(US_DIE, "Emage_die", 1);
			break;
		case stone:
			if (m_isPlayer)changeState(US_DIE, "Pstone_die", 2);
			else changeState(US_DIE, "Estone_die", 1);
			break;
		case looser:
			if (m_isPlayer)changeState(US_DIE, "Plooser_die", 2);
			else changeState(US_DIE, "Elooser_die", 1);
			break;
		case cuteGirl:
			if (m_isPlayer)changeState(US_DIE, "PcuteGirl_die", 2);
			else changeState(US_DIE, "EcuteGirl_die", 1);
			break;
		default:
			break;
		}
	}
}
