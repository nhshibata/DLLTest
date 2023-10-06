#ifndef __APPLICATION_DEFINE_H__
#define __APPLICATION_DEFINE_H__


#include <define.h>

// NOTE:反対のはずなのに上手くいく
#ifdef APPLICATION_EXPORTS
// クラスをDLLエクスポート
#define DLLEXPORT_CLASS __declspec(dllexport)
#else
// クラスをDLLインポート
#define DLLEXPORT_CLASS __declspec(dllimport)
#endif // !APPLICATION_EXPORTS


#endif // !__APPLICATION_DEFINE_H__
