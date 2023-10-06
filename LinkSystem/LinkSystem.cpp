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

//--- 定数定義
#define NAME_TO(type) #type

//--- 名前空間の展開
using namespace std;

// DLL読み込み
// エラー確認とビルド環境により読み込みファイル切替のため
HMODULE LoadDll(const char* dllName)
{
	char name[256] = "\0";
	strcat(name, dllName);

	// ライブラリの読み込み設定
	// Debugでは拡張子の前にDが付く
#if _DEBUG
	strcat(name, "D.dll");
#else
	strcat(name, ".dll");
#endif // _DEBUG

	cout << "load dll name\n" << name << endl;

	// 読み込み
	auto dll = LoadLibrary(name);

	// dll読み込み確認
	if (!dll)
	{
		cout << "dll load miss" << endl;
	}
	return dll;
}

// DLL関数,クラス読み込み
// エラー確認
template <class T>
T* LoadClass(HMODULE dll, const char* className)
{
	cout << className << "load" << endl;
	// 関数あるいはクラスのインスタンスを取得
	T* instance = (T*)GetProcAddress(dll, className);

	// インスタンス確認
	if (!instance)
	{
		cout << "GetProcAddress is fail" << endl;
	}
	return instance;
}

// DLL関数,クラス読み込み
// エラー確認
template <class T>
T* LoadProc(HMODULE dll, const char* procName)
{
	cout << procName << "load" << endl;
	// 関数あるいはクラスのインスタンスを取得
	T* procInstance = (T*)GetProcAddress(dll, procName);

	// インスタンス確認
	if (!procInstance)
	{
		cout << "GetProcAddress is fail" << endl;
	}
	return procInstance;
}

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
	typedef CScene*(Game)();
	auto game = LoadProc<Game>(modules[L"GameSystem"], "CreateScene");
	CScene* activeScene = game();

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
	delete activeScene;

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
