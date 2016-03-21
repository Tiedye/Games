#include "D3DManager.h"

D3DManager::D3DManager()
{
}


D3DManager::~D3DManager()
{
}

bool D3DManager::Initialize(int, int, bool, HWND window, bool, float, float)
{
	return false;
}

void D3DManager::Shutdown()
{
}

void D3DManager::BeginScene(float, float, float, float)
{
}

void D3DManager::EndScene()
{
}

ID3D11Device * D3DManager::GetDevice()
{
	return nullptr;
}

ID3D11DeviceContext * D3DManager::GetDeviceContext()
{
	return nullptr;
}

void D3DManager::GetProjectionMatrix(XMMATRIX & matrix)
{
}

void D3DManager::GetWorldMatrix(XMMATRIX & matrix)
{
}

void D3DManager::GetOrthoMatrix(XMMATRIX & matrix)
{
}

void D3DManager::GetVideoCardInfo(char *, int &)
{
}
