#include "header.h"
#include "templates.h"
#include "EzyabmEngine.h"
#include <windows.h>
#include "JPGImage.h"
#include "EzyabmTileManager.h"
#include "EnemyDisplayableObject.h"
#include "EnemyDisplayableObject1.h"
//Constructor
EzyabmEngine::EzyabmEngine()
{

}

//Destructor
EzyabmEngine::~EzyabmEngine()
{

}

void EzyabmEngine::SetupBackgroundBuffer()
{
	/////Background init/////
	if (level_loaded == 0) {
		if(level_init == 0){
			SDL_Surface *image0;
			image0 = IMG_Load("Welcome Stage Bright.jpg");
			image0 = SDL_ConvertSurfaceFormat(image0, SDL_PIXELFORMAT_ARGB8888, 0);
			m_pBackgroundSurface = image0;
			level_init = 1;
		}
	}

	/////TILE TIME/////
	int tileWidth = 8;
	int tileheight = 0;

	// Specify how many tiles wide and high
	m_oTiles.SetSize(tileWidth, tileheight);

	// Set coordinates
	m_oTiles.SetBaseTilesPositionOnScreen(95, 25); //Changed
	
	//Draw in tiles
	if(level_loaded==0)
		m_oTiles.DrawAllTiles(this, this->GetBackground(), 0, 0, tileWidth, tileheight);

	// Specify how many tiles wide and high
	m_oTiles.SetSize(tileWidth, tileheight);

	// Set co-ors
	m_oTiles.SetBaseTilesPositionOnScreen(730, 25);
	
	//Draw in tiles
	if (level_loaded == 0)
		m_oTiles.DrawAllTiles(this, this->GetBackground(), 0, 0, tileWidth, tileheight);
}

int EzyabmEngine::InitialiseObjects() {
	//Initialise
	DrawableObjectsChanged();

	DestroyOldObjects();

	CreateObjectArray(3);

	//Store user object
	StoreObjectInArray(0, new EzyabmDisplayableObject(this));

	//Store enemy object
	StoreObjectInArray(1, new EnemyDisplayableObject(this));
	StoreObjectInArray(2, new EnemyDisplayableObject1(this));

	// End array
	StoreObjectInArray(3, NULL);

	return 0;
}

void EzyabmEngine::KeyDown(int iKeyCode)
{
	switch (iKeyCode)
	{
	case SDLK_ESCAPE: // End program when escape is pressed
		SetExitWithCode(0);
		break;

	case SDLK_SPACE: // SPACE Pauses
		switch (m_state)
		{
		case stateInit:
			m_state = stateMain;
			SetupBackgroundBuffer();
			Redraw(true);
			break;

		case stateMain:
			m_state = statePaused;
			m_iPauseStarted = GetTime();
			SetupBackgroundBuffer();
			Redraw(true);
			break;

		case statePaused:
			m_state = stateMain;
			IncreaseTimeOffset(m_iPauseStarted - GetTime());
			SetupBackgroundBuffer();
			Redraw(true);
			break;
		}
	}
}

int EzyabmEngine::MainLoop(void) {
	SDL_Event event;
	int iKeyCode;

	// Main loop: loop until told not to
	while (m_iExitWithCode == -1)
	{

		// Render stuff
		m_iTick = SDL_GetTicks();

		// Poll for events, and handle the ones we care about.
		while (SDL_PollEvent(&event))
		{
			switch (level_loaded) {
			case 1:
				if (level_change == 0)
				{
/*
					level_loaded = 0;*/
					level_change = 1;
					SDL_Surface * image0;
					image0 = IMG_Load("Fight Floor.jpg");
					image0 = SDL_ConvertSurfaceFormat(image0, SDL_PIXELFORMAT_ARGB8888, 0);
					m_pBackgroundSurface = image0;
					CopyAllBackgroundBuffer();
				}
				break;
			}

			switch (event.type)
			{
			case SDL_KEYDOWN:
				//printf("Key down: %d, '%c'\n", SymbolToKeycode(event.key.keysym.sym), event.key.keysym.sym);
				m_pKeyStatus[SymbolToKeycode(event.key.keysym.sym)] = true;
				KeyDown(event.key.keysym.sym);
				break;

			case SDL_KEYUP:
				//printf("Key up: %d, '%c'\n", SymbolToKeycode(event.key.keysym.sym), event.key.keysym.sym);
				m_pKeyStatus[SymbolToKeycode(event.key.keysym.sym)] = false;
				KeyUp(event.key.keysym.sym);
				break;

			case SDL_MOUSEMOTION:
				m_iCurrentMouseX = event.motion.x;
				m_iCurrentMouseY = event.motion.y;
				MouseMoved(event.motion.x, event.motion.y);
				break;

			case SDL_MOUSEBUTTONDOWN:
				m_iMouseXClickedDown = event.button.x;
				m_iMouseYClickedDown = event.button.y;
				MouseDown(event.button.button, event.button.x, event.button.y);
				break;

			case SDL_MOUSEBUTTONUP:
				m_iMouseXClickedUp = event.button.x;
				m_iMouseYClickedUp = event.button.y;
				MouseUp(event.button.button, event.button.x, event.button.y);
				break;

			case SDL_QUIT:
				return 0;			
			}
		}

		// Do any updates for movements
		GameAction();

		// Render the screen
		GameRender();
		
	}
	return 0;
}

void EzyabmEngine::DrawStringsOnTop()
{
	// Build the string to print
	char buf[128];
	
}

void EzyabmEngine::UnDrawStrings()
{
	// Clear the top of the screen, since we about to draw text on it.
	CopyBackgroundPixels(0, 0, GetWindowWidth(), GetWindowHeight());
	if (tile_num < 7) {
		tile_num += 1;
	}
	else {
		tile_num = 0;
	}
	SetupBackgroundBuffer();
	Redraw(true);
}