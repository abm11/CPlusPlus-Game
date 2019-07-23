#pragma once
#include "DisplayableObject.h"
class EnemyDisplayableObject :
	public DisplayableObject
{
public:
	EnemyDisplayableObject(BaseEngine* pEngine);
	~EnemyDisplayableObject();
	void Draw();
	void DoUpdate(int iCurrentTime);
};
