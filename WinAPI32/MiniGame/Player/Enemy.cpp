#include "stdafx.h"
#include "Enemy.h"
#include "MiniGame/Unit/UnitManager.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
	m_unitManager = nullptr;
	m_goal = nullptr;
}

HRESULT Enemy::init()
{

	m_Alive = true;
	m_Hp = 600.0f;
	m_pos = D3DXVECTOR2(1550.0f,120.0f);
	m_size = D3DXVECTOR2(120.0f, 150.0f);




	m_goal = IMGMANAGER->GetImage("적기지");
	m_goal->Position(m_pos);
	m_goal->Scale(m_size);

	m_rc = RectMakeCenter(m_pos.x, m_pos.y, m_size.x, m_size.y);

	m_aiOn = true;

	m_isCow = false;
	m_isMage = false;
	m_isLooser = false;
	m_isCuteGirl = false;
	m_isStone = false;

	return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{
	if (KEYMANAGER->isKeyDown('Q'))
	{
		m_unitManager->createUnit(cow, false, false);
	}

	if (KEYMANAGER->isKeyDown('W'))
	{
		m_unitManager->createUnit(mage, false, false);
	}

	if (KEYMANAGER->isKeyDown('E'))
	{
		m_unitManager->createUnit(looser, false, false);
	}

	if (KEYMANAGER->isKeyDown('R'))
	{
		m_unitManager->createUnit(cuteGirl, false, false);
	}

	if (KEYMANAGER->isKeyDown('T'))
	{
		m_unitManager->createUnit(stone, false, false);
	}


	if (KEYMANAGER->isKeyDown('6'))
	{
		if (m_aiOn) m_aiOn = false;
		else m_aiOn = true;
	}

	if (m_aiOn)spawn();




	NexusHp = (int)m_Hp;


}

void Enemy::render()
{
	m_goal->Render();


	wchar_t str[256];
	swprintf_s(str, L"HP: %d", NexusHp);

	if (m_Hp > 0.0f)
	{

		Rect* Hpbar = IMGMANAGER->Getrect();
		IMGMANAGER->Getrect()->SetisFill(true);
		IMGMANAGER->Getrect()->Position(1550.0f, 300.0f + (m_Hp / 4 - 100.0f));
		IMGMANAGER->Getrect()->Scale(50.0f, m_Hp / 2);
		IMGMANAGER->Getrect()->Color(1.0f, 0.0f, 0.0f);
		IMGMANAGER->RectRender();

		RECT rect = { 1500 - g_ptCam.x, 190, 1600 - g_ptCam.x, 210 };
		WRITEMANAGER->RenderText(str, rect, 20, L"돋움체", D3DXCOLOR(0, 0, 0, 1));
	}


}

void Enemy::damagged(float damage)
{
	m_Hp -= damage / 2.0f;
	if (m_Hp <= 0)
	{
		m_Alive = false;
	}
}

void Enemy::spawn()
{


	m_spawnTime += g_ETime;
	

	if (m_spawnTime >= 2.0f)
	{
		m_isCow = true;
	}
	if (m_spawnTime >= 20.0f)
	{
		m_isMage = true;
	}
	if (m_spawnTime >= 40.0f)
	{
		m_isLooser = true;
	}
	if (m_spawnTime >= 120.0f)
	{
		m_isCuteGirl = true;
	}
	if (m_spawnTime >= 150.0f)
	{
		m_isStone = true;
	}

	if (m_isCow && !m_isMage)
	{
		if (m_cowTime >= 2.2f * 3.0f)
		{
			m_cowTime = 0.0f;
			m_unitManager->createUnit(cow, false, false);
		}
		else
		{
			m_cowTime += g_ETime;
		}
	}

	if (m_isMage && !m_isLooser)
	{
		if (m_cowTime >= 2.2f * 3.0f)
		{
			m_cowTime = -1.4f * 3.0f;
			m_unitManager->createUnit(cow, false, false);
		}
		else
		{
			m_cowTime += g_ETime;
		}

		if (m_mageTime >= 3.6f * 3.0f)
		{
			m_mageTime = 0.0f;
			m_unitManager->createUnit(mage, false, false);
		}
		else
		{
			m_mageTime += g_ETime;
		}
	}

	if (m_isLooser && !m_isCuteGirl)
	{
		if (m_cowTime >= 4.2f * 3.0f)
		{
			m_cowTime = -2.0f * 3.0f;
			m_unitManager->createUnit(cow, false, false);
		}
		else
		{
			m_cowTime += g_ETime;
		}

		if (m_mageTime >= 2.6f * 3.0f)
		{
			m_mageTime = -3.6f * 3.0f;
			m_unitManager->createUnit(mage, false, false);
		}
		else
		{
			m_mageTime += g_ETime;
		}

		if (m_looserTime >= 6.2f * 3.0f)
		{
			m_looserTime = 0.0f;
			m_unitManager->createUnit(looser, false, false);
		}
		else
		{
			m_looserTime += g_ETime;
		}
	}

	if (m_isCuteGirl && !m_isStone)
	{
		/*if (m_cowTime >= 2.2f)
		{
			m_cowTime = 0.0f;
			m_unitManager->createUnit(cow, false);
		}
		else
		{
			m_cowTime += g_ETime;
		}

		if (m_mageTime >= 3.6f)
		{
			m_mageTime = 0.0f;
			m_unitManager->createUnit(mage, false);
		}
		else
		{
			m_mageTime += g_ETime;
		}

		if (m_looserTime >= 4.2f)
		{
			m_looserTime = 0.0f;
			m_unitManager->createUnit(looser, false);
		}
		else
		{
			m_looserTime += g_ETime;
		}*/

		if (m_cuteGirlTime >= 2.8f * 3.0f)
		{
			m_cuteGirlTime = 0.0f;
			m_unitManager->createUnit(cuteGirl, false, false);
		}
		else
		{
			m_cuteGirlTime += g_ETime;
		}
	}

	if (m_isStone)
	{
		if (m_cowTime >= 4.2f * 3.0f)
		{
			m_cowTime = 0.0f;
			m_unitManager->createUnit(cow, false, false);
		}
		else
		{
			m_cowTime += g_ETime;
		}

		if (m_mageTime >= 3.6f * 3.0f)
		{
			m_mageTime = 0.0f;
			m_unitManager->createUnit(mage, false, false);
		}
		else
		{
			m_mageTime += g_ETime;
		}

		if (m_looserTime >= 8.2f * 3.0f)
		{
			m_looserTime = 0.0f;
			m_unitManager->createUnit(looser, false, false);
		}
		else
		{
			m_looserTime += g_ETime;
		}

		if (m_cuteGirlTime >= 10.8f * 3.0f)
		{
			m_cuteGirlTime = 0.0f;
			m_unitManager->createUnit(cuteGirl, false, false);
		}
		else
		{
			m_cuteGirlTime += g_ETime;
		}

		if (m_stoneTime >= 14.3f * 3.0f)
		{
			m_stoneTime = 0.0f;
			m_unitManager->createUnit(stone, false, false);
		}
		else
		{
			m_stoneTime += g_ETime;
		}
	}











}
