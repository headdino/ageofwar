#pragma once
#include "GameNode.h"
#include "MiniGame/PlayGame.h"

class MainGame :public GameNode
{
private:
	PlayGame* m_pg;

public:
	MainGame();
	~MainGame() override;
	HRESULT init() override;
	void release() override;
	void update() override;
	void render() override;

};

