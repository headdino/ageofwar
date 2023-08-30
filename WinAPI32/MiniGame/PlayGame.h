#pragma once
#include "GameNode.h"
#include "Map/Stage.h"
#include "Unit/UnitManager.h"
#include "Shop/Shop.h"
#include "Player/Enemy.h"

class PlayGame : public GameNode
{
private:
	Stage* m_Stage;
	UnitManager* m_UnitManager;
	Shop* m_Shop;
	Enemy* m_Enemy;

	bool m_isWin;
	bool m_isInGame;

private:
	void SetImage();
	void ShopImage();

public:
	PlayGame();
	~PlayGame() override;
	HRESULT init() override;
	void release() override;
	void update() override;
	void render() override;
};

