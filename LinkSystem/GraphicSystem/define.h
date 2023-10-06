#ifndef __GRAPHICS_DEFINE_H__
#define __GRAPHICS_DEFINE_H__


#include <define.h>

// NOTE:反対のはずなのに上手くいく
#ifdef GRAPHICSYSTEM_EXPORTS
// クラスをDLLエクスポート
#define DLLEXPORT_CLASS __declspec(dllexport)
#else
// クラスをDLLインポート
#define DLLEXPORT_CLASS __declspec(dllimport)
#endif // !GRAPHICSYSTEM_EXPORTS


#endif // !__GRAPHICS_DEFINE_H__
