//#ifndef __DEBUG_DEFINE_H__
//#define __DEBUG_DEFINE_H__


#include <define.h>

// NOTE:���΂̂͂��Ȃ̂ɏ�肭����
#ifdef DEBUGSYSTEM_EXPORTS
// �N���X��DLL�G�N�X�|�[�g
#define DLLEXPORT_CLASS __declspec(dllexport)
#else
// �N���X��DLL�C���|�[�g
#define DLLEXPORT_CLASS __declspec(dllimport)
#endif // !DEBUGSYSTEM_EXPORTS


//#endif // !__DEBUG_DEFINE_H__
