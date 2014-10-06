#include "Bullet.h"
#include "AIE.h"

Bullet::Bullet(float in_x, float in_y) {
	x = in_x;
	y = in_y;

	width = 15;
	height = 30;

	spriteID = CreateSprite(TEXTURE_FILE, width, height, true);

	velocityX = 0.f;
	velocityY = 1000.f;
	MoveSprite(spriteID, x, y);
}

Bullet::Bullet() {
}

Bullet::~Bullet() {

}

void Bullet::Update(float delta) {
	x += velocityX * delta;
	y += velocityY * delta;
	MoveSprite(spriteID, x, y);
}

void Bullet::Draw() {
	DrawSprite(spriteID);
}