#include "stdafx.h"
#include "Shop.h"
#include "MiniGame/Unit/UnitManager.h"


Shop::Shop()
{
}


Shop::~Shop()
{
	ShopE = nullptr;
	goldE = nullptr;
	m_unitManager = nullptr;
}

HRESULT Shop::init()
{

	shoplist = new Shoplist[5];
	ShopUnit = new ShoplistUnit[6];
	ShopUpgrade = new ShoplistUpgrade[6];
	m_nexus = new Nexus;

	m_slot = emain;
	g_time = 0.0f;
	getgold = 11;

	one, ten, hundred, thousand = 0;
	for (int i = 0; i < 5; i++)
	{
		shoplist[i].shopping = false;
		shoplist[i].pos = D3DXVECTOR2(480.0f + i * 50.0f, 520.0f);
		shoplist[i].size = D3DXVECTOR2(40.0f, 40.0f);
		shoplist[i].index = RectMakeCenter(shoplist[i].pos.x, shoplist[i].pos.y, shoplist[i].size.x, shoplist[i].size.y);

	}

	for (int i = 0; i < 6; i++)
	{
		ShopUnit[i].pos = D3DXVECTOR2(480.0f + i * 50.0f, 520.0f);
		ShopUnit[i].size = D3DXVECTOR2(40.0f, 40.0f);
		ShopUnit[i].index = RectMakeCenter(ShopUnit[i].pos.x, ShopUnit[i].pos.y, ShopUnit[i].size.x, ShopUnit[i].size.y);
		ShopUnit[i].buy = false;
		ShopUnit[i].time = 0.0f;
		ShopUnit[i].price = 100 + i * 100;
		switch (i)
		{
		case 0: ShopUnit[i].unitType = cow;
			break;
		case 1: ShopUnit[i].unitType = mage;
			break;
		case 2: ShopUnit[i].unitType = looser;
			break;
		case 3: ShopUnit[i].unitType = cuteGirl;
			break;
		case 4: ShopUnit[i].unitType = stone;
			break;
		default: ShopUnit[i].unitType = ENDUNITTYPE;
			break;
		}

		ShopUpgrade[i].pos = D3DXVECTOR2(480.0f + i * 50.0f, 520.0f);
		ShopUpgrade[i].size = D3DXVECTOR2(40.0f, 40.0f);
		ShopUpgrade[i].index = RectMakeCenter(ShopUpgrade[i].pos.x, ShopUpgrade[i].pos.y, ShopUpgrade[i].size.x, ShopUpgrade[i].size.y);
		ShopUpgrade[i].buy = false;
	}

	m_nexus->pos = D3DXVECTOR2(60.0f, 120.0f);
	m_nexus->size = D3DXVECTOR2(120.0f, 150.0f);
	m_Alive = true;
	m_nexus->level = 0;
	m_nexus->Hp = 300.0f;

	m_rc = RectMakeCenter(m_nexus->pos.x, m_nexus->pos.y, m_nexus->size.x, m_nexus->size.y);

	NexusHp = (int)m_nexus->Hp;

	ShopE = IMGMANAGER->GetImage("테두리");
	goldE = IMGMANAGER->GetImage("상점테두리");
	

	return S_OK;
}

void Shop::release()
{
	//delete[] shoplist;
	SAFE_DELETE_ARRAY(shoplist);
	SAFE_DELETE_ARRAY(ShopUnit);
	SAFE_DELETE_ARRAY(ShopUpgrade);
	SAFE_DELETE(m_nexus);
}

void Shop::update()
{

	for (int i = 0; i < 6; i++)
	{
		shoplist[i].pos = D3DXVECTOR2(480.0f + i * 50.0f + g_ptCam.x, 520.0f);
		shoplist[i].index = RectMakeCenter(shoplist[i].pos.x, shoplist[i].pos.y, shoplist[i].size.x, shoplist[i].size.y);
		ShopUnit[i].pos = D3DXVECTOR2(480.0f + i * 50.0f + g_ptCam.x, 520.0f);
		ShopUnit[i].index = RectMakeCenter(ShopUnit[i].pos.x, ShopUnit[i].pos.y, ShopUnit[i].size.x, ShopUnit[i].size.y);
		ShopUpgrade[i].pos = D3DXVECTOR2(480.0f + i * 50.0f + g_ptCam.x, 520.0f);
		ShopUpgrade[i].index = RectMakeCenter(ShopUpgrade[i].pos.x, ShopUpgrade[i].pos.y, ShopUpgrade[i].size.x, ShopUpgrade[i].size.y);
	}
	//골드수급 변수 추후 수정
	if (g_time > 1.0f)
	{
		g_gold += 20;
		g_time -= g_time;
	}
	else
	{
		g_time += g_ETime;
	}

	one = g_gold % 10;
	ten = g_gold % 100 / 10;
	hundred = g_gold % 1000 / 100;
	thousand = g_gold % 10000 / 1000;

	//상점 메인메뉴 버튼누르면 이넘값줘서 그 리스트로 넘어감
	if (m_slot == emain)
	{
		if (PtInRect(shoplist[0].index, g_ptMouse+g_ptCam) && KEYMANAGER->isKeyDown(VK_LBUTTON))
		{
			m_slot = eUnit;
		}

		if (PtInRect(shoplist[1].index, g_ptMouse + g_ptCam) && KEYMANAGER->isKeyDown(VK_LBUTTON))
		{
			m_slot = eUpgrade;
		}

		//넥서스 클릭할경우 tower값줌
		if (PtInRect(shoplist[2].index, g_ptMouse + g_ptCam) && KEYMANAGER->isKeyDown(VK_LBUTTON))
		{
			if (m_nexus->level < 1 && g_gold > 99)
			{
				m_slot = eTower;
			}
		}
	}

	if (m_slot == eUnit)
	{
		//유닛 구매시
		for (int i = 0; i < 5; i++)
		{
			if (PtInRect(ShopUnit[i].index, g_ptMouse + g_ptCam) && KEYMANAGER->isKeyDown(VK_LBUTTON) && !ShopUnit[i].buy)
			{
				if (ShopUnit[i].price - 1 < g_gold)
				{
					ShopUnit[i].buy = true;
					buyUnit(ShopUnit[i]);
				}
					
			}
		}

		//뒤로가기
		if (PtInRect(ShopUnit[5].index, g_ptMouse + g_ptCam) && KEYMANAGER->isKeyDown(VK_LBUTTON))
		{
			m_slot = emain;
		}
	}

	//업그레이드
	if (m_slot == eUpgrade)
	{
		for (int i = 0; i < 5; i++)
		{
			if (PtInRect(ShopUpgrade[i].index, g_ptMouse + g_ptCam) && KEYMANAGER->isKeyDown(VK_LBUTTON) && !ShopUpgrade[i].buy)
			{
				ShopUpgrade[i].buy = true;
				//g_gold -= ShopUpgrade[i].buy;
			}
		}

		if (PtInRect(ShopUpgrade[5].index, g_ptMouse + g_ptCam) && KEYMANAGER->isKeyDown(VK_LBUTTON))
		{
			m_slot = emain;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		if (ShopUnit[i].buy)
		{
			ShopUnit[i].time += g_ETime * 0.5f;

			if (ShopUnit[i].time > 1.0f)
			{
				ShopUnit[i].time -= 1.0f;
				ShopUnit[i].buy = false;
			}
		}
	}

	//넥서스 업글될경우 hp랑 레벨늘어남
	if (m_slot == eTower)
	{
		m_nexus->Hp += 300.0f;
		m_nexus->level++;
		g_gold -= 100;
		m_slot = emain;
	}

	//보스 체력담을int 변수
	NexusHp = (int)m_nexus->Hp;
	//m_nexus->Hp -= g_ETime * 5.0f;
}

void Shop::render()
{
	//왼상단 골드이미지
	IMGMANAGER->GetImage("골드")->Position(25.0f + g_ptCam.x, 550.0f);
	IMGMANAGER->GetImage("골드")->Scale(20.0f, 30.0f);
	IMGMANAGER->Render("골드");

	ShopE->Position(600.0f + g_ptCam.x, 520.0f);
	ShopE->Scale(400.0f, 120.0f);
	ShopE->Render();

	goldE->Position(65.0f + g_ptCam.x, 550.0f);
	goldE->Scale(130.0f, 50.0f);
	goldE->Render();

	if (m_slot == emain)
	{
		IMGMANAGER->GetImage("Uniticon")->Position(shoplist[0].pos);
		IMGMANAGER->GetImage("Uniticon")->Scale(shoplist[0].size);
		IMGMANAGER->Render("Uniticon");

		IMGMANAGER->GetImage("Upgradeicon")->Position(shoplist[1].pos);
		IMGMANAGER->GetImage("Upgradeicon")->Scale(shoplist[1].size);
		IMGMANAGER->Render("Upgradeicon");

	

		//넥서스 레벨에따른 가격표시
		if (m_nexus->level == 0)
		{
			IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(1);
			IMGMANAGER->GetImage("상점유닛숫자")->Position(shoplist[2].pos.x - 10.0f, shoplist[2].pos.y - 30.0f);
			IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
			IMGMANAGER->Render("상점유닛숫자");

			IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
			IMGMANAGER->GetImage("상점유닛숫자")->Position(shoplist[2].pos.x, shoplist[2].pos.y - 30.0f);
			IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
			IMGMANAGER->Render("상점유닛숫자");

			IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
			IMGMANAGER->GetImage("상점유닛숫자")->Position(shoplist[2].pos.x + 10.0f, shoplist[2].pos.y - 30.0f);
			IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
			IMGMANAGER->Render("상점유닛숫자");

			IMGMANAGER->GetImage("Towericon")->Position(shoplist[2].pos);
			IMGMANAGER->GetImage("Towericon")->Scale(shoplist[2].size);
			IMGMANAGER->Render("Towericon");
		}

		else if (m_nexus->level == 1)
		{
			//IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(5);
			//IMGMANAGER->GetImage("상점유닛숫자")->Position(shoplist[2].pos.x - 10.0f, shoplist[2].pos.y - 30.0f);
			//IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
			//IMGMANAGER->Render("상점유닛숫자");
			//
			//IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
			//IMGMANAGER->GetImage("상점유닛숫자")->Position(shoplist[2].pos.x, shoplist[2].pos.y - 30.0f);
			//IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
			//IMGMANAGER->Render("상점유닛숫자");
			//
			//IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
			//IMGMANAGER->GetImage("상점유닛숫자")->Position(shoplist[2].pos.x + 10.0f, shoplist[2].pos.y - 30.0f);
			//IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
			//IMGMANAGER->Render("상점유닛숫자");
		}
	}

	if (m_slot == eUnit)
	{
		//상점 유닛 초상화 가격들 표시
		IMGMANAGER->GetImage("미노")->Position(ShopUnit[0].pos);
		IMGMANAGER->GetImage("미노")->Scale(ShopUnit[0].size);
		if (g_gold < 100)
		{
			IMGMANAGER->GetImage("미노")->Color(1.0f, 0.0f, 0.0f);
		}
		else if (g_gold > 99 && !ShopUnit[0].buy)
		{
			IMGMANAGER->GetImage("미노")->Color(0.0f, 0.0f, 0.0f);
		}

		IMGMANAGER->Render("미노");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(1);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[0].pos.x - 10.0f, ShopUnit[0].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[0].pos.x, ShopUnit[0].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[0].pos.x + 10.0f, ShopUnit[0].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");


		//드라이어드 
		IMGMANAGER->GetImage("드라이어드")->Position(ShopUnit[1].pos);
		IMGMANAGER->GetImage("드라이어드")->Scale(ShopUnit[1].size);

		if (g_gold < 200)
		{
			IMGMANAGER->GetImage("드라이어드")->Color(1.0f, 0.0f, 0.0f);
		}
		else if (g_gold > 199 && !ShopUnit[1].buy)
		{
			IMGMANAGER->GetImage("드라이어드")->Color(0.0f, 0.0f, 0.0f);
		}
		IMGMANAGER->Render("드라이어드");

		//백단위 값
		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(2);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[1].pos.x - 10.0f, ShopUnit[1].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[1].pos.x, ShopUnit[1].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[1].pos.x + 10.0f, ShopUnit[1].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");


		IMGMANAGER->GetImage("챔피언")->Position(ShopUnit[2].pos);
		IMGMANAGER->GetImage("챔피언")->Scale(ShopUnit[2].size);

		if (g_gold < 300)
		{
			IMGMANAGER->GetImage("챔피언")->Color(1.0f, 0.0f, 0.0f);
		}
		else if (g_gold > 299 && !ShopUnit[2].buy)
		{
			IMGMANAGER->GetImage("챔피언")->Color(0.0f, 0.0f, 0.0f);
		}

		IMGMANAGER->Render("챔피언");

		//백단위 값
		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(3);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[2].pos.x - 10.0f, ShopUnit[2].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[2].pos.x, ShopUnit[2].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[2].pos.x + 10.0f, ShopUnit[2].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("암살자")->Position(ShopUnit[3].pos);
		IMGMANAGER->GetImage("암살자")->Scale(ShopUnit[3].size);

		if (g_gold < 400)
		{
			IMGMANAGER->GetImage("암살자")->Color(1.0f, 0.0f, 0.0f);
		}
		else if (g_gold > 399 && !ShopUnit[3].buy)
		{
			IMGMANAGER->GetImage("암살자")->Color(0.0f, 0.0f, 0.0f);
		}

		IMGMANAGER->Render("암살자");

		//백단위 값
		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(4);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[3].pos.x - 10.0f, ShopUnit[3].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[3].pos.x, ShopUnit[3].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[3].pos.x + 10.0f, ShopUnit[3].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("힐 자이언트")->Position(ShopUnit[4].pos);
		IMGMANAGER->GetImage("힐 자이언트")->Scale(ShopUnit[4].size);

		if (g_gold < 500)
		{
			IMGMANAGER->GetImage("힐 자이언트")->Color(1.0f, 0.0f, 0.0f);
		}
		else if (g_gold > 499 && !ShopUnit[4].buy)
		{
			IMGMANAGER->GetImage("힐 자이언트")->Color(0.0f, 0.0f, 0.0f);
		}

		IMGMANAGER->Render("힐 자이언트");

		//백단위 값
		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(5);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[4].pos.x - 10.0f, ShopUnit[4].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[4].pos.x, ShopUnit[4].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(0);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(ShopUnit[4].pos.x + 10.0f, ShopUnit[4].pos.y - 30.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(10.0f, 10.0f);
		IMGMANAGER->Render("상점유닛숫자");

		//뒤로가기 버튼
		IMGMANAGER->GetImage("shoparrowL")->Position(ShopUnit[5].pos);
		IMGMANAGER->GetImage("shoparrowL")->Scale(ShopUnit[5].size);
		IMGMANAGER->Render("shoparrowL");

		//유닛 쿨타임
		if (ShopUnit[0].buy)
		{
			IMGMANAGER->GetImage("미노")->Color(0.0f, 0.0f, 0.0f, ShopUnit[0].time - 0.2f);
		}

		if (ShopUnit[1].buy)
		{
			IMGMANAGER->GetImage("드라이어드")->Color(0.0f, 0.0f, 0.0f, ShopUnit[1].time);
		}

		if (ShopUnit[2].buy)
		{
			IMGMANAGER->GetImage("챔피언")->Color(0.0f, 0.0f, 0.0f, ShopUnit[2].time);
		}

		if (ShopUnit[3].buy)
		{
			IMGMANAGER->GetImage("암살자")->Color(0.0f, 0.0f, 0.0f, ShopUnit[3].time);
		}

		if (ShopUnit[4].buy)
		{
			IMGMANAGER->GetImage("힐 자이언트")->Color(0.0f, 0.0f, 0.0f, ShopUnit[4].time);
		}
	}

	if (m_slot == eUpgrade)
	{
		//뒤로가기 버튼
		IMGMANAGER->GetImage("shoparrowL")->Position(ShopUpgrade[5].pos);
		IMGMANAGER->GetImage("shoparrowL")->Scale(ShopUpgrade[5].size);
		IMGMANAGER->Render("shoparrowL");
	}

	//넥서스 레벨에따른 이미지
	if (m_nexus->level == 0)
	{
		IMGMANAGER->GetImage("넥서스")->Position(m_nexus->pos);
		IMGMANAGER->GetImage("넥서스")->Scale(m_nexus->size);
		IMGMANAGER->Render("넥서스");
	}

	else if (m_nexus->level == 1)
	{
		IMGMANAGER->GetImage("넥서스")->Position(m_nexus->pos.x, m_nexus->pos.y + 80.0f);
		IMGMANAGER->GetImage("넥서스")->Scale(m_nexus->size);
		IMGMANAGER->Render("넥서스");

		IMGMANAGER->GetImage("넥서스")->Position(m_nexus->pos.x, m_nexus->pos.y - 80.0f);
		IMGMANAGER->GetImage("넥서스")->Scale(m_nexus->size);
		IMGMANAGER->Render("넥서스");
	}

	//돈표시
	if (g_gold > 9 && g_gold < 100)
	{
		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(ten);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(50.0f + g_ptCam.x, 550.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(20.0f, 20.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(one);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(64.0f + g_ptCam.x, 550.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(20.0f, 20.0f);
		IMGMANAGER->Render("상점유닛숫자");
	}
	else if (g_gold > -1 && g_gold < 10)
	{
		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(one);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(50.0f + g_ptCam.x, 550.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(20.0f, 20.0f);
		IMGMANAGER->Render("상점유닛숫자");
	}
	if (g_gold > 99 && g_gold < 1000)
	{
		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(hundred);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(50.0f + g_ptCam.x, 550.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(20.0f, 20.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(ten);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(64.0f + g_ptCam.x, 550.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(20.0f, 20.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(one);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(78.0f + g_ptCam.x, 550.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(20.0f, 20.0f);
		IMGMANAGER->Render("상점유닛숫자");
	}
	if (g_gold > 999)
	{
		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(thousand);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(50.0f + g_ptCam.x, 550.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(20.0f, 20.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(hundred);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(64.0f + g_ptCam.x, 550.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(20.0f, 20.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(ten);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(78.0f + g_ptCam.x, 550.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(20.0f, 20.0f);
		IMGMANAGER->Render("상점유닛숫자");

		IMGMANAGER->GetImage("상점유닛숫자")->SetCurrentFrameX(one);
		IMGMANAGER->GetImage("상점유닛숫자")->Position(92.0f + g_ptCam.x, 550.0f);
		IMGMANAGER->GetImage("상점유닛숫자")->Scale(20.0f, 20.0f);
		IMGMANAGER->Render("상점유닛숫자");
	}


	//보스 체력바
	wchar_t str[256];
	swprintf_s(str, L"HP: %d", NexusHp);

	if (m_nexus->Hp > 0.0f)
	{
		if (m_nexus->level == 0)
		{
			Rect* Hpbar = IMGMANAGER->Getrect();
			IMGMANAGER->Getrect()->SetisFill(true);
			IMGMANAGER->Getrect()->Position(30.0f, 300.0f + (m_nexus->Hp / 4 - 100.0f));
			IMGMANAGER->Getrect()->Scale(50.0f, m_nexus->Hp / 2);
			IMGMANAGER->Getrect()->Color(1.0f, 0.0f, 0.0f);
			IMGMANAGER->RectRender();

			RECT rect = { 10 - g_ptCam.x, 190, 150 - g_ptCam.x, 210 };
			WRITEMANAGER->RenderText(str, rect, 20, L"돋움체", D3DXCOLOR(0, 0, 0, 1));
		}

		else if (m_nexus->level == 1)
		{
			IMGMANAGER->Getrect()->Position(30.0f, 370.0f + (m_nexus->Hp / 4 - 100.0f));
			IMGMANAGER->Getrect()->Scale(50.0f, m_nexus->Hp / 2);
			IMGMANAGER->RectRender();

			RECT rect = { 10 - g_ptCam.x, 70, 150 - g_ptCam.x, 90 };
			WRITEMANAGER->RenderText(str, rect, 20, L"돋움체", D3DXCOLOR(0, 0, 0, 1));
		}
	}

}

void Shop::buyUnit(ShoplistUnit shopUnit)
{
	m_unitManager->createUnit(shopUnit.unitType, true, false);
	g_gold -= shopUnit.price;
	switch (shopUnit.unitType)
	{
	case cow:
		SOUNDMANAGER->play("cowSpawn", 0.3f);
		break;
	case mage:
		SOUNDMANAGER->play("mageSpawn", 0.3f);
		break;
	case stone:
		SOUNDMANAGER->play("stoneSpawn", 0.1f);
		break;
	case looser:
		SOUNDMANAGER->play("looserSpawn", 0.3f);
		break;
	case cuteGirl:
		SOUNDMANAGER->play("cuteGirlSpawn", 0.7f);
		break;
	default:
		break;
	}
}

void Shop::damagged(float damage)
{
	if (m_nexus->level == 0)m_nexus->Hp -= damage;
	if (m_nexus->level == 1)m_nexus->Hp -= damage / 2.0f;
	
	if (m_nexus->Hp <= 0)
	{
		m_Alive = false;
	}
}