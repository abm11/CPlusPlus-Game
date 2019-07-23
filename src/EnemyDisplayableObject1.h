#pragma once
#include "DisplayableObject.h"
class EnemyDisplayableObject1 :
	public DisplayableObject
{
public:
	EnemyDisplayableObject1(BaseEngine* pEngine);
	~EnemyDisplayableObject1();
	void Draw();
	void DoUpdate(int iCurrentTime);
};
