//==========================================================
// [scene]
// �I�u�W�F�N�g�̊Ǘ����s��
// �{���͕ʂ̖��O�A�\����������Ȃ�����
//==========================================================

#ifndef __SECENE_H__
#define __SECENE_H__

#include <gameObject.h>
#include "gameDefine.h"

// �x���}�~
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

// �A�v���P�[�V����������N���X�𐶐�����p
DLLEXPORT CScene* CreateScene(void)
{
	return new CScene;
}

// �A�v���P�[�V����������N���X���擾����p
DLLEXPORT CScene* GetInstanceScene(void)
{
	return CScene::Get();
}

DLLEXPORT void ShutdownScene(CScene* pScene)
{
	delete pScene;
}

#endif // !__SECENE_H__
