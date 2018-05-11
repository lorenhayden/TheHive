#include "D3DFont.h"

D3DFont::D3DFont() : IGameObject() {

}

D3DFont::D3DFont(const LPDIRECT3DDEVICE9 device, const INT size, const BOOL bold, const BOOL italics, LPCWSTR family, const LPD3DXVECTOR3 position, const LPD3DXCOLOR color, std::string text) :
	IGameObject(device,position,&D3DXVECTOR3(0.0f,0.0f,0.0f),0,color,0.0f)
{
	this->SetSize(size);
	this->SetBold(bold);
	this->SetItalics(italics);
	this->SetFamily(family);
	this->SetText(text);

	INT weight = (bold == TRUE) ? FW_BOLD : FW_NORMAL;

	HRESULT hr = D3DXCreateFont(
		device
		, size
		, 0
		, weight
		, 1
		, m_italics
		, DEFAULT_CHARSET
		, OUT_DEFAULT_PRECIS
		, ANTIALIASED_QUALITY
		, DEFAULT_PITCH | FF_DONTCARE
		, this->m_family
		, &this->p_font
	);
}

D3DFont::~D3DFont()
{
	if (this->m_family) {
		free(this-> m_family);
		this->m_family = 0;
	}

	if (this->p_font) {
		this->p_font->Release();
		this->p_font = 0;
	}
}

void D3DFont::SetSize(const INT size) {
	this->m_size = size;
}

void D3DFont::SetBold(const BOOL bold) {
	this->m_bold = bold;
}

void D3DFont::SetItalics(const BOOL italics) {
	this->m_italics = italics;
}

void D3DFont::SetFamily(LPCWSTR family) {

	if (this->m_family) {
		free(this->m_family);
		this->m_family = 0;
	}

	size_t size = wcslen(family) * sizeof(wchar_t);
	this->m_family = (wchar_t*)calloc(size+1, size+1);
	wcscpy_s(this->m_family, size, family);
}

void D3DFont::SetText(std::string text) {
	this->m_text = text;
}

void D3DFont::Update(float gameTime) {

}

void D3DFont::Draw() {
	RECT rect = { 0,0,0,0 };
	LPD3DXVECTOR3 position = this->GetPosition();
	LPD3DXCOLOR color = this->GetColor();

	if (this->p_font) {

		// Get the rect size of the text that will be rendered
		this->p_font->DrawTextA(NULL, (LPCSTR)this->m_text.c_str(), strlen(this->m_text.c_str()), &rect, DT_CALCRECT, *color);

		this->SetBounds(&rect);

		rect.top = (int)position->y;
		rect.left = (int)position->x;
		rect.bottom = (int)position->y + rect.bottom;
		rect.right = (int)position->x + rect.right;

		// Render the text to the screen
		this->p_font->DrawTextA(NULL, (LPCSTR)this->m_text.c_str(), strlen(this->m_text.c_str()), &rect, DT_LEFT | DT_WORDBREAK, *color);
	}
}

void D3DFont::SetDevice(const LPDIRECT3DDEVICE9 device) {
	IGameObject::SetDevice(device);
}

LPDIRECT3DDEVICE9 D3DFont::GetDevice() {
	return IGameObject::GetDevice();
}

void D3DFont::SetPosition(const LPD3DXVECTOR3 position) {
	return IGameObject::SetPosition(position);
}

LPD3DXVECTOR3 D3DFont::GetPosition() {
	return IGameObject::GetPosition();
}

void D3DFont::SetVelocity(const LPD3DXVECTOR3 velocity) {
	IGameObject::SetVelocity(velocity);
}

LPD3DXVECTOR3 D3DFont::GetVelocity() {
	return IGameObject::GetVelocity();
}

void D3DFont::SetBounds(const LPRECT bounds) {
	IGameObject::SetBounds(bounds);
}

LPRECT D3DFont::GetBounds() {
	return IGameObject::GetBounds();
}

void D3DFont::SetColor(const LPD3DXCOLOR color) {
	IGameObject::SetColor(color);
}

LPD3DXCOLOR D3DFont::GetColor() {
	return IGameObject::GetColor();
}