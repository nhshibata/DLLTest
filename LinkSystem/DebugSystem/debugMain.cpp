
#include <pch.h>
#include <stdio.h>
#include "debugMain.h"

DLLEXPORT_CLASS CDebug::CDebug()
{
	printf("debug�R���X�g���N�^\n");
}

DLLEXPORT_CLASS CDebug::~CDebug()
{
	printf("debug�f�X�g���N�^\n");
}

void DLLEXPORT_CLASS CDebug::Init()
{
	printf("debug������\n");
}

void DLLEXPORT_CLASS CDebug::Uninit()
{
	printf("debug�I��\n");
}

void DLLEXPORT_CLASS CDebug::Update()
{
	printf("debug�X�V\n");
}

void DLLEXPORT_CLASS CDebug::Draw()
{
	printf("debug�`��\n");
}
