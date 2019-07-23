#pragma once
#include "DisplayableObject.h"
class EzyabmDisplayableObject :
	public DisplayableObject
{
public:
	EzyabmDisplayableObject(BaseEngine* pEngine);
	~EzyabmDisplayableObject();
	void Draw();
	void DoUpdate(int iCurrentTime);
};

