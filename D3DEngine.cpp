#include "D3DEngine.h"

D3DEngine::D3DEngine( HWND hWnd, D3DCOLOR background)
{
	// Initialize the background color
	this->m_background = background;

	// Set the window handle
	this->m_hWnd = hWnd;

	// Get the window rect
	GetWindowRect(hWnd, &m_windowrect);

	// Initialize the game timer
	this->m_bIsTrackingTime = this->m_gameTime.Create();

	// Create the Direct3D Device
	this->m_bIsValidDevice = D3DEngine::Create();
	
	// If device is not valid then release all resources
	if(!this->m_bIsValidDevice) {
		D3DEngine::Release();
	}
}

D3DEngine::~D3DEngine()
{
	D3DEngine::Release();
}

BOOL D3DEngine::Create() {

	HRESULT hr = D3D_OK;

	// Initialie the Direct3D9 Interface
	this->p_d3d = Direct3DCreate9(D3D_SDK_VERSION);

	// Validate the Direct3D9 Interface was created
	if (!this->p_d3d) {
		return FALSE;
	}

	D3DCAPS9 devicecaps;
	ZeroMemory(&devicecaps, sizeof(D3DCAPS9));

	hr = this->p_d3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &devicecaps);

	if (hr != D3D_OK) {
		return FALSE;
	}

	// Intialize the present parameters
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = this->m_hWnd;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferCount = D3DPRESENT_BACK_BUFFERS_MAX;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	
	// Create a Direct3D device using hardware device vertex processing 
	hr = this->p_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, this->m_hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &this->p_device);
	
	if (hr != D3D_OK) {

		// Create a Direct3D device using software device vertex processing 
		hr = this->p_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, this->m_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &this->p_device);

		// Check if the device create fails 
		if (hr != D3D_OK) {
			return FALSE;
		}
	}

	this->p_device->SetRenderState(D3DRS_ZENABLE, TRUE);

	this->p_aurebesh = new AurebeshSystem(this->p_device, 10, 100);

	if (!this->p_aurebesh) {
		return FALSE;
	}

	// Return success!!!!!
	return TRUE;
}

void D3DEngine::Release() {

	if (this->p_aurebesh) {
		delete this->p_aurebesh;
		this->p_aurebesh = 0;
	}
	
	if (this->p_device) {

		// Release the Direct3D9 Device
		this->p_device->Release();

		// Clear the Direct3D9 Device
		this->p_device = 0;
	}

	if (this->p_d3d) {

		// Release the Direct3D9 Interface
		this->p_d3d->Release();

		// Clear the Direct39 Interface
		this->p_d3d = 0;
	}

}

void D3DEngine::Update() {
	
	// Get the next update game time
	if (this->m_bIsTrackingTime == TRUE) {

		//Update the game time
		this->m_gameTime.Update();

		if (this->p_aurebesh) {
			this->p_aurebesh->Update(this->m_gameTime.elapsedGameTime);
		}

	}
}

BOOL D3DEngine::Render() {

	// Validate device 3d
	if (this->p_device != 0) {
		
		// Clear the Direct3D9 Device
		this->p_device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, this->m_background, 1.0f, 0);

		// Start rendering the scene
		this->p_device->BeginScene();

		if (this->p_aurebesh) {
			this->p_aurebesh->Render();
		}

		// End rendering the scene
		this->p_device->EndScene();

		//Present in the scene
		this->p_device->Present(NULL, NULL, NULL, NULL);

		return TRUE;
	}

	return FALSE;
}

BOOL D3DEngine::Reset() {

	// Release the current Direct3D Interfaces
	D3DEngine::Release();

	// Create a new Direct3D Device
	return D3DEngine::Create();
}

BOOL D3DEngine::IsValidDevice() {

	return this->m_bIsValidDevice;
}
