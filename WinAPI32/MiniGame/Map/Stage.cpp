#include "stdafx.h"
#include "Stage.h"


Stage::Stage() : m_stage(NULL), m_bg(nullptr)
{
}


Stage::~Stage()
{
	m_bg = nullptr;
	//SAFE_DELETE(m_bg);
}

void Stage::init(int stage)
{
	m_stage = stage;

	switch (m_stage)
	{
	case 0:
		m_bg = IMGMANAGER->GetImage("bg_st1");
		break;
	case 1:
		m_bg = IMGMANAGER->GetImage("bg_st2");
		break;
	default:
		m_bg = nullptr;
		break;
	}
	m_lpsp = 0.0f;

}

void Stage::Render(void)
{
	//움직이는지 확인용 나중에 제거 예정
	/*if (KEYMANAGER->StayKeyDown(VK_LEFT))
	{
		g_ptCam.x -= g_ETime;
	}
	if (KEYMANAGER->StayKeyDown(VK_RIGHT))
	{
		g_ptCam.x += 50.0f * g_ETime;
	}*/
	//1600
	if (g_ptCam.x > 0 &&
		g_ptMouse.x <50)
	{
		g_ptCam.x -= 120.0f * g_ETime;
		m_lpsp -= 0.1f * g_ETime;
	}

	if (g_ptCam.x < 800 &&
		g_ptMouse.x > 750)
	{
		g_ptCam.x += 120.0f * g_ETime;
		m_lpsp += 0.1f * g_ETime;
	}

	if (KEYMANAGER->isKeyDown(VK_LEFT))
	{
		g_ptCam.x = 0.0f;
		m_lpsp = 0.0f;
	}
	if (KEYMANAGER->isKeyDown(VK_UP))
	{
		g_ptCam.x = 360.0f;
		m_lpsp = 0.3f;
	}
	if (KEYMANAGER->isKeyDown(VK_RIGHT))
	{
		g_ptCam.x = 720.0f;
		m_lpsp = 0.6f;
	}

	//cout << g_ptCam.x << "   마우스 좌표 ->   " << g_ptMouse.x << endl;
	if (m_bg != nullptr)
	{
		m_bg->Position(WINSIZEX / 2.0f + g_ptCam.x, WINSIZEY / 2.0f + g_ptCam.y);
		m_bg->LoofRender(m_lpsp, 0);
	}
	
}

void Stage::Render(int a)
{

	switch (a)
	{
	case 0:
		m_bg = IMGMANAGER->GetImage("win");
		break;
	case 1:
		m_bg = IMGMANAGER->GetImage("lose");
		break;
	default:
		break;
	}
	m_bg->Position(WINSIZEX / 2.0f, WINSIZEY / 2.0f);
	m_bg->Render();
}
