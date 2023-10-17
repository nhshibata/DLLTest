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
		printf("debugコンストラクタ\n");
	}

	~CDebug()
	{
		printf("debugデストラクタ\n");
	}

	void Init()
	{
		printf("debug初期化\n");
	}

	void Uninit()
	{
		printf("debug終了\n");
	}

	void Update()
	{
		printf("debug更新\n");
	}

	void Draw()
	{
		printf("debug描画\n");
	}*/

};

