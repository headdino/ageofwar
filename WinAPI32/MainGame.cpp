#include "stdafx.h"
#include "MainGame.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	//싱글톤 해제
	KEYMANAGER->ReleaseSingleton();
	TIMEMANAGER->ReleaseSingleton();
	SOUNDMANAGER->ReleaseSingleton();
	CAMMANAGER->ReleaseSingleton();
	IMGMANAGER->DeleteAll();
	IMGMANAGER->ReleaseSingleton();
	WRITEMANAGER->ReleaseSingleton();

	m_pg->release();
	SAFE_DELETE(m_pg);

}

HRESULT MainGame::init()
{
	//윈도우가 시작되서 지금까지 흐른 시간을 1/1000초 단위로
	//DWORD형을 리턴하는 함수다
	srand(GetTickCount());
	////////////////////////////////////////////////////
	//m_Arka = new Arka;
	//m_Arka->init();

	m_pg = new PlayGame;
	m_pg->init();

	//new Image(_T("록맨.bmp"), 10, 2, "PS2");







	////////////////////////////////////////////////////
	ImGui::Create(g_hwnd, Device, DeviceContext);
	ImGui::StyleColorsDark();
	return S_OK;
}

void MainGame::release()
{
	////////////////////////////////////////////////////
	


	////////////////////////////////////////////////////
	ImGui::Delete();
}

void MainGame::update()
{
	////////////////////////////////////////////////////
	m_pg->update();

	

	////////////////////////////////////////////////////
	SOUNDMANAGER->Update();
	ImGui::Update();
}

void MainGame::render()
{
	D3DXCOLOR background = D3DXCOLOR(1, 1, 1, 1);
	DeviceContext->ClearRenderTargetView(RTV, (float *)background);
	CAMMANAGER->SetBuffers();
	WRITEMANAGER->GetDc()->BeginDraw();
	////////////////////////////////////////////////////
	
	m_pg->render();


	////////////////////////////////////////////////////
#ifdef _DEBUG
	ImGui::Render();
#endif 
	WRITEMANAGER->GetDc()->EndDraw();
	SwapChain->Present(0, 0);
	
}
