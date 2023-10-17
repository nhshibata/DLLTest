//==========================================================
// [dllLoader]
// DLL�ǂݍ���
// �y�сADLL�Œ�`���ꂽ�֐���N���X�̓ǂݍ���
//==========================================================


//--- �x���}�~
#define _CRT_SECURE_NO_WARNINGS

#ifndef __DLL_LOADER_H__
#define __DLL_LOADER_H__

//--- �C���N���[�h��
#include <iostream>
#include <Windows.h>
#include <string.h>

//--- �萔��`
#define NAME_TO(type) #type

//--- ���O��Ԃ̓W�J
using namespace std;

// DLL�ǂݍ���
// �G���[�m�F�ƃr���h���ɂ��ǂݍ��݃t�@�C���ؑւ̂���
HMODULE LoadDll(const char* dllName)
{
	char name[256] = "\0";
	strcat(name, dllName);

	// ���C�u�����̓ǂݍ��ݐݒ�
	// Debug�ł͊g���q�̑O��D���t��
#if _DEBUG
	strcat(name, "D.dll");
#else
	strcat(name, ".dll");
#endif // _DEBUG

	cout << "load dll name\n" << name << endl;

	// �ǂݍ���
	auto dll = LoadLibrary(name);

	// dll�ǂݍ��݊m�F
	if (!dll)
	{
		cout << "dll load miss" << endl;
	}
	return dll;
}

// DLL�֐�,�N���X�ǂݍ���
// �G���[�m�F
template <class T>
T* LoadClass(HMODULE dll, const char* className)
{
	cout << className << "load" << endl;
	// �֐����邢�̓N���X�̃C���X�^���X���擾
	T* instance = (T*)GetProcAddress(dll, className);

	// �C���X�^���X�m�F
	if (!instance)
	{
		cout << "GetProcAddress is fail" << endl;
	}
	return instance;
}

// DLL�֐�,�N���X�ǂݍ���
// �G���[�m�F
template <class T>
T* LoadProc(HMODULE dll, const char* procName)
{
	cout << procName << "load" << endl;
	// �֐����邢�̓N���X�̃C���X�^���X���擾
	T* procInstance = (T*)GetProcAddress(dll, procName);

	// �C���X�^���X�m�F
	if (!procInstance)
	{
		cout << "GetProcAddress is fail" << endl;
	}
	return procInstance;
}

void FreeDLL(HMODULE dll)
{
	FreeLibrary(dll);
}

#endif // !__DLL_LOADER_H__

