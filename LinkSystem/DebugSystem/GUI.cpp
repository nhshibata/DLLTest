#include "pch.h"
#include "GUI.h"
#include <CoreSystem/dllLoader.h>


DLLEXPORT_CLASS GUI::GUI()
	:m_hGameDLL(NULL),m_pProc(nullptr)
{
	
}

DLLEXPORT_CLASS GUI::~GUI()
{
}

DLLEXPORT_CLASS void GUI::Init()
{
	// DLLロード
	m_hGameDLL = LoadDll("GameSystem");

	// 関数ロード
	m_pProc = LoadProc<GetScene>(m_hGameDLL, "GetInstanceScene");
}

DLLEXPORT_CLASS void GUI::Uninit()
{
	FreeDLL(m_hGameDLL);
}

DLLEXPORT_CLASS void GUI::Update()
{

}

DLLEXPORT_CLASS void GUI::Draw()
{
	auto list = m_pProc()->GetList();

	for (auto obj : list)
	{
		obj->Message();
	}
}

DLLEXPORT_CLASS void GUI::EndDraw()
{
}
