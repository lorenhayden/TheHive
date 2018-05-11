#include "AurebeshFont.h"

AurebeshFont::AurebeshFont(LPDIRECT3DDEVICE9 device)
{

	// Set the default character string that the 
	this->m_text = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz01233456789";

	// Intialize the font size random range generator
	this->p_irFontSize = new IntegerRange(8, 40);

	// Create the new D3DFont with default settings
	this->p_font = new D3DFont(device, 
															this->p_irFontSize->GetNext(), 
															FALSE, 
															FALSE, 
															L"Aurebesh", 
															&D3DXVECTOR3(0.0f, 0.0f, 0.0f), 
															&D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 
															""
														);

#if _DEBUG
	RECT rect;
	rect.top = 0;
	rect.left = 0;
	rect.right = GetSystemMetrics(SM_CXSCREEN);
	rect.bottom = GetSystemMetrics(SM_CYSCREEN);
	this->SetBounds(&rect);
#else
	RECT rect;
	rect.top = GetSystemMetrics(SM_XVIRTUALSCREEN);
	rect.left = GetSystemMetrics(SM_YVIRTUALSCREEN);
	rect.right = GetSystemMetrics(SM_CXVIRTUALSCREEN);
	rect.bottom = GetSystemMetrics(SM_CYVIRTUALSCREEN);
	this->SetBounds(&rect);
#endif

	//Get the min and max x position values for the random generator
#if _DEBUG
	float xmin = 0;
	float xmax = (float)GetSystemMetrics(SM_CXSCREEN);
#else
	float xmin = (float)GetSystemMetrics(SM_XVIRTUALSCREEN);
	float xmax = (float)GetSystemMetrics(SM_CXVIRTUALSCREEN);
#endif

	// Intialize the float range random generator
	this->p_frXPos = new FloatRange(xmin, xmax);

#if _DEBUG
	float ymin = 0;
	float ymax = (float)GetSystemMetrics(SM_CYSCREEN);
#else
	float ymin = (float)GetSystemMetrics(SM_YVIRTUALSCREEN);
	float ymax = (float)GetSystemMetrics(SM_CYVIRTUALSCREEN);
#endif

	this->p_frYPos = new FloatRange(ymin, ymax);

	// Intialize the integer range random geneator
	this->p_irStartCharacterIndex = new IntegerRange(0, this->m_text.length() - 1);

	// Initialize the velocity random range generator
	this->p_frVelocity = new FloatRange(1.0f, 10.0f);

	// Intialize the color random range generator
	this->p_crFontColor = new ColorRange(&D3DXCOLOR(0.3686f, 0.6823f, 0.8f, 0.5f), &D3DXCOLOR(0.3686f, 0.6823f, 1.0f, 1.0f));

	// Spawn the random generated values
	this->Default();
}

AurebeshFont::~AurebeshFont()
{
	// Release the x position float range random generator
	if (this->p_frXPos) {
		delete this->p_frXPos;
		this->p_frXPos = 0;
	}

	// Release the y position float range random generator
	if (this->p_frYPos) {
		delete this->p_frYPos;
		this->p_frYPos = 0;
	}

	// Release the velocity range random generator
	if (this->p_frVelocity) {
		delete this->p_frVelocity;
		this->p_frVelocity = 0;
	}

	// Release the character start index integer range random generator
	if (this->p_irStartCharacterIndex) {
		delete this->p_irStartCharacterIndex;
		this->p_irStartCharacterIndex = 0;
	}

	// Release the font size range random generator
	if (this->p_irFontSize) {
		delete this->p_irFontSize;
		this->p_irFontSize = 0;
	}

	// Release the font color range random generator
	if (this->p_crFontColor) {
		delete this->p_crFontColor;
		this->p_crFontColor = 0;
	}

	// Release the D3DFont
	if (this->p_font) {
		delete this->p_font;
		this->p_font = 0;
	}
}

void AurebeshFont::Update(float elsapedTime) {
	
	// If is alive then set the values
	if (this->IsAlive() == TRUE) {
		if (this->p_font) {
			this->p_font->SetPosition(this->GetPosition());
			this->p_font->SetColor(this->GetColor());
			this->p_font->SetText(this->m_character);
		}
	}
	else {
		// Respawn font if the alive flag is false
		this->ReSpawn();
	}
}

void AurebeshFont::Render() {
	if (this->p_font) {
		this->p_font->Draw();
	}
}

BOOL AurebeshFont::IsAlive() {
	LPRECT bounds = this->GetBounds();
	LPD3DXVECTOR3 position = this->GetPosition();

	INT xpos = (INT)position->x;
	INT ypos = (INT)position->y;

	// Check to see if the font has gone off the screen on x-coordinates
	if (xpos < bounds->left || xpos > bounds->right) {
		return FALSE;
	}

	// Check to see if the font has gone off the screen on y-coordinates
	if (ypos < bounds->top || ypos > bounds->bottom) {
		return FALSE;
	}
	
	return TRUE;
}

void AurebeshFont::Flip() {
	INT length = (INT)this->m_text.length();

	this->m_nStartIndex += 1;

	if (this->m_nStartIndex > length - 1) {
		this->m_nStartIndex = 0;
	}

	this->m_character = this->m_text.substr(this->m_nStartIndex, 1);
}

void AurebeshFont::Default() {
	float newx = this->p_frXPos->GetNext();
	float newy = this->p_frYPos->GetNext();
	float newxvelocity = this->p_frVelocity->GetNext();
	float newyvelocity = this->p_frVelocity->GetNext();
	int newstartindex = this->p_irStartCharacterIndex->GetNext();
	LPD3DXCOLOR newcolor = this->p_crFontColor->GetNext();
	newcolor->r = 0.3686f;
	newcolor->g = 0.6823f;
	newcolor->b = 0.8f;
	this->m_character = this->m_text.substr(newstartindex, 1);
	this->m_nStartIndex = newstartindex;
	this->SetPosition(&D3DXVECTOR3(newx, newy, 0.0f));
	this->SetVelocity(&D3DXVECTOR3(newxvelocity, newyvelocity, 0.0f));
	this->SetColor(newcolor);
}

void AurebeshFont::ReSpawn() {
	float newx = this->p_frXPos->GetNext();
	float newy = 0.0f;
	float newxvelocity = this->p_frVelocity->GetNext();
	float newyvelocity = this->p_frVelocity->GetNext();
	int newstartindex = this->p_irStartCharacterIndex->GetNext();
	LPD3DXCOLOR newcolor = this->p_crFontColor->GetNext();
	newcolor->r = 0.3686f;
	newcolor->g = 0.6823f;
	newcolor->b = 0.8f;
	this->m_character = this->m_text.substr(newstartindex, 1);
	this->m_nStartIndex = newstartindex;
	this->SetPosition(&D3DXVECTOR3(newx, newy, 0.0f));
	this->SetVelocity(&D3DXVECTOR3(newxvelocity, newyvelocity, 0.0f));
	this->SetColor(newcolor);
}
