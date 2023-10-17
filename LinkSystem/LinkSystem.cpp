// LinkSystem.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

//--- 警告抑止
#define _CRT_SECURE_NO_WARNINGS

//--- インクルード部
#include <Windows.h>
#include <iostream>
#include <typeinfo.h>
#include <map>
#include <string.h>
#include <DebugSystem/debugMain.h>
#include <GameSystem/scene.h>
#include <CoreSystem/dllLoader.h>

//--- 名前空間の展開
using namespace std;

// エントリーポイント
int main()
{
	// 認識用(モジュールを呼び出すことがあるか?)
	// 一括で解放
	std::map<LPCWSTR, HMODULE> modules;

	printf("dll load program\n\n");

	// DLL読み込み
	modules[L"DebugSystem"] = LoadDll("DebugSystem");
	modules[L"GameSystem"] = LoadDll("GameSystem");

	// クラス読み込み
	auto debug = LoadClass<CDebug>(modules[L"DebugSystem"], NAME_TO(CDebug));

	// 関数ポインタ
	GetScene* game = LoadProc<GetScene>(modules[L"GameSystem"], "GetInstanceScene");
	CScene* activeScene = game();

	//auto proc = LoadProc<GUIProc>(m_hGameDLL, "CreateGUI");


	if (debug == NULL || game == NULL)
	{
		printf("error\n");
	}

	// 確認
	debug->Init();
	debug->Update();
	debug->Draw();
	debug->Uninit();


	for (int cnt = 0; cnt < 10; cnt++)
	{
		Cookie::GameObject* obj = new Cookie::GameObject(std::string("obj_" + std::to_string(cnt)));
		activeScene->AddObject(obj);
	}
	activeScene->PrintList();
	//activeScene->Uninit();
	auto list = activeScene->GetList();
	for (auto obj : list)
	{
		delete obj;
	}

	// 読み込んだモジュールの解放
	for (auto hmodule : modules)
	{
		FreeLibrary(hmodule.second);
	}


    std::cout << "Hello World!\n";
	getchar();
	rewind(stdin);

	return 0;
}
