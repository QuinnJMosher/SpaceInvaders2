#include "Enemy.h"
#include "AIE.h"

const float ENEMY_SPEED = 125.f;
const float ENEMY_SPEED_DOWN = 2.5f;
const int iScreenWidth = 672;

bool Enemy::Move(float fDeltaTime, int direction) {

	if (direction == 0) {//check for direction moved
		x -= (ENEMY_SPEED * fDeltaTime);
		if (x < 0.0f + 32.0f) {//check if screen edge is reached
			return true;//if we hit a wall then we need to complain about it;
		}
	} else if (direction == 1) {
		x += (ENEMY_SPEED * fDeltaTime);
		if (x >(iScreenWidth - 32.0f)) {
			return true;
		}
	} else if (direction == 2) {
		y -= ENEMY_SPEED_DOWN;
		return true;//we dont need to track if we hit a wall going down because we will only ever move down once
	}
	return false;//if we dont hit any walls or move downward the we are fine
}

void Enemy::draw() {
	if (active) {
		DrawSprite(iSpriteID);
	}
}

void Enemy::colide() {

}