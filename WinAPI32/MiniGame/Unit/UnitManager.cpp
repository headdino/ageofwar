#include "stdafx.h"
#include "UnitManager.h"
#include "MiniGame/Player/Enemy.h"
#include "MiniGame/Shop/Shop.h"

UnitManager::UnitManager()
{
	ZeroMemory(mPTemp, sizeof(mPTemp));
	ZeroMemory(mETemp, sizeof(mETemp));
}


UnitManager::~UnitManager()
{
}

HRESULT UnitManager::init()
{
	maPUint = new Unit[UNITMAX];
	maEUint = new Unit[UNITMAX];

	for (int i = 0; i < UNITMAX; i++)
	{
		maPUint[i].init(cow, true, true);
		maEUint[i].init(cow, false, true);
	}


	return S_OK;
}

void UnitManager::release()
{
	//mvPUnit.clear();
	//mvPUnit.shrink_to_fit();

	//mvEUnit.clear();
	//mvEUnit.shrink_to_fit();
}

void UnitManager::update()
{
	if (KEYMANAGER->isKeyDown('A'))
	{
		createUnit(cow, true, false);
	}
	if (KEYMANAGER->isKeyDown('S'))
	{
		createUnit(mage, true, false);
	}
	if (KEYMANAGER->isKeyDown('D'))
	{
		createUnit(looser, true, false);
	}
	if (KEYMANAGER->isKeyDown('F'))
	{
		createUnit(cuteGirl, true, false);
	}
	if (KEYMANAGER->isKeyDown('G'))
	{
		createUnit(stone, true, false);
	}



	//for (mviUnit = mvUnit.begin(); mviUnit != mvUnit.end(); mviUnit++)
	//{
	//	(*mviUnit).update();
	//}
	//for (int i = 0; i < mvPUnit.size(); i++)
	//{
	//	mvPUnit[i]->update();
	//}

	//for (int i = 0; i < mvEUnit.size(); i++)
	//{
	//	mvEUnit[i]->update();
	//}
	

	////플레이어 유닛 벡터 업데이트
	//for (mviUnit iUnit = mvPUnit.begin(); iUnit != mvPUnit.end();)
	//{
	//
	//	//if (!(*iUnit)->Getm_isDead())
	//	//{
	//		(*iUnit)->update();
	//	//}
	//	
	//
	//	iUnit++;
	//	
	//}

	////에너미 유닛 벡터 업데이트
	//for (mviUnit iUnit = mvEUnit.begin(); iUnit != mvEUnit.end();)
	//{

	//	//if (!(*iUnit)->Getm_isDead())
	//	//{
	//		(*iUnit)->update();
	//	//}
	//	

	//	iUnit++;

	//}

	if (KEYMANAGER->isKeyDown('H'))
	{
		for (int i = 0; i < UNITMAX; i++)
		{
			if (!maPUint[i].Getm_isDead())
			{
				maPUint[i].Setm_isDead(true);
			}
			if (!maEUint[i].Getm_isDead())
			{
				maEUint[i].Setm_isDead(true);
			}
		}
	}


	for (int i = 0; i < UNITMAX; i++)
	{
		if (!maPUint[i].Getm_isDead())
		{
			maPUint[i].update();
			
		}

		if (!maEUint[i].Getm_isDead())
		{
			maEUint[i].update();
		}

		//if (maPUint[i].Getm_isDead() && maEUint[i].Getm_isDead()) break;
	}

	refreshInfo();

	checkAtt();
	checkInter();
	checkErase();
}

void UnitManager::render()
{

	//for (mviUnit = mvUnit.begin(); mviUnit != mvUnit.end(); mviUnit++)
	//{
	//	(*mviUnit).render();
	//}

	////플레이어 유닛 벡터 렌더
	//for (mviUnit iUnit = mvPUnit.begin(); iUnit != mvPUnit.end();)
	//{
	//	//if (!(*iUnit)->Getm_isDead())
	//	//{
	//		(*iUnit)->render();
	//	//}
	//
	//	iUnit++;
	//}

	////에너미 유닛 벡터 렌더
	//for (mviUnit iUnit = mvEUnit.begin(); iUnit != mvEUnit.end();)
	//{
	//	//if (!(*iUnit)->Getm_isDead())
	//	//{
	//		(*iUnit)->render();
	//	//}

	//	iUnit++;
	//}

	for (int i = 0; i < UNITMAX; i++)
	{
		if (!maPUint[i].Getm_isDead())
		{
			maPUint[i].render();

		}

		if (!maEUint[i].Getm_isDead())
		{
			maEUint[i].render();
		}

		//if (maPUint[i].Getm_isDead() && maEUint[i].Getm_isDead()) break;
	}

}

void UnitManager::createUnit(UnitType type, bool player, bool isDead)
{
	if (type == ENDUNITTYPE) return;

	for (int i = 0; i < UNITMAX; i++)
	{
		if (player)
		{
			if (maPUint[i].Getm_isDead())
			{
				maPUint[i].init(type, player, isDead);
				break;
			}
		}
		else
		{
			if (maEUint[i].Getm_isDead())
			{
				maEUint[i].init(type, player, isDead);
				break;
			}
		}
		
	}

	/*mUnit = new Unit;
	mUnit->init(type, player, isDead);
	if (player)
	{
		mvPUnit.emplace_back(mUnit);
	}
	else
	{
		mvEUnit.emplace_back(mUnit);
	}*/
	
}

void UnitManager::checkInter()
{

	////아군과 아군 충돌 체크
	//for (mviUnit iUnit = mvPUnit.begin(); iUnit != mvPUnit.end();)
	//{

	//	mviUnit iUnit2 = iUnit + 1;

	//	//충돌할 껀덕지가 있으면
	//	if (iUnit2 < mvPUnit.end())
	//	{
	//		if (IntersectRect((*iUnit2)->Getm_rc(), (*iUnit)->Getm_rc()))
	//		{
	//			if ((*iUnit2)->Getm_rc().left - (*iUnit)->Getm_rc().left >= 0 &&
	//				(*iUnit)->Getm_state() != US_DIE)
	//			{
	//				//(*iUnit).Setm_state(US_STOP);
	//				(*iUnit)->Setm_isCollision(true);
	//				//(*iUnit2).Setm_state(US_MOVE);
	//			}
	//			else if ((*iUnit)->Getm_rc().left - (*iUnit2)->Getm_rc().left >= 0 &&
	//				(*iUnit2)->Getm_state() != US_DIE)
	//			{
	//				//(*iUnit2).Setm_state(US_STOP);
	//				(*iUnit2)->Setm_isCollision(true);
	//				//(*iUnit).Setm_state(US_MOVE);
	//			}

	//		}
	//		else
	//		{
	//			(*iUnit)->Setm_isCollision(false);
	//			(*iUnit2)->Setm_isCollision(false);
	//		}
	//	}

	//	iUnit++;

	//}

	////적군과 적군 충돌 체크
	//for (mviUnit iUnit = mvEUnit.begin(); iUnit != mvEUnit.end();)
	//{
	//	mviUnit iUnit2 = iUnit + 1;

	//	//충돌할 껀덕지가 있으면
	//	if (iUnit2 < mvEUnit.end())
	//	{
	//		if (IntersectRect((*iUnit2)->Getm_rc(), (*iUnit)->Getm_rc()))
	//		{
	//			if ((*iUnit2)->Getm_rc().left - (*iUnit)->Getm_rc().left <= 0 &&
	//				(*iUnit)->Getm_state() != US_DIE)
	//			{
	//				//(*iUnit).Setm_state(US_STOP);
	//				(*iUnit)->Setm_isCollision(true);
	//				//(*iUnit2).Setm_state(US_MOVE);
	//			}
	//			else if((*iUnit)->Getm_rc().left - (*iUnit2)->Getm_rc().left <= 0 &&
	//				(*iUnit2)->Getm_state() != US_DIE)
	//			{
	//				//(*iUnit2).Setm_state(US_STOP);
	//				(*iUnit2)->Setm_isCollision(true);
	//				//(*iUnit).Setm_state(US_MOVE);
	//			}

	//		}
	//		else
	//		{
	//			(*iUnit)->Setm_isCollision(false);
	//			(*iUnit2)->Setm_isCollision(false);
	//		}
	//	}

	//	iUnit++;

	//}

	for (int i = 0; i < UNITMAX; i++)
	{
		for (int j = 0; j < UNITMAX; j++)
		{
			if (!mPTemp[i].isDead && !mPTemp[j].isDead &&
				i != j )//&& !mPTemp[i].isDead && !mPTemp[j].isDead)
			{
				//아군과 아군끼리의 충돌검사
				if (IntersectRect(mPTemp[i].rc, mPTemp[j].rc))
				{
					if (mPTemp[j].rc.left - mPTemp[i].rc.left > 0)
					{
						//(*iUnit).Setm_state(US_STOP);
						//mvPUnit[i]->stopMove(mPTemp[j].rc.left);
						maPUint[i].stopMove(mPTemp[j].rc.left);
						//mvPUnit[i]->Setm_isCollision(true);
						//(*iUnit2).Setm_state(US_MOVE);
					}
					else if (mPTemp[i].rc.left - mPTemp[j].rc.left >= 0)
					{
						//(*iUnit2).Setm_state(US_STOP);
						//mvPUnit[j]->stopMove(mPTemp[i].rc.left);
						maPUint[j].stopMove(mPTemp[i].rc.left);
						//mvPUnit[j]->Setm_isCollision(true);
						//(*iUnit).Setm_state(US_MOVE);
					}

				}
				else
				{
					/*mvPUnit[i]->Setm_isCollision(false);
					mvPUnit[j]->Setm_isCollision(false);*/
					if (mPTemp[j].rc.left - mPTemp[i].rc.left > 0)
					{
						//(*iUnit).Setm_state(US_STOP);
						//mvPUnit[i]->Setm_isCollision(false);
						maPUint[i].Setm_isCollision(false);
						//(*iUnit2).Setm_state(US_MOVE);
					}
					else if (mPTemp[i].rc.left - mPTemp[j].rc.left >= 0)
					{
						//(*iUnit2).Setm_state(US_STOP);
						//mvPUnit[j]->Setm_isCollision(false);
						maPUint[j].Setm_isCollision(false);
						//(*iUnit).Setm_state(US_MOVE);
					}
				}
			}

			if (!mETemp[i].isDead && !mETemp[j].isDead &&
				i != j)// && !mETemp[i].isDead && !mETemp[j].isDead)
			{
				//적군과 적군 끼리의 충돌
				if (IntersectRect(mETemp[i].rc, mETemp[j].rc))
				{
					if (mETemp[j].rc.left - mETemp[i].rc.left < 0)
					{
						//(*iUnit).Setm_state(US_STOP);
						//mvEUnit[i]->Setm_isCollision(true);
						//mvEUnit[i]->stopMove(mETemp[j].rc.right);
						maEUint[i].stopMove(mETemp[j].rc.right);
						//(*iUnit2).Setm_state(US_MOVE);
					}
					else if (mETemp[i].rc.left - mETemp[j].rc.left <= 0)
					{
						//(*iUnit2).Setm_state(US_STOP);
						//mvEUnit[j]->Setm_isCollision(true);
						//mvEUnit[j]->stopMove(mETemp[i].rc.right);
						maEUint[j].stopMove(mETemp[i].rc.right);
						//(*iUnit).Setm_state(US_MOVE);
					}

				}
				else
				{
					//mvEUnit[i]->Setm_isCollision(false);
					//mvEUnit[j]->Setm_isCollision(false);
					if (mETemp[j].rc.left - mETemp[i].rc.left < 0)
					{
						//(*iUnit).Setm_state(US_STOP);
						//mvEUnit[i]->Setm_isCollision(false);
						maEUint[i].Setm_isCollision(false);
						//(*iUnit2).Setm_state(US_MOVE);
					}
					else if (mETemp[i].rc.left - mETemp[j].rc.left <= 0)
					{
						//(*iUnit2).Setm_state(US_STOP);
						//mvEUnit[j]->Setm_isCollision(false);
						maEUint[j].Setm_isCollision(false);
						//(*iUnit).Setm_state(US_MOVE);
					}
				}
			}



			if (mPTemp[i].isDead && mPTemp[j].isDead &&
				mETemp[i].isDead && mETemp[j].isDead ) break;
		}
	}




	



}


void UnitManager::checkAtt()
{
	//사거리 안에 든 상대를 찾기 위한 포문
	for (int i = 0; i < UNITMAX; i++)
	{
		for (int j = 0; j < UNITMAX; j++)
		{
			if (!mPTemp[i].isDead && !mETemp[j].isDead)
			{
				//둘 사이에 거리보다 플레이어 캐릭사거리가 더 길다
				//즉 플레이어 사거리 안에 적이 들어왔다.
				if (mPTemp[i].range >= GetDistance(mETemp[j].posX, mETemp[j].rc.top, mPTemp[i].posX, mPTemp[i].rc.top))
				{
					maPUint[i].Setm_isInRange(true);
					//maPUint[i].stopMove(maEUint[j].Getm_rc().left);
					if (maPUint[i].Getm_isAttackFinish() || maEUint[j].Getm_state() == US_DIE)
					{
						maPUint[i].Setm_isAttackFinish(false);
						maEUint[j].damagged(maPUint[i].Getm_damage());
						/*if (maEUint[j].Getm_state() == US_DIE)*/maPUint[i].Setm_isInRange(false);
						
						//maPUint[i].Setm_isCollision(false);
					}
					break;
				}
				else if (mPTemp[i].range < GetDistance(mETemp[j].posX, mETemp[j].rc.top, mPTemp[i].posX, mPTemp[i].rc.top))
				{
					maPUint[i].Setm_isInRange(false);
				}
			}
		}
	}

	//사거리 안에 든 상대를 찾기 위한 포문
	for (int i = 0; i < UNITMAX; i++)
	{
		for (int j = 0; j < UNITMAX; j++)
		{
			if (!mPTemp[j].isDead && !mETemp[i].isDead)
			{
				//반대로 적 사거리에 내가 들어왔다
				if (mETemp[i].range >= GetDistance(mETemp[i].posX, mETemp[i].rc.top, mPTemp[j].posX, mPTemp[j].rc.top))
				{
					//cout << GetDistance(mETemp[i].posX, mETemp[i].rc.top, mPTemp[j].posX, mPTemp[j].rc.top) << endl;
					maEUint[i].Setm_isInRange(true);
					//maEUint[i].stopMove(maPUint[j].Getm_rc().right);
					if (maEUint[i].Getm_isAttackFinish() || maPUint[j].Getm_state() == US_DIE)
					{
						maEUint[i].Setm_isAttackFinish(false);
						maPUint[j].damagged(maPUint[i].Getm_damage());
						/*if (maPUint[i].Getm_state() == US_DIE)*/maEUint[i].Setm_isInRange(false);
						break;
						//maEUint[i].Setm_isCollision(false);
					}
					break;
				}
				else if (mETemp[i].range < GetDistance(mETemp[i].posX, mETemp[i].rc.top, mPTemp[j].posX, mPTemp[j].rc.top))
				{
					maEUint[i].Setm_isInRange(false);
				}

			}
		}
	}

	for (int i = 0; i < UNITMAX; i++)
	{
		if (!mPTemp[i].isDead)// && !mPTemp[i].isDead)
		{
			//아군 유닛 사거리안에 적군 기지가 들어왔다
			if (mPTemp[i].range > m_enemy->Getm_rc().left - mPTemp[i].posX)
			{
				maPUint[i].Setm_isInRange(true);
				if (maPUint[i].Getm_isAttackFinish())
				{
					maPUint[i].Setm_isAttackFinish(false);
					m_enemy->damagged(maPUint[i].Getm_damage());
					maPUint[i].stopMove(m_enemy->Getm_rc().left);
				}
			}

			//마우스가 아군 유닛이랑 충돌했을경우
			//체력바를 표시해준다.
			if (PtInRect(mPTemp[i].rc, g_ptMouse + g_ptCam))
			{
				maPUint[i].Setm_isCollisionMouse(true);
			}
			else
			{
				maPUint[i].Setm_isCollisionMouse(false);
			}
		}

		if (!mETemp[i].isDead)//&& !mETemp[i].isDead)
		{
			//적군 유닛 사거리안에 아군 기지가 들어왔다
			if (mETemp[i].range > mETemp[i].posX - m_shop->Getm_rc().right)
			{
				maEUint[i].Setm_isInRange(true);
				if (maEUint[i].Getm_isAttackFinish())
				{
					maEUint[i].Setm_isAttackFinish(false);
					m_shop->damagged(maEUint[i].Getm_damage());
					maEUint[i].stopMove(m_shop->Getm_rc().right);
				}
			}

			//체력바를 표시해준다.
			if (PtInRect(mETemp[i].rc, g_ptMouse + g_ptCam))
			{
				maEUint[i].Setm_isCollisionMouse(true);
			}
			else
			{
				maEUint[i].Setm_isCollisionMouse(false);
			}
		}

	}

	
	//if (mPTemp[i].isDead && mETemp[j].isDead) break;


}

void UnitManager::checkErase()
{

	//mviUnit iUnit;
	//int a = 0;
	////죽은 유닛을 찾기위한 포문
	//for (mviUnit i = mvPUnit.begin(); i < mvPUnit.end(); i++,a++)
	//{
	//	if (mPTemp[a].posX != NULL)
	//	{
	//		if (mPTemp[a].isDead)
	//		{
	//			mvPUnit.erase(i);
	//			/*(*i)->release();*/

	//			//iUnit = mvPUnit.begin() + i;
	//			//(*iUnit)->release();
	//			//mvPUnit.erase(iUnit);
	//			//mvPUnit[i]->release();
	//			//mvPUnit.erase(mvPUnit.begin() + i);
	//			//refreshInfo();
	//			break;
	//		}

	//	}
	//	//if (mETemp[i].posX != NULL)
	//	//{
	//	//	if (mETemp[i].isDead)
	//	//	{
	//	//		iUnit = mvEUnit.begin() + i;

	//	//		mvEUnit.erase(iUnit);
	//	//		//mvEUnit[i]->giveMoney();
	//	//		//mvEUnit[i]->release();
	//	//		//mvEUnit.at(i)->giveMoney();
	//	//		//mvEUnit.at(i)->release();
	//	//		////(*(mvEUnit.begin() + i))->release();
	//	//		//mvEUnit.erase(mvEUnit.begin() + i);
	//	//		//refreshInfo();
	//	//		break;
	//	//	}
	//	//}

	//	//if (mPTemp[i].posX == NULL && mETemp[i].posX == NULL) break;
	//}

	for (int i = 0; i < UNITMAX; i++)
	{
		if (maPUint[i].Getm_isDead())
		{
			maPUint[i].Setm_rc(RectMakeCenter(-500.0f, -500.0f, 100.0f, 100.0f));
		}
		if (maEUint[i].Getm_isDead())
		{
			if (maEUint[i].Getm_rc().left != -500.0f)
			{
				//maEUint[i].giveMoney();
			}
			maEUint[i].Setm_rc(RectMakeCenter(-450.0f, -500.0f, 100.0f, 100.0f));
		}
	}

	//refreshInfo();


}

void UnitManager::refreshInfo()
{
	//위치랑 사거리만 배열로 넘겨주는 작업
	for (int i = 0; i < UNITMAX; i++)
	{

		mPTemp[i].posX = maPUint[i].Getm_rc().left + (maPUint[i].Getm_rc().right - maPUint[i].Getm_rc().left) / 2.0f;
		mPTemp[i].range = maPUint[i].Getm_range();
		mPTemp[i].isDead = maPUint[i].Getm_isDead();
		mPTemp[i].rc = maPUint[i].Getm_rc();
		
		


		
	
		mETemp[i].posX = maEUint[i].Getm_rc().left + (maEUint[i].Getm_rc().right - maEUint[i].Getm_rc().left) / 2.0f;
		mETemp[i].range = maEUint[i].Getm_range();
		mETemp[i].isDead = maEUint[i].Getm_isDead();
		mETemp[i].rc = maEUint[i].Getm_rc();
		


	}
}
