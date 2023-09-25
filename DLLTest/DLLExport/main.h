#pragma once

// ライブラリで関数を公開するのに必須
// 内部であればその限りではない
#define DLLEXPORT extern "C" __declspec(dllexport)

DLLEXPORT int AddNum(int a, int b);


