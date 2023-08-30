#include "stdafx.h"
#include "PlayGame.h"


void PlayGame::SetImage()
{
	IMGMANAGER->AddImage("bg_st1", _T("bg_forest.png"), 1, 1, "PS");
	IMGMANAGER->AddImage("bg_st2", _T("bg_desert.png"), 1, 1, "PS");

	IMGMANAGER->GetImage("bg_st1")->Scale(WINSIZEX, WINSIZEY);
	IMGMANAGER->GetImage("bg_st2")->Scale(WINSIZEX, WINSIZEY);


	IMGMANAGER->AddImage("Pcow_move", _T("미노move.bmp"), 8, 4, "PS2");
	IMGMANAGER->GetImage("Pcow_move")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Ecow_move", _T("미노move.bmp"), 8, 4, "PS4");
	IMGMANAGER->GetImage("Ecow_move")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Pcow_stop", _T("미노stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pcow_stop")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Ecow_stop", _T("미노stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Ecow_stop")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Pcow_attack", _T("미노fight.bmp"), 7, 4, "PS2");
	IMGMANAGER->GetImage("Pcow_attack")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Ecow_attack", _T("미노fight.bmp"), 7, 4, "PS4");
	IMGMANAGER->GetImage("Ecow_attack")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Pcow_die", _T("미노stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pcow_die")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Ecow_die", _T("미노stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Ecow_die")->Scale(100.0f, 100.0f);



	IMGMANAGER->AddImage("Pmage_move", _T("드라이어드move.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pmage_move")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("Emage_move", _T("드라이어드move.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Emage_move")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("Pmage_stop", _T("드라이어드stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pmage_stop")->Scale(100.0f, 100.0f);
						 
	IMGMANAGER->AddImage("Emage_stop", _T("드라이어드stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Emage_stop")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("Pmage_attack", _T("드라이어드fight.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pmage_attack")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("Emage_attack", _T("드라이어드fight.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Emage_attack")->Scale(100.0f, 100.0f);
						  
	IMGMANAGER->AddImage("Pmage_die", _T("드라이어드stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pmage_die")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("Emage_die", _T("드라이어드stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Emage_die")->Scale(100.0f, 100.0f);



	IMGMANAGER->AddImage("Plooser_move", _T("챔피언move.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Plooser_move")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Elooser_move", _T("챔피언move.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Elooser_move")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Plooser_stop", _T("챔피언stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Plooser_stop")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Elooser_stop", _T("챔피언stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Elooser_stop")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Plooser_attack", _T("챔피언attack.bmp"), 6, 2, "PS2");
	IMGMANAGER->GetImage("Plooser_attack")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Elooser_attack", _T("챔피언attack.bmp"), 6, 2, "PS4");
	IMGMANAGER->GetImage("Elooser_attack")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Plooser_die", _T("챔피언stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Plooser_die")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Elooser_die", _T("챔피언stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Elooser_die")->Scale(100.0f, 100.0f);



	IMGMANAGER->AddImage("Pstone_move", _T("힐 자이언트move.bmp"), 8, 4, "PS2");
	IMGMANAGER->GetImage("Pstone_move")->Scale(200.0f, 200.0f);
						 
	IMGMANAGER->AddImage("Estone_move", _T("힐 자이언트move.bmp"), 8, 4, "PS4");
	IMGMANAGER->GetImage("Estone_move")->Scale(200.0f, 200.0f);
						 
	IMGMANAGER->AddImage("Pstone_stop", _T("힐 자이언트stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pstone_stop")->Scale(200.0f, 200.0f);
						 
	IMGMANAGER->AddImage("Estone_stop", _T("힐 자이언트stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Estone_stop")->Scale(200.0f, 200.0f);
						
	IMGMANAGER->AddImage("Pstone_attack", _T("힐 자이언트attack.bmp"), 6, 2, "PS2");
	IMGMANAGER->GetImage("Pstone_attack")->Scale(200.0f, 200.0f);
						
	IMGMANAGER->AddImage("Estone_attack", _T("힐 자이언트attack.bmp"), 6, 2, "PS4");
	IMGMANAGER->GetImage("Estone_attack")->Scale(200.0f, 200.0f);
						
	IMGMANAGER->AddImage("Pstone_die", _T("힐 자이언트stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pstone_die")->Scale(200.0f, 200.0f);
						
	IMGMANAGER->AddImage("Estone_die", _T("힐 자이언트stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Estone_die")->Scale(200.0f, 200.0f);


	IMGMANAGER->AddImage("PcuteGirl_move", _T("암살자move.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("PcuteGirl_move")->Scale(100.0f, 100.0f);
						 
	IMGMANAGER->AddImage("EcuteGirl_move", _T("암살자move.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("EcuteGirl_move")->Scale(100.0f, 100.0f);
						 
	IMGMANAGER->AddImage("PcuteGirl_stop", _T("암살자stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("PcuteGirl_stop")->Scale(100.0f, 100.0f);
						  
	IMGMANAGER->AddImage("EcuteGirl_stop", _T("암살자stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("EcuteGirl_stop")->Scale(100.0f, 100.0f);
						
	IMGMANAGER->AddImage("PcuteGirl_attack", _T("암살자fight.bmp"), 7, 4, "PS2");
	IMGMANAGER->GetImage("PcuteGirl_attack")->Scale(100.0f, 100.0f);
						 
	IMGMANAGER->AddImage("EcuteGirl_attack", _T("암살자fight.bmp"), 7, 4, "PS4");
	IMGMANAGER->GetImage("EcuteGirl_attack")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("PcuteGirl_die", _T("암살자stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("PcuteGirl_die")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("EcuteGirl_die", _T("암살자stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("EcuteGirl_die")->Scale(100.0f, 100.0f);


	SOUNDMANAGER->addSound("BGM", "sound/전쟁시대-ost.wav", true);

	SOUNDMANAGER->addSound("cowSpawn", "sound/cowSpawn.wav", false);
	SOUNDMANAGER->addSound("mageSpawn", "sound/mageSpawn.wav", false);
	SOUNDMANAGER->addSound("looserSpawn", "sound/looserSpawn.wav", false);
	SOUNDMANAGER->addSound("cuteGirlSpawn", "sound/cuteGirlSpawn.wav", false);
	SOUNDMANAGER->addSound("stoneSpawn", "sound/stoneSpawn.wav", false);


	SOUNDMANAGER->addSound("SDvictory", "sound/victory.wav", false);
	SOUNDMANAGER->addSound("SDlose", "sound/lose.wav", false);

	SOUNDMANAGER->addSound("normalAtt", "sound/normalAttack.wav", false);
	SOUNDMANAGER->addSound("knifAtt", "sound/knifeAttack.wav", false);



}

void PlayGame::ShopImage()
{
	//상점 이미지
	IMGMANAGER->AddImage("미노", _T("미노.bmp"), "PS");
	IMGMANAGER->AddImage("드라이어드", _T("드라이어드.bmp"), "PS");
	IMGMANAGER->AddImage("챔피언", _T("챔피언.bmp"), "PS");
	IMGMANAGER->AddImage("암살자", _T("암살자.bmp"), "PS");
	IMGMANAGER->AddImage("힐 자이언트", _T("힐 자이언트.bmp"), "PS");
	IMGMANAGER->AddImage("미노2", _T("미노.bmp"), "PS");
	IMGMANAGER->AddImage("드라이어드2", _T("드라이어드.bmp"), "PS");
	IMGMANAGER->AddImage("챔피언2", _T("챔피언.bmp"), "PS");
	IMGMANAGER->AddImage("암살자2", _T("암살자.bmp"), "PS");
	IMGMANAGER->AddImage("힐 자이언트2", _T("힐 자이언트.bmp"), "PS");
	IMGMANAGER->AddImage("곱하기", _T("곱하기.bmp"), "PS2");
	IMGMANAGER->AddImage("골드", _T("골드.bmp"), "PS2");
	IMGMANAGER->AddImage("상점유닛숫자", _T("상점유닛숫자.bmp"), 10, 1, "PS3");
	IMGMANAGER->AddImage("Uniticon", _T("Unit.png"), "PS");
	IMGMANAGER->AddImage("Towericon", _T("Tower.png"), "PS");
	IMGMANAGER->AddImage("Upgradeicon", _T("Upgrade.png"), "PS");
	IMGMANAGER->AddImage("넥서스", _T("넥서스.bmp"), "PS2");
	IMGMANAGER->AddImage("적기지", _T("적기지.bmp"), "PS2");
	IMGMANAGER->AddImage("shoparrowL", _T("shoparrowL.bmp"), "PS2");
	IMGMANAGER->AddImage("shoparrowL1", _T("shoparrowL1.bmp"), "PS2");
	IMGMANAGER->AddImage("테두리", _T("테두리.bmp"), "PS2");
	IMGMANAGER->AddImage("상점테두리", _T("상점테두리.bmp"), "PS2");
	IMGMANAGER->AddImage("lose", _T("게임패배.png"), "PS");
	IMGMANAGER->AddImage("win", _T("게임승리.png"), "PS");
	IMGMANAGER->GetImage("lose")->Scale(WINSIZEX, WINSIZEY);
	IMGMANAGER->GetImage("win")->Scale(WINSIZEX, WINSIZEY);


	IMGMANAGER->AddImage("hpBarBottom", _T("hpBarBottom.bmp"), "PS");
	IMGMANAGER->AddImage("hpBarTop", _T("hpBarTop.bmp"), "PS");
}

PlayGame::PlayGame()
{
}


PlayGame::~PlayGame()
{
}

HRESULT PlayGame::init()
{

	SetImage();
	ShopImage();

	m_Stage = new Stage;
	m_Stage->init(1);

	m_UnitManager = new UnitManager;
	m_UnitManager->init();

	m_Shop = new Shop;
	m_Shop->init();

	m_Enemy = new Enemy;
	m_Enemy->init();



	m_UnitManager->SetEnemy(m_Enemy);
	m_UnitManager->SetShop(m_Shop);
	m_Shop->SetUnitManager(m_UnitManager);
	m_Enemy->SetUnitManager(m_UnitManager);

	m_isWin = false;
	m_isInGame = true;

	SOUNDMANAGER->play("BGM", 0.3f);

	return S_OK;
}

void PlayGame::release()
{
	m_Shop->release();
	SAFE_DELETE(m_Shop);

	SAFE_DELETE(m_Stage);

	m_Enemy->release();
	SAFE_DELETE(m_Enemy);

	m_UnitManager->release();
	SAFE_DELETE(m_UnitManager);
}

void PlayGame::update()
{
	if (m_isInGame)
	{
		m_Enemy->update();

		m_UnitManager->update();

		m_Shop->update();
	}

	if (KEYMANAGER->isKeyDown('0'))
	{
		g_gold = 1000;
	}


	if (m_Shop->Getm_Alive() == false && m_isInGame)
	{
		m_isWin = false;
		m_isInGame = false;
		SOUNDMANAGER->play("SDlose", 0.5f);
	}
	if (m_Enemy->Getm_Alive() == false && m_isInGame)
	{
		m_isWin = true;
		m_isInGame = false;
		SOUNDMANAGER->play("SDvictory", 0.5f);
	}
}

void PlayGame::render()
{

	if (m_isInGame)
	{
		TIMEMANAGER->render();

		m_Stage->Render();

		m_Enemy->render();

		m_Shop->render();

		m_UnitManager->render();
	}
	else
	{
		g_ptCam.x = 0.0f;
		if (m_isWin)
		{
			m_Stage->Render(0);
		}
		else if(!m_isWin)
		{
			m_Stage->Render(1);
		}
	}

}
