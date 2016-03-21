#pragma once

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include <d3d11.h>
#include <DirectXMath.h>
using namespace DirectX;

class D3DManager
{
public:
	D3DManager();
	~D3DManager();

	bool Initialize(int, int, bool, HWND window, bool, float, float);
	void Shutdown();

	void BeginScene(float, float, float, float);
	void EndScene();

	ID3D11Device *GetDevice();
	ID3D11DeviceContext *GetDeviceContext();

	void GetProjectionMatrix(XMMATRIX &matrix);
	void GetWorldMatrix(XMMATRIX &matrix);
	void GetOrthoMatrix(XMMATRIX &matrix);

	void GetVideoCardInfo(char *, int &);

private:
	bool vsync_enabled_;
	int video_card_memory_;
	char video_card_description_[128];
	IDXGISwapChain *swap_chain_;
	ID3D11Device *device_;
	ID3D11DeviceContext *device_context_;
	ID3D11RenderTargetView *render_target_view_;
	ID3D11Texture2D *depth_stencil_buffer_;
	ID3D11DepthStencilState *depth_stencil_state_;
	ID3D11DepthStencilView *depth_stencil_view_;
	ID3D11RasterizerState *raster_state_;
	XMMATRIX projection_matrix_;
	XMMATRIX world_matrix_;
	XMMATRIX ortho_matrix_;
};

