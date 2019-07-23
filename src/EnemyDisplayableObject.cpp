#include "header.h"
#include "EnemyDisplayableObject.h"
#include "EnemyDisplayableObject1.h"
#include "EzyabmEngine.h"
#include "DisplayableObject.h"
#include "templates.h"
#include "BaseEngine.h"
#include "JPGImage.h"

#include <iostream>
#include <string> // for string class

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>


using namespace std;

	int m_dSX = 2;
	int m_dSY = 2;

// Constructor
EnemyDisplayableObject::EnemyDisplayableObject(BaseEngine* pEngine) :
	DisplayableObject(pEngine)
{
	// Start point on screen
	m_iCurrentScreenX = m_iPreviousScreenX = 0;
	m_iCurrentScreenY = m_iPreviousScreenY = 300;
	//Initilises to to left
	m_iStartDrawPosX = 0;
	m_iStartDrawPosY = 0;
	// Set dimensions
	m_iDrawWidth = 32;
	m_iDrawHeight = 34;
	SetVisible(true);

	//Next level point
	if (level_loaded == 1) {
		m_iCurrentScreenX = m_iPreviousScreenX = 0;
		m_iCurrentScreenY = m_iPreviousScreenY = 300;
	}
}

EnemyDisplayableObject::~EnemyDisplayableObject()
{

}

char script0[] = "'RARR'";
char script1[] = "'BOO'";
char script2[] = "'SP00KY'";
char script3[] = "'AGH'";
int random;
time_t end0= time(NULL);

void EnemyDisplayableObject::Draw()
{
	switch (level_loaded) {///////////////////////////CASE MESSING WITH IT?
	case 1:
		if (level_change == 1)
		{
			ImageData im;
			im.LoadImage("big_zombie_idle_anim_f0.png");
			im.RenderImageWithMask(m_pEngine->GetForeground(), 0, 0, m_iCurrentScreenX, m_iCurrentScreenY, im.GetWidth(), im.GetHeight());
			StoreLastScreenPositionForUndraw();

			time_t start = time(NULL);



			if (end0 < start)
			{
				end0 = (end0 + 1);
				cout << end0;
				random = rand() % 4;
				
			}

			switch (random) {
			case 0:
				GetEngine()->DrawForegroundString(m_dX, m_dY - 25, script0, 0x00ff00, NULL);
				break;
			case 1:
				GetEngine()->DrawForegroundString(m_dX, m_dY - 25, script1, 0x00ff00, NULL);
				break;
			case 2:
				GetEngine()->DrawForegroundString(m_dX, m_dY - 25, script2, 0x00ff00, NULL);
				break;
			case 3:
				GetEngine()->DrawForegroundString(m_dX, m_dY - 25, script3, 0x00ff00, NULL);
				break;
			}
		}
		break;
	}
}

/**
Handle the update action, moving the object and/or handling any game logic
*/
int circle_x = 0;
void EnemyDisplayableObject::DoUpdate(int iCurrentTime)
{
		m_dX += m_dSX;
		m_dY += m_dSY;
	
		if ((m_dX - 96) < 0)
		{
			m_dX = 95;
			if (m_dSX < 0)
				m_dSX = -m_dSX;
		}
	
		if ((m_dX + m_iStartDrawPosX + m_iDrawWidth + 96) >(GetEngine()->GetWindowWidth()))
		{
			m_dX = GetEngine()->GetWindowWidth() - 96 - 1 - m_iStartDrawPosX - m_iDrawWidth;
			if (m_dSX > 0)
				m_dSX = -m_dSX;
		}
	
		if ((m_dY - 96) < 0)
		{
			m_dY = 95;
			if (m_dSY < 0)
				m_dSY = -m_dSY;
		}
	
		if ((m_dY + m_iStartDrawPosY + m_iDrawHeight + 47) > (GetEngine()->GetWindowHeight()))
		{
			m_dY = GetEngine()->GetWindowHeight() - 47 - 1 - m_iStartDrawPosY - m_iDrawHeight;
			if (m_dSY > 0)
				m_dSY = -m_dSY;
		}
	// Work out current position
	m_iCurrentScreenX = (int)(m_dX + 0.5);
	m_iCurrentScreenY = (int)(m_dY + 0.5);
	
	
	if ((((m_dX + 32) >= m_dX1) && ((m_dX) <= (m_dX1 + 34))) && (((m_dY1 - 32) <= m_dY) && ((m_dY - 34) <= (m_dY1))))
	{
		printf("COLLLIDE");
		m_dSX = -m_dSX;
		m_dSY = -m_dSY;
	}

	GetEngine()->DrawForegroundString(m_iCurrentScreenX-150, m_iCurrentScreenY, "AAAAAAAAAAAAAAA", 0xffffff, NULL);
	// Ensure that the object gets redrawn on the display, if something changed
	RedrawObjects();
}