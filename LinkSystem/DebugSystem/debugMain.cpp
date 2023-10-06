
#include <pch.h>
#include <stdio.h>
#include "debugMain.h"

DLLEXPORT_CLASS CDebug::CDebug()
{
	printf("debugコンストラクタ\n");
}

DLLEXPORT_CLASS CDebug::~CDebug()
{
	printf("debugデストラクタ\n");
}

void DLLEXPORT_CLASS CDebug::Init()
{
	printf("debug初期化\n");
}

void DLLEXPORT_CLASS CDebug::Uninit()
{
	printf("debug終了\n");
}

void DLLEXPORT_CLASS CDebug::Update()
{
	printf("debug更新\n");
}

void DLLEXPORT_CLASS CDebug::Draw()
{
	printf("debug描画\n");
}
