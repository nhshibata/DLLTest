//#ifndef __DEBUG_DEFINE_H__
//#define __DEBUG_DEFINE_H__


#include <define.h>

// NOTE:反対のはずなのに上手くいく
#ifdef DEBUGSYSTEM_EXPORTS
// クラスをDLLエクスポート
#define DLLEXPORT_CLASS __declspec(dllexport)
#else
// クラスをDLLインポート
#define DLLEXPORT_CLASS __declspec(dllimport)
#endif // !DEBUGSYSTEM_EXPORTS


//#endif // !__DEBUG_DEFINE_H__
