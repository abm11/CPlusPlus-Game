#pragma once
#include "BaseEngine.h"
#include "EzyabmTileManager.h"
#include "EzyabmDisplayableObject.h"

class EzyabmEngine :
	public BaseEngine
{
public:
	EzyabmEngine();
	~EzyabmEngine();
	void SetupBackgroundBuffer();
	int InitialiseObjects();
	void Tileupdater();
	void KeyDown(int iKeyCode);

	int MainLoop(void);

	void DrawStringsOnTop();

	void UnDrawStrings();

	void DoUpdate(int iCurrentTime);
	inline BaseEngine* GetEngine() const { return m_pEngine; }

	// State number
	enum State { stateInit, stateMain, statePaused };

	// Work out what this means yourself
	int m_iPauseStarted;

	void RedrawObjects() { m_pEngine->Redraw(false); }
	

private:
	EzyabmTileManager m_oTiles;
	State m_state;

protected:
	BaseEngine * m_pEngine;
	// We expect the sub-class to specify where to draw the object, and where it came from
	// Current position of object on the screen
	int m_iCurrentScreenX;
	int m_iCurrentScreenY;
	// Previous position of object on the screen
	int m_iPreviousScreenX;
	int m_iPreviousScreenY;

	// We expect the sub-class to specify the size of the drawable area, and where, within the drawable area, to draw the object
	// Details of where to actually draw this thing
	// Using these offsets allows moving of the drawn object within the drawing region, without altering the calling code.
	int m_iStartDrawPosX;
	int m_iStartDrawPosY;
	// Size of the object to draw
	int m_iDrawWidth;
	int m_iDrawHeight;

};


