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
#include <muth.h>


void ErPrint(MonoObject* excObject)
{
	// 異常なし
	if (!excObject)
		return;

	MonoString* excMsg = mono_object_to_string(excObject, nullptr);
	const char* msg = mono_string_to_utf8(excMsg);
	std::cout << "関数実行時例外" << msg << std::endl;
}

int main()
{
	using namespace std;

	// Moonoのアセンブリと設定ファイルのディレクトリをセットする
	mono_set_dirs("./MonoAssembly/bin/", "./MonoAssembly/etc/");

	// ドメイン(OSにおけるProcessのようなもの)
	MonoDomain* domain = nullptr;
	// 初期化
	domain = mono_jit_init("CSScriptTest");

	if (!domain)
	{
		cout << "Monoの初期化失敗" << endl;
		return 1;
	}

	// 指定のクラスに内部呼び出し対象として登録
	// 上記の処理後でなくては読み取れない
	mono_add_internal_call("CSScript.Class1::Multiply", &Multiply);



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
	MonoClass* typeClass = nullptr;
	mainClass = mono_class_from_name(assemblyImage, "CSScript", "Class1");
	typeClass = mono_class_from_name(assemblyImage, "CSScript", "TypeSizeInfo");
	if (!mainClass || !typeClass)
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
	//methodDesc = mono_method_desc_new("CSScript.Class1::PrintMessage()", true);
	methodDesc = mono_method_desc_new("CSScript.Class1::PrintMessage2()", true);
	
	if (!methodDesc)
	{
		cout << "関数情報の定義作成に失敗" << endl;
		mono_jit_cleanup(domain);
		return 1;
	}

	// スクリプト関数
	MonoMethod* method = nullptr;
	MonoMethod* method2 = nullptr;
	// 関数情報定義をもとに、クラス内の関数を検索
	method = mono_method_desc_search_in_class(methodDesc, mainClass);
	method2 = mono_class_get_method_from_name(typeClass, "StringToSize", 1);// 第3引き数で関数の引き数がいくつか教える
	if (!method)
	{
		cout << "関数取得に失敗" << endl;
		mono_jit_cleanup(domain);
		return 1;
	}
#pragma endregion

#pragma region PROPERTY_LOAD

	cout << "---プロパティを出力確認---\n";
	MonoProperty* prop = nullptr;
	void* ptr = nullptr;
	void* data = nullptr;
	while (prop = mono_class_get_properties(mainClass, &ptr))
	{
		cout << mono_property_get_name(prop) << endl;
		cout << mono_property_get_flags(prop) << endl;

		// methodとしてpropertyを受け取る
		auto pGet = mono_property_get_get_method(prop);
		//auto pSet = mono_property_get_set_method(prop);

		// インスタンスから関数ポインタを通じて実際の値を受け取る
		MonoObject* excObject = nullptr;
		auto pObj = mono_runtime_invoke(pGet, instance, nullptr, &excObject);
		ErPrint(excObject); // エラー処理
		
		// 型サイズ取得
		auto type = mono_signature_get_return_type(
			mono_method_signature(pGet));
		auto typeName = mono_type_get_name(type);
		
		cout << (typeName) << endl;
		
		MonoString* monoTypeName = mono_string_new(domain, typeName);
		void* args[1];
		args[0] = monoTypeName;
		auto pSize = mono_runtime_invoke(method2, nullptr, args, nullptr);
		int size = *(int*)mono_object_unbox(pSize);
		cout << (size) << endl;

		// string用
		//if (mono_type_is_reference(type))
		//{
		//	if (size == -1)
		//	{
		//		data = mono_string_to_utf8((MonoString*)pObj);
		//	}
		//}
		//else
		//{
		//	// 値型であればunbox化する
		//	auto ubx = (MonoObject*)mono_object_unbox(pObj);
		//	memcpy(data, ubx, size);
		//}
		cout << (data) << endl;

	}
	cout << "\n---プロパティ確認終了---\n";

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
