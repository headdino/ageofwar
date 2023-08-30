#include "stdafx.h"
#include "MainGame.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	//�̱��� ����
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
	//�����찡 ���۵Ǽ� ���ݱ��� �帥 �ð��� 1/1000�� ������
	//DWORD���� �����ϴ� �Լ���
	srand(GetTickCount());
	////////////////////////////////////////////////////
	//m_Arka = new Arka;
	//m_Arka->init();

	m_pg = new PlayGame;
	m_pg->init();

	//new Image(_T("�ϸ�.bmp"), 10, 2, "PS2");







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
