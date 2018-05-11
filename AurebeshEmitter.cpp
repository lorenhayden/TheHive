#include "AurebeshEmitter.h"

AurebeshEmitter::AurebeshEmitter(LPDIRECT3DDEVICE9 device) : IParticleEmitter()
{
	this->p_font = new AurebeshFont(device);
}

AurebeshEmitter::~AurebeshEmitter()
{
	if (this->p_font) {
		delete this->p_font;
		this->p_font = 0;
	}
}


void AurebeshEmitter::Update(float elapsedTime) {

	static float yposelapsed = elapsedTime;
	yposelapsed += elapsedTime;


	if (this->p_font) {

		if (yposelapsed >= 0.05) {

			yposelapsed = 0.0f;

			this->p_font->Flip();
		}

		LPD3DXVECTOR3 position = this->p_font->GetPosition();
		LPD3DXVECTOR3 velocity = this->p_font->GetVelocity();

		//position->x -= velocity->x;
		position->y += velocity->y;

		this->p_font->Update(elapsedTime);
	}
}

void AurebeshEmitter::Render() {
	if (this->p_font) {
		this->p_font->Render();
	}
}