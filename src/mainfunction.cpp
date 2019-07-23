#include "header.h"

#include <ctime>

#include "templates.h"

// Needs one of the following #includes, to include the class definition
#include "EzyabmEngine.h"
#include "EzyabmTileManager.h"
#include "EzyabmStage.h"
#include <thread>
#include "JPGImage.h"


const int BaseScreenWidth = 1280;
const int BaseScreenHeight = 720;
int level_loaded = 0;
int level_change = 0;
int level_init = 0;
int tile_num = 0;
int m_dX = 0;
int m_dY = 0;
int m_dX1 = 1000;
int m_dY1 = 800;
int arms = 0;


int main(int argc, char *argv[])
{
	int iResult;

	// Send random number generator with current time
	::srand(time(0));

	EzyabmEngine oMain;

	char buf[1024];
	sprintf(buf, "C++ Game : Size %d x %d", BaseScreenWidth, BaseScreenHeight);
	iResult = oMain.Initialise(buf, BaseScreenWidth, BaseScreenHeight, "Cornerstone Regular.ttf", 24);
	iResult = oMain.MainLoop();
	oMain.Deinitialise();
	return iResult;
}
