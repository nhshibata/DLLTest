// DllLoder.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <Windows.h>
#include <iostream>

int main()
{
	using namespace std;

	std::cout << "Hello World!\n";

	HINSTANCE hDLL;
	int(*AddNum)(int, int);// 関数へのﾎﾟｲﾝﾀ
	int ans = 0;
	//hDLL = LoadLibrary(".././Release/Dllexport.dll"); // 
	hDLL = LoadLibrary("Dllexport.dll"); // 

	if (!hDLL)
	{
		cout << "dll load miss" << endl;
	}
	else if (!(AddNum = (int(*)(int, int))GetProcAddress(hDLL, "AddNum")))
	{
		cout << "GetProcAddress is fail" << endl;
	}
	else
	{
		ans = AddNum(2, 3);
		cout << ans << endl;
		cout << "success" << endl;
		FreeLibrary(hDLL);
	}

	cout << "end" << endl;

	getchar();
	rewind(stdin);

	return 0;

}
