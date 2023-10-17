#ifndef __GAME_DEFINE_H__
#define __GAME_DEFINE_H__


#include <define.h>

#ifndef DLLEXPORT_CLASS

// NOTE:反対のはずなのに上手くいく
#ifdef GAMESYSTEM_EXPORTS
// クラスをDLLエクスポート
#define DLLEXPORT_CLASS __declspec(dllexport)
#else
// クラスをDLLインポート
#define DLLEXPORT_CLASS __declspec(dllimport)
#endif // !GAMESYSTEM_EXPORTS

#endif // DLLEXPORT_CLASS


#endif // !__GAME_DEFINE_H__
