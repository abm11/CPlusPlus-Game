#include "header.h"
#include "templates.h"

#include "EzyabmStage.h"



EzyabmStage::EzyabmStage()
{
}


EzyabmStage::~EzyabmStage()
{
}

void EzyabmStage::SetupBackgroundBuffer()
{
	
	//------------------------------------------
	//chooseAccount

	FillBackground(0xf0ba4a);
	DrawBackgroundRectangle(450, 250, 1000, 300, 0x00ffff);
	DrawBackgroundRectangle(450, 300, 1000, 350, 0xffffff);

	//------------------------------------

}