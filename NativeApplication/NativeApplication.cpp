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
	using namespace std;
	// Moonoのアセンブリと設定ファイルのディレクトリをセットする
	mono_set_dirs("./MonoAssembly/bin/", "./MonoAssembly/etc/");

	// ドメイン(OSにおけるProcessのようなもの
	MonoDomain* domain = nullptr;
	// 初期化
	domain = mono_jit_init("CSScriptTest");

	if (!domain)
	{
		cout << "Monoの初期化失敗" << endl;
		return 1;
	}

#pragma region AssemblyLoad

	// スクリプトのアセンブリ(中間言語の状態に変換したC#)
	MonoAssembly* assembly = nullptr;
	// スクリプトのアセンブリ(DLL)をロード
	assembly = mono_domain_assembly_open(domain, ".\\CSScript.dll");
	if (!assembly)
	{
		cout << "スクリプトのアセンブリのロードに失敗" << endl;
		mono_jit_cleanup(domain);
		return 1;
	}

	// アセンブリのイメージ(アセンブリ内のコード情報を実際に保持している物)
	MonoImage* assemblyImage = nullptr;
	assemblyImage = mono_assembly_get_image(assembly);
	if (!assemblyImage)
	{
		cout << "スクリプトのアセンブリイメージの取得に失敗" << endl;
		mono_jit_cleanup(domain);
		return 1;
	}
#pragma endregion

#pragma region CLASS_LOAD
	// クラスの型
	MonoClass* mainClass = nullptr;
	mainClass = mono_class_from_name(assemblyImage, "CSScript", "Class1");
	if (!mainClass)
	{
		cout << "クラスの型取得に失敗" << endl;
		mono_jit_cleanup(domain);
		return 1;
	}

	// クラスのインスタンスを作成
	MonoObject* instance = nullptr;
	instance = mono_object_new(domain, mainClass);
	if (!instance)
	{
		cout << "クラスのインスタンス生成に失敗" << endl;
		mono_jit_cleanup(domain);
		return 1;
	}

#pragma endregion


#pragma region CLASS_FUNC
	// 関数情報読み込み
	MonoMethodDesc* methodDesc = nullptr;
	methodDesc = mono_method_desc_new("CSScript.Class1::PrintMessage()", true);
	if (!methodDesc)
	{
		cout << "関数情報の定義作成に失敗" << endl;
		mono_jit_cleanup(domain);
		return 1;
	}

	// スクリプト関数
	MonoMethod* method = nullptr;
	// 関数情報定義をもとに、クラス内の関数を検索
	method = mono_method_desc_search_in_class(methodDesc, mainClass);
	if (!method)
	{
		cout << "関数取得に失敗" << endl;
		mono_jit_cleanup(domain);
		return 1;
	}
#pragma endregion

	// 関数呼び出し
	// 関数実行時の例外情報受け取り
	MonoObject* excObject = nullptr;
	mono_runtime_invoke(method, instance, nullptr, &excObject);
	// 異常受け取り
	if (excObject)
	{
		MonoString* excMsg = mono_object_to_string(excObject, nullptr);
		const char* msg = mono_string_to_utf8(excMsg);
		cout << "関数実行時例外" << msg << endl;
		mono_jit_cleanup(domain);
		return 1;
	}


	// 終了処理
	mono_jit_cleanup(domain);

	cout << "\nこの上にC#で指定した文字\n";
	cout << "この下にC++で指定した文字\n";
    cout << "Hello World!\n";

	getchar();
	rewind(stdin);

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
