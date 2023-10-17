#pragma once

#include "debugDefine.h"
#include <Singleton.h>

//class  __declspec(dllexport) CDebug //: public Cookie::Singleton<CDebug>
class DLLEXPORT_CLASS CDebug : public Cookie::Singleton<CDebug>
{
private:

public:
	CDebug();
	~CDebug();

	void Init();
	void Uninit();
	void Update();
	void Draw();
	
	/*CDebug()
	{
		printf("debug�R���X�g���N�^\n");
	}

	~CDebug()
	{
		printf("debug�f�X�g���N�^\n");
	}

	void Init()
	{
		printf("debug������\n");
	}

	void Uninit()
	{
		printf("debug�I��\n");
	}

	void Update()
	{
		printf("debug�X�V\n");
	}

	void Draw()
	{
		printf("debug�`��\n");
	}*/

};

