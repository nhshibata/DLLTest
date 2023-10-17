//==========================================================
// [dllLoader]
// DLL読み込み
// 及び、DLLで定義された関数やクラスの読み込み
//==========================================================


//--- 警告抑止
#define _CRT_SECURE_NO_WARNINGS

#ifndef __DLL_LOADER_H__
#define __DLL_LOADER_H__

//--- インクルード部
#include <iostream>
#include <Windows.h>
#include <string.h>

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

void FreeDLL(HMODULE dll)
{
	FreeLibrary(dll);
}

#endif // !__DLL_LOADER_H__

