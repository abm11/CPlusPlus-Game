#include "header.h"
#include "EzyabmDisplayableObject.h"
#include "EzyabmEngine.h"
#include "DisplayableObject.h"
#include "templates.h"
#include "BaseEngine.h"
#include "JPGImage.h"
#include <string>
#include <iostream>
#include <string>

EzyabmDisplayableObject::EzyabmDisplayableObject(BaseEngine* pEngine) :
	DisplayableObject(pEngine)
{

	// Start point on screen
	m_iCurrentScreenX = m_iPreviousScreenX = 0;
	m_iCurrentScreenY = m_iPreviousScreenY = 300;
	//Initilises to to left
	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;
	// Set dimensions
	m_iDrawWidth = 30;
	m_iDrawHeight = 80;
	SetVisible(true);

	//Next level point
	if (level_loaded == 1) {
		m_iCurrentScreenX = m_iPreviousScreenX = 0;
		m_iCurrentScreenY = m_iPreviousScreenY = 300;
	}
}


EzyabmDisplayableObject::~EzyabmDisplayableObject()
{

}

int dir = 0;
/* dir...
* 0 = down
* 1 = left
* 2 = up
* 3 = right*/

int attack = 0;
int animation = 0;
SDL_Event event;
bool quit = false;

void EzyabmDisplayableObject::Draw()
{

	//Character model
	if (dir == 0) {
		ImageData im;
		if (attack == 0) {
			if (animation == 0) {
				im.LoadImage("knight iso char_idle_0.png");
				im.RenderImageWithMask(m_pEngine->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, im.GetWidth(), im.GetHeight());
				StoreLastScreenPositionForUndraw();
				animation = 1;
			}
			if (animation == 1) {
				im.LoadImage("knight iso char_idle_1.png");
				im.RenderImageWithMask(m_pEngine->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, im.GetWidth(), im.GetHeight());
				StoreLastScreenPositionForUndraw();
				animation = 2;
			}
			if (animation == 2) {
				im.LoadImage("knight iso char_idle_2.png");
				im.RenderImageWithMask(m_pEngine->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, im.GetWidth(), im.GetHeight());
				StoreLastScreenPositionForUndraw();
				animation = 3;
			}
			if (animation == 3) {
				im.LoadImage("knight iso char_idle_3.png");
				im.RenderImageWithMask(m_pEngine->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, im.GetWidth(), im.GetHeight());
				StoreLastScreenPositionForUndraw();
				animation = 0;
			}

		}
		if (attack == 1) {
			im.LoadImage("knight iso char_slice down_2.png");
			im.RenderImageWithMask(m_pEngine->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, im.GetWidth(), im.GetHeight());
			StoreLastScreenPositionForUndraw();
			attack = 0;
		}

	}

	if (dir == 1) {
		ImageData im;
		if (attack == 0) {
			im.LoadImage("knight iso char_run left_0.png");
			im.RenderImageWithMask(m_pEngine->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, im.GetWidth(), im.GetHeight());
			StoreLastScreenPositionForUndraw();
		}
		if (attack == 1) {
			im.LoadImage("knight iso char_slice right_1.png");
			im.RenderImageWithMask(m_pEngine->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, im.GetWidth(), im.GetHeight());
			StoreLastScreenPositionForUndraw();
			attack = 0;
		}
	}

	if (dir == 2) {
		ImageData im;
		if (attack == 0) {
			im.LoadImage("knight iso char_idle up_0.png");
			im.RenderImageWithMask(m_pEngine->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, im.GetWidth(), im.GetHeight());
			StoreLastScreenPositionForUndraw();
		}
		if (attack == 1) {
			im.LoadImage("knight iso char_slice up_2.png");
			im.RenderImageWithMask(m_pEngine->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, im.GetWidth(), im.GetHeight());
			StoreLastScreenPositionForUndraw();
			attack = 0;
		}
	}

	if (dir == 3) {
		ImageData im;
		if (attack == 0) {
			im.LoadImage("knight iso char_run right_0.png");
			im.RenderImageWithMask(m_pEngine->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, im.GetWidth(), im.GetHeight());
			StoreLastScreenPositionForUndraw();
		}
		if (attack == 1) {
			im.LoadImage("knight iso char_slice left_1.png");
			im.RenderImageWithMask(m_pEngine->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, im.GetWidth(), im.GetHeight());
			StoreLastScreenPositionForUndraw();
			attack = 0;
		}
	}
}


void EzyabmDisplayableObject::DoUpdate(int iCurrentTime)
{
	// Register inputs
	if (GetEngine()->IsKeyPressed(SDLK_w)) {
		m_iCurrentScreenY -= 2;
		dir = 2;
	}
	
	if (GetEngine()->IsKeyPressed(SDLK_s)) {
		m_iCurrentScreenY += 2;
		dir = 0;
	}
	
	if (GetEngine()->IsKeyPressed(SDLK_a)) {
		m_iCurrentScreenX -= 2;
		dir = 1;
	}
	
	if (GetEngine()->IsKeyPressed(SDLK_d)) {
		m_iCurrentScreenX += 2;
		dir = 3;
	}

	if (GetEngine()->IsKeyPressed(SDLK_SPACE)) {
		attack = 1;
	}
	
	//BOOST
	if (GetEngine()->IsKeyPressed(SDLK_LSHIFT)) {
		if (GetEngine()->IsKeyPressed(SDLK_w))
			m_iCurrentScreenY -= 4;
		if (GetEngine()->IsKeyPressed(SDLK_s))
			m_iCurrentScreenY += 4;
		if (GetEngine()->IsKeyPressed(SDLK_a))
			m_iCurrentScreenX -= 4;
		if (GetEngine()->IsKeyPressed(SDLK_d))
			m_iCurrentScreenX += 4;
	}

		
	//Level borders//
	//Set left side barrier
	if (m_iCurrentScreenX < 68)
		m_iCurrentScreenX = 68;
	//Set right side barrier
	if (m_iCurrentScreenX >= GetEngine()->GetWindowWidth() - m_iDrawWidth - 120)
		m_iCurrentScreenX = GetEngine()->GetWindowWidth() - m_iDrawWidth - 120;
	//Set bottom barrier
	if (m_iCurrentScreenY < 98)
		m_iCurrentScreenY = 98;
	//Set top barrier
	if (m_iCurrentScreenY >= GetEngine()->GetWindowHeight() - m_iDrawHeight - 47 )
		m_iCurrentScreenY = GetEngine()->GetWindowHeight() - m_iDrawHeight- 47;

	if ((m_iCurrentScreenX > 550) && (m_iCurrentScreenX < 700) && (m_iCurrentScreenY < 100) && (level_change == 0)) {
		printf("Change level");
		level_loaded = 1;

		m_iCurrentScreenY = GetEngine()->GetWindowHeight() - m_iDrawHeight - 47;
		m_iCurrentScreenX = 600;
	}


	//Redraws for new position
	RedrawObjects();
	
}