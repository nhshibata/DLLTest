//==========================================================
// [imguiManager.cpp]
//==========================================================

#include "pch.h"
#include "imguiManager.h"

#include <imgui_impl_dx12.h>
#include <imgui_impl_win32.h>


HRESULT InitImgui(HWND hwnd, ID3D12Device* device, ID3D12DescriptorHeap* srvHeap, int numFrame)
{
    HRESULT hr = S_OK;

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);

    {
        D3D12_DESCRIPTOR_HEAP_DESC desc = {};
        desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
        desc.NumDescriptors = 1;
        desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
        hr = device->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&srvHeap));
        if (FAILED(hr))
            return hr;
    }

    return S_OK;
}

HRESULT InitImguiB(HWND hwnd, ID3D12Device* device, ID3D12DescriptorHeap* srvHeap, int numFrame)
{
    bool res = ImGui_ImplDX12_Init(
        device, numFrame,
        DXGI_FORMAT_R8G8B8A8_UNORM, srvHeap,
        srvHeap->GetCPUDescriptorHandleForHeapStart(),
        srvHeap->GetGPUDescriptorHandleForHeapStart());

    if (!res)
    {
        return E_FAIL;
    }

    return S_OK;
}

void UninitImgui()
{
    // Cleanup
    ImGui_ImplDX12_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
}

void BeginUpdateImgui()
{
    // Start the Dear ImGui frame
    ImGui_ImplDX12_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

void DrawImgui(ID3D12GraphicsCommandList* commandList, ID3D12DescriptorHeap* srvHeap)
{
    // コマンドリストの生成と記録開始
    ImGui::Render();

    // ImGuiの描画コマンドをDirectX 12コマンドリストに追加
    // ImGuiの描画データを取得
    ImDrawData* drawData = ImGui::GetDrawData();

    // ImGuiの描画データをDirectX 12コマンドリストに変換
    ImGui_ImplDX12_RenderDrawData(drawData, commandList);


    // CBV_SRV_UAVディスクリプタヒープを設定
    ID3D12DescriptorHeap* heaps[] = { srvHeap };
    commandList->SetDescriptorHeaps(_countof(heaps), heaps);
}

DLLMODE ImGuiContext* GetImguiContext()
{
    return ImGui::GetCurrentContext();
}


