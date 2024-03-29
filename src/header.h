#if defined(_MSC_VER)

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_surface.h"
#include "SDL_image.h"

#elif defined(__linux)

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_surface.h"
#include "SDL_image.h"

#else

#ifndef _SDL_H
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#endif


#endif

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>

// These are used for backward compatibility with SDL 1.2 to get the keycodes to work
//#define SDL12_SDLK_FIRST 0
#define SDL12_SDLK_NORMAL 127
#define SDL12_SDLK_LAST 255

extern int level_loaded;
extern int level_change;
extern int level_init;
extern int tile_num;
extern int m_dX;
extern int m_dY;
extern int m_dX1;
extern int m_dY1;
extern int arms;