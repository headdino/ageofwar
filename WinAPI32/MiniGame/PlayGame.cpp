#include "stdafx.h"
#include "PlayGame.h"


void PlayGame::SetImage()
{
	IMGMANAGER->AddImage("bg_st1", _T("bg_forest.png"), 1, 1, "PS");
	IMGMANAGER->AddImage("bg_st2", _T("bg_desert.png"), 1, 1, "PS");

	IMGMANAGER->GetImage("bg_st1")->Scale(WINSIZEX, WINSIZEY);
	IMGMANAGER->GetImage("bg_st2")->Scale(WINSIZEX, WINSIZEY);


	IMGMANAGER->AddImage("Pcow_move", _T("�̳�move.bmp"), 8, 4, "PS2");
	IMGMANAGER->GetImage("Pcow_move")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Ecow_move", _T("�̳�move.bmp"), 8, 4, "PS4");
	IMGMANAGER->GetImage("Ecow_move")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Pcow_stop", _T("�̳�stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pcow_stop")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Ecow_stop", _T("�̳�stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Ecow_stop")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Pcow_attack", _T("�̳�fight.bmp"), 7, 4, "PS2");
	IMGMANAGER->GetImage("Pcow_attack")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Ecow_attack", _T("�̳�fight.bmp"), 7, 4, "PS4");
	IMGMANAGER->GetImage("Ecow_attack")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Pcow_die", _T("�̳�stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pcow_die")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Ecow_die", _T("�̳�stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Ecow_die")->Scale(100.0f, 100.0f);



	IMGMANAGER->AddImage("Pmage_move", _T("����̾��move.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pmage_move")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("Emage_move", _T("����̾��move.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Emage_move")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("Pmage_stop", _T("����̾��stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pmage_stop")->Scale(100.0f, 100.0f);
						 
	IMGMANAGER->AddImage("Emage_stop", _T("����̾��stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Emage_stop")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("Pmage_attack", _T("����̾��fight.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pmage_attack")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("Emage_attack", _T("����̾��fight.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Emage_attack")->Scale(100.0f, 100.0f);
						  
	IMGMANAGER->AddImage("Pmage_die", _T("����̾��stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pmage_die")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("Emage_die", _T("����̾��stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Emage_die")->Scale(100.0f, 100.0f);



	IMGMANAGER->AddImage("Plooser_move", _T("è�Ǿ�move.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Plooser_move")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Elooser_move", _T("è�Ǿ�move.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Elooser_move")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Plooser_stop", _T("è�Ǿ�stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Plooser_stop")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Elooser_stop", _T("è�Ǿ�stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Elooser_stop")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Plooser_attack", _T("è�Ǿ�attack.bmp"), 6, 2, "PS2");
	IMGMANAGER->GetImage("Plooser_attack")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Elooser_attack", _T("è�Ǿ�attack.bmp"), 6, 2, "PS4");
	IMGMANAGER->GetImage("Elooser_attack")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Plooser_die", _T("è�Ǿ�stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Plooser_die")->Scale(100.0f, 100.0f);

	IMGMANAGER->AddImage("Elooser_die", _T("è�Ǿ�stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Elooser_die")->Scale(100.0f, 100.0f);



	IMGMANAGER->AddImage("Pstone_move", _T("�� ���̾�Ʈmove.bmp"), 8, 4, "PS2");
	IMGMANAGER->GetImage("Pstone_move")->Scale(200.0f, 200.0f);
						 
	IMGMANAGER->AddImage("Estone_move", _T("�� ���̾�Ʈmove.bmp"), 8, 4, "PS4");
	IMGMANAGER->GetImage("Estone_move")->Scale(200.0f, 200.0f);
						 
	IMGMANAGER->AddImage("Pstone_stop", _T("�� ���̾�Ʈstop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pstone_stop")->Scale(200.0f, 200.0f);
						 
	IMGMANAGER->AddImage("Estone_stop", _T("�� ���̾�Ʈstop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Estone_stop")->Scale(200.0f, 200.0f);
						
	IMGMANAGER->AddImage("Pstone_attack", _T("�� ���̾�Ʈattack.bmp"), 6, 2, "PS2");
	IMGMANAGER->GetImage("Pstone_attack")->Scale(200.0f, 200.0f);
						
	IMGMANAGER->AddImage("Estone_attack", _T("�� ���̾�Ʈattack.bmp"), 6, 2, "PS4");
	IMGMANAGER->GetImage("Estone_attack")->Scale(200.0f, 200.0f);
						
	IMGMANAGER->AddImage("Pstone_die", _T("�� ���̾�Ʈstop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("Pstone_die")->Scale(200.0f, 200.0f);
						
	IMGMANAGER->AddImage("Estone_die", _T("�� ���̾�Ʈstop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("Estone_die")->Scale(200.0f, 200.0f);


	IMGMANAGER->AddImage("PcuteGirl_move", _T("�ϻ���move.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("PcuteGirl_move")->Scale(100.0f, 100.0f);
						 
	IMGMANAGER->AddImage("EcuteGirl_move", _T("�ϻ���move.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("EcuteGirl_move")->Scale(100.0f, 100.0f);
						 
	IMGMANAGER->AddImage("PcuteGirl_stop", _T("�ϻ���stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("PcuteGirl_stop")->Scale(100.0f, 100.0f);
						  
	IMGMANAGER->AddImage("EcuteGirl_stop", _T("�ϻ���stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("EcuteGirl_stop")->Scale(100.0f, 100.0f);
						
	IMGMANAGER->AddImage("PcuteGirl_attack", _T("�ϻ���fight.bmp"), 7, 4, "PS2");
	IMGMANAGER->GetImage("PcuteGirl_attack")->Scale(100.0f, 100.0f);
						 
	IMGMANAGER->AddImage("EcuteGirl_attack", _T("�ϻ���fight.bmp"), 7, 4, "PS4");
	IMGMANAGER->GetImage("EcuteGirl_attack")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("PcuteGirl_die", _T("�ϻ���stop.bmp"), 6, 4, "PS2");
	IMGMANAGER->GetImage("PcuteGirl_die")->Scale(100.0f, 100.0f);
						   
	IMGMANAGER->AddImage("EcuteGirl_die", _T("�ϻ���stop.bmp"), 6, 4, "PS4");
	IMGMANAGER->GetImage("EcuteGirl_die")->Scale(100.0f, 100.0f);


	SOUNDMANAGER->addSound("BGM", "sound/����ô�-ost.wav", true);

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
	//���� �̹���
	IMGMANAGER->AddImage("�̳�", _T("�̳�.bmp"), "PS");
	IMGMANAGER->AddImage("����̾��", _T("����̾��.bmp"), "PS");
	IMGMANAGER->AddImage("è�Ǿ�", _T("è�Ǿ�.bmp"), "PS");
	IMGMANAGER->AddImage("�ϻ���", _T("�ϻ���.bmp"), "PS");
	IMGMANAGER->AddImage("�� ���̾�Ʈ", _T("�� ���̾�Ʈ.bmp"), "PS");
	IMGMANAGER->AddImage("�̳�2", _T("�̳�.bmp"), "PS");
	IMGMANAGER->AddImage("����̾��2", _T("����̾��.bmp"), "PS");
	IMGMANAGER->AddImage("è�Ǿ�2", _T("è�Ǿ�.bmp"), "PS");
	IMGMANAGER->AddImage("�ϻ���2", _T("�ϻ���.bmp"), "PS");
	IMGMANAGER->AddImage("�� ���̾�Ʈ2", _T("�� ���̾�Ʈ.bmp"), "PS");
	IMGMANAGER->AddImage("���ϱ�", _T("���ϱ�.bmp"), "PS2");
	IMGMANAGER->AddImage("���", _T("���.bmp"), "PS2");
	IMGMANAGER->AddImage("�������ּ���", _T("�������ּ���.bmp"), 10, 1, "PS3");
	IMGMANAGER->AddImage("Uniticon", _T("Unit.png"), "PS");
	IMGMANAGER->AddImage("Towericon", _T("Tower.png"), "PS");
	IMGMANAGER->AddImage("Upgradeicon", _T("Upgrade.png"), "PS");
	IMGMANAGER->AddImage("�ؼ���", _T("�ؼ���.bmp"), "PS2");
	IMGMANAGER->AddImage("������", _T("������.bmp"), "PS2");
	IMGMANAGER->AddImage("shoparrowL", _T("shoparrowL.bmp"), "PS2");
	IMGMANAGER->AddImage("shoparrowL1", _T("shoparrowL1.bmp"), "PS2");
	IMGMANAGER->AddImage("�׵θ�", _T("�׵θ�.bmp"), "PS2");
	IMGMANAGER->AddImage("�����׵θ�", _T("�����׵θ�.bmp"), "PS2");
	IMGMANAGER->AddImage("lose", _T("�����й�.png"), "PS");
	IMGMANAGER->AddImage("win", _T("���ӽ¸�.png"), "PS");
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
