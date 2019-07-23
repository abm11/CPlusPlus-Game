#include "header.h"
#include "EzyabmTileManager.h"


//Constructor
EzyabmTileManager::EzyabmTileManager() : TileManager(50,50)
{
}

//Destructor
EzyabmTileManager::~EzyabmTileManager()
{
}

void EzyabmTileManager::DrawTileAt(
	BaseEngine* pEngine,
	SDL_Surface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY) const
{
	unsigned int iColour;

	// Base class implementation just draws some grey tiles
	if ((iMapX == tile_num) || (8- iMapX ==tile_num)) {
		iColour = 0xFFFFFF;
	}
	else {
		iColour = 0x000000 * ((iMapX + iMapY + GetValue(iMapX, iMapY)) % 16);
	}
	pEngine->DrawRectangle(
		iStartPositionScreenX,
		iStartPositionScreenY,
		iStartPositionScreenX + GetTileWidth() - 1,
		iStartPositionScreenY + GetTileHeight() - 1,
		iColour,
		pSurface);
}