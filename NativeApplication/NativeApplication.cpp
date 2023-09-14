// NativeApplication.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// mono

#pragma comment(lib, "mono-2.0-sgen.lib")
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/object.h>
#include <mono/metadata/appdomain.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/exception.h>
#include <iostream>

int main()
{
	// Moonoのアセンブリと設定ファイルのディレクトリをセットする
	mono_set_dirs("./MonoAssembly/bin/", "./MonoAssembly/etc/");

	// ドメイン(OSにおけるProcessのようなもの
	MonoDomain* domain = nullptr;
	// 初期化
	domain = mono_jit_init("CSScriptTest");

	if (!domain)
	{
		printf("Monoの初期化知っパう\n");
		return 1;
	}

	// 終了処理
	mono_jit_cleanup(domain);

    std::cout << "Hello World!\n";

	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
