
#ifndef __SECENE_H__
#define __SECENE_H__

#include <gameObject.h>
#include "define.h"

// åxçêó}é~
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
};

DLLEXPORT CScene* CreateScene(void)
{
	return new CScene;
}

#endif // !__SECENE_H__
