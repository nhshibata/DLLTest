//==========================================================
// [scene]
// オブジェクトの管理を行う
// 本来は別の名前、構成かもしれないが仮
//==========================================================

#ifndef __SECENE_H__
#define __SECENE_H__

#include <gameObject.h>
#include "gameDefine.h"

// 警告抑止
#pragma warning(disable:4251)

class DLLEXPORT_CLASS CScene
{
private:
	std::vector<Cookie::GameObject*> m_aObject;
	 
public:
	CScene();
	~CScene();

	void AddObject(Cookie::GameObject* obj);

	void PrintList();

	void Uninit();

	std::vector<Cookie::GameObject*> GetList();

	static CScene* Get()
	{
		static CScene instance;
		return &instance;
	}

};

typedef CScene*(GetScene)();

// アプリケーション側からクラスを生成する用
DLLEXPORT CScene* CreateScene(void)
{
	return new CScene;
}

// アプリケーション側からクラスを取得する用
DLLEXPORT CScene* GetInstanceScene(void)
{
	return CScene::Get();
}

DLLEXPORT void ShutdownScene(CScene* pScene)
{
	delete pScene;
}

#endif // !__SECENE_H__
