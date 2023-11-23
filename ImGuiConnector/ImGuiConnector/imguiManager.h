//==========================================================
// [imguiManager.h]
//==========================================================

#ifndef __IMGUI_MANAGER_H__
#define __IMGUI_MANAGER_H__

#include <Windows.h>

#include <imgui.h>
#include <d3d12.h>
#include <tchar.h>

#ifdef IMGUICONNECTOR_EXPORTS
#define DLLMODE extern "C" __declspec(dllexport)
#else
#define DLLMODE extern "C" __declspec(dllimport)
#endif // IMGUICONNECTOR_EXPORTS

/// <summary>
/// èâä˙âª
/// </summary>
/// <param name="hwnd"></param>
/// <param name="device"></param>
/// <param name="srvHeap"></param>
/// <param name="numFrame"></param>
/// <returns></returns>
DLLMODE
HRESULT InitImgui(HWND hwnd, ID3D12Device* device, ID3D12DescriptorHeap* srvHeap, int numFrame);

/// <summary>
/// èâä˙âª2
/// </summary>
/// <param name="hwnd"></param>
/// <param name="device"></param>
/// <param name="srvHeap"></param>
/// <param name="numFrame"></param>
/// <returns></returns>
DLLMODE
HRESULT InitImguiB(HWND hwnd, ID3D12Device* device, ID3D12DescriptorHeap* srvHeap, int numFrame);

/// <summary>
/// èIóπèàóù
/// </summary>
DLLMODE
void UninitImgui();

/// <summary>
/// çXêVèàóù
/// </summary>
DLLMODE
void BeginUpdateImgui();

/// <summary>
/// ï`âÊ
/// </summary>
/// <param name="commandList"></param>
/// <param name="srvHeap"></param>
DLLMODE
void DrawImgui(ID3D12GraphicsCommandList* commandList, ID3D12DescriptorHeap* srvHeap);

DLLMODE
ImGuiContext* GetImguiContext();

#endif // !__IMGUI_MANAGER_H__
