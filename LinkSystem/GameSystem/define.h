#ifndef __GAME_DEFINE_H__
#define __GAME_DEFINE_H__


#include <define.h>

// NOTE:���΂̂͂��Ȃ̂ɏ�肭����
#ifdef GAMESYSTEM_EXPORTS
// �N���X��DLL�G�N�X�|�[�g
#define DLLEXPORT_CLASS __declspec(dllexport)
#else
// �N���X��DLL�C���|�[�g
#define DLLEXPORT_CLASS __declspec(dllimport)
#endif // !GAMESYSTEM_EXPORTS


#endif // !__GAME_DEFINE_H__