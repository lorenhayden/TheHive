#include "D3DSprite.h"


D3DSprite::D3DSprite() {
	
}

D3DSprite::~D3DSprite() {

	if (this->p_sprite) {
		this->p_sprite->Release();
		this->p_sprite = 0;
	}

	if (this->p_texture) {
		this->p_texture->Release();
		this->p_texture = 0;
	}
}

BOOL D3DSprite::Create(HWND hWnd, LPDIRECT3DDEVICE9 device, LPCTSTR texturefile, D3DXVECTOR3 position, RECT bounds, D3DXCOLOR color) {

	//  Set the main window handle
	this->SetHwnd(hWnd);

	// Set the D3DSprite device
	this->SetDevice(device);

	// Set the D3DSprite positiion
	this->SetPosition(position);

	// Set the D3DSprite bounds
	this->SetBounds(bounds);

	// Set the D3DSprite color
	this->SetColor(color);

	// Create the texture from file
	UINT width = (UINT)(bounds.right - bounds.left);
	UINT height = (UINT)(bounds.bottom - bounds.top);

	// Create the texture
	if (this->p_device) {

		int ErrorCode = D3DXCreateTextureFromFileEx(device, texturefile, width, height, D3DX_DEFAULT, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &this->p_texture);
		if ( ErrorCode != D3D_OK ) {
			switch (ErrorCode) {
			case D3DERR_INVALIDCALL: {
				OutputDebugStringW(L"D3DERR_INVALIDCALL");
			}break;
			case D3DERR_NOTAVAILABLE: {
				OutputDebugStringW(L"D3DERR_NOTAVAILABLE");
			}break;
			case D3DERR_OUTOFVIDEOMEMORY: {
				OutputDebugStringW(L"D3DERR_OUTOFVIDEOMEMORY");
			}break;
			case D3DXERR_INVALIDDATA: {
				OutputDebugStringW(L"D3DXERR_INVALIDDATA");
			}break;
			case E_OUTOFMEMORY: {
				OutputDebugStringW(L"E_OUTOFMEMORY");
			}break;
			default:
				OutputDebugStringW(L"UNKNOWN");
			};
			return FALSE;
		}

		// Create the sprite
		ErrorCode = D3DXCreateSprite(device, &this->p_sprite);
		if (ErrorCode != D3D_OK ) {
			switch (ErrorCode) {
			case D3DERR_INVALIDCALL: {
				OutputDebugStringW(L"D3DERR_INVALIDCALL");
			}break;
			case D3DERR_NOTAVAILABLE: {
				OutputDebugStringW(L"D3DERR_NOTAVAILABLE");
			}break;
			case D3DERR_OUTOFVIDEOMEMORY: {
				OutputDebugStringW(L"D3DERR_OUTOFVIDEOMEMORY");
			}break;
			case D3DXERR_INVALIDDATA: {
				OutputDebugStringW(L"D3DXERR_INVALIDDATA");
			}break;
			case E_OUTOFMEMORY: {
				OutputDebugStringW(L"E_OUTOFMEMORY");
			}break;
			default:
				OutputDebugStringW(L"UNKNOWN");
			};
			return FALSE;
		}
	}
	else {
		return FALSE;
	}

	return TRUE;
}
 
void D3DSprite::Draw(float gameTime) {
	RECT rect;
	rect.top = 0;
	rect.left = 0;
	rect.right = GetSystemMetrics(SM_CXSCREEN);
	rect.bottom = GetSystemMetrics(SM_CYSCREEN);

	if (this->p_texture && this->p_sprite) {
		
		this->p_sprite->Begin(D3DXSPRITE_ALPHABLEND);

		this->p_sprite->Draw(this->p_texture, NULL, NULL, &this->m_position, this->m_color);

		this->p_sprite->End();

		this->p_sprite->Flush();
	}
}

void D3DSprite::SetHwnd(HWND hWnd) {
	this->m_hWnd = hWnd;
}
void D3DSprite::SetDevice(LPDIRECT3DDEVICE9 device) {
	this->p_device = device;
}

void D3DSprite::SetPosition(D3DXVECTOR3 position) {
	this->m_position = position;
}

void D3DSprite::SetBounds(RECT bounds) {
	this->m_bounds = bounds;
}

void D3DSprite::SetColor(D3DXCOLOR color) {
	this->m_color = color;
}