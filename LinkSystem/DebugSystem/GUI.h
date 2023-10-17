//==========================================================
// [GUI]
// GUI�Ƃ��Ĉ���
//==========================================================

#ifndef __GUI_H__
#define __GUI_H__

#include "debugDefine.h"
#include <GameSystem/scene.h>

class DLLEXPORT_CLASS GUI
{
private:
	HMODULE m_hGameDLL;
	GetScene *m_pProc;
public:
	GUI();
	~GUI();

	void Init();
	void Uninit();
	void Update();
	void Draw();
	void EndDraw();
};

// �֐��|�C���^
typedef GUI*(GUIProc)();

DLLEXPORT GUI* CreateGUI()
{
	return new GUI();
}

DLLEXPORT void ShutdownGUI(GUI* pGUI)
{
	delete pGUI;
}

#endif // !__GUI_H__

