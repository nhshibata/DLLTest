#ifndef __APPLICATION_DEFINE_H__
#define __APPLICATION_DEFINE_H__


#include <define.h>

// NOTE:���΂̂͂��Ȃ̂ɏ�肭����
#ifdef APPLICATION_EXPORTS
// �N���X��DLL�G�N�X�|�[�g
#define DLLEXPORT_CLASS __declspec(dllexport)
#else
// �N���X��DLL�C���|�[�g
#define DLLEXPORT_CLASS __declspec(dllimport)
#endif // !APPLICATION_EXPORTS


#endif // !__APPLICATION_DEFINE_H__
