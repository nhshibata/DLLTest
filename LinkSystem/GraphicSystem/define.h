#ifndef __GRAPHICS_DEFINE_H__
#define __GRAPHICS_DEFINE_H__


#include <define.h>

// NOTE:���΂̂͂��Ȃ̂ɏ�肭����
#ifdef GRAPHICSYSTEM_EXPORTS
// �N���X��DLL�G�N�X�|�[�g
#define DLLEXPORT_CLASS __declspec(dllexport)
#else
// �N���X��DLL�C���|�[�g
#define DLLEXPORT_CLASS __declspec(dllimport)
#endif // !GRAPHICSYSTEM_EXPORTS


#endif // !__GRAPHICS_DEFINE_H__
