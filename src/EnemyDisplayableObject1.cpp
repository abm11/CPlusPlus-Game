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

#include <thread>
#include <chrono>
using namespace std;

int m_dSX1 = 2;
int m_dSY1 = 0;

EnemyDisplayableObject1::EnemyDisplayableObject1(BaseEngine* pEngine) :
DisplayableObject(pEngine)
{

	// Start point on screen
	m_iCurrentScreenX = m_iPreviousScreenX = 300;
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

EnemyDisplayableObject1::~EnemyDisplayableObject1()
{
}

char scriptnew0[] = "'RARR'";
char scriptnew1[] = "'BOO'";
char scriptnew2[] = "'SP00KY'";
char scriptnew3[] = "'AGH'";
int random1;
time_t end1 = time(NULL);

void EnemyDisplayableObject1::Draw()
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

			if (end1 < start)
			{
				end1 = (end1 + 1);
				cout << end1;
				random1 = rand() % 4;

			}

			switch (random1) {
			case 0:
				GetEngine()->DrawForegroundString(m_dX1, m_dY1 - 25, scriptnew0, 0x00ff00, NULL);
				break;
			case 1:
				GetEngine()->DrawForegroundString(m_dX1, m_dY1 - 25, scriptnew1, 0x00ff00, NULL);
				break;
			case 2:
				GetEngine()->DrawForegroundString(m_dX1, m_dY1 - 25, scriptnew2, 0x00ff00, NULL);
				break;
			case 3:
				GetEngine()->DrawForegroundString(m_dX1, m_dY1 - 25, scriptnew3, 0x00ff00, NULL);
				break;
			}
		}
		break;
	}
}

/**
Handle the update action, moving the object and/or handling any game logic
*/


void EnemyDisplayableObject1::DoUpdate(int iCurrentTime)
{
	m_dX1 += m_dSX1;
	m_dY1 += m_dSY1;

	//Left
	if ((m_dX1 - 96) < 0)
	{
		m_dX1 = 95;
		if (m_dSX1 < 0) {
			m_dSX1 = 0;
			m_dSY1 = 2;
		}
	}

	//Right
	if ((m_dX1 + m_iStartDrawPosX + m_iDrawWidth + 96) >(GetEngine()->GetWindowWidth()))
	{
		m_dX1 = GetEngine()->GetWindowWidth() - 96 - 1 - m_iStartDrawPosX - m_iDrawWidth;
		if (m_dSX1 > 0)
			m_dSX1 = 0;
			m_dSY1 = -2;

	}

	//Top
	if ((m_dY1 - 96) < 0)
	{
		m_dY1 = 95;
		if (m_dSY1 < 0) {
			m_dSY1 = 0;
			m_dSX1 = -2;
		}
	}

	//Bottom
	if ((m_dY1 + m_iStartDrawPosY + m_iDrawHeight + 47) >(GetEngine()->GetWindowHeight()))
	{
		m_dY1 = GetEngine()->GetWindowHeight() - 47 - 1 - m_iStartDrawPosY - m_iDrawHeight;
		if (m_dSY1 > 0) {
			m_dSY1 = 0;
			m_dSX1 = 2;
		}
	}

	// Work out current position
	m_iCurrentScreenX = (int)(m_dX1 + 0.5);
	m_iCurrentScreenY = (int)(m_dY1 + 0.5);

	//if (!((m_dX+60) < m_dX1) || ((m_dX-60) > m_dX1)) {
	//	printf("COLLLIDE");
	//	m_dSX1 = -m_dSX1;
	//	m_dSY1 = -m_dSY1;
	//}

	if ((((m_dX + 32) >= m_dX1) && ((m_dX) <= (m_dX1 + 34))) && (((m_dY1 - 32) <= m_dY) && ((m_dY - 34) <= (m_dY1))))
	{
		printf("COLLLIDE");
		m_dSX1 = -m_dSX1;
		m_dSY1 = -m_dSY1;
	}


	// Ensure that the object gets redrawn on the display, if something changed
	RedrawObjects();
}