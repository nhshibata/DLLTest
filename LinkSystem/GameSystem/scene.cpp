#include "pch.h"
#include "scene.h"


DLLEXPORT_CLASS CScene::CScene()
{
}

DLLEXPORT_CLASS CScene::~CScene()
{
}

void DLLEXPORT_CLASS CScene::AddObject(Cookie::GameObject * obj)
{
	m_aObject.push_back(obj);
}

void DLLEXPORT_CLASS CScene::PrintList()
{
	for (auto obj : m_aObject)
	{
		obj->Message();
		printf("\n");
	}
}

void DLLEXPORT_CLASS CScene::Uninit()
{
	printf("objects release start\n");

	for (auto obj : m_aObject)
	{
		delete obj;
	}
	m_aObject.clear();
}

std::vector<Cookie::GameObject*> DLLEXPORT_CLASS CScene::GetList()
{
	return m_aObject;
}

