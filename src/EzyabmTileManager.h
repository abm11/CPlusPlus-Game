#pragma once
#include "TileManager.h"

class EzyabmTileManager :
	public TileManager
{
public:
	EzyabmTileManager();
	~EzyabmTileManager();

	void DrawTileAt(BaseEngine * pEngine, SDL_Surface * pSurface, int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const;

};

