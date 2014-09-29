#include "Enemy.h"
#include "AIE.h"

const float ENEMY_SPEED = 0.125f;
const float ENEMY_SPEED_DOWN = 2.5f;
const int iScreenWidth = 672;

bool Enemy::Move(float fDeltaTime, int direction) {

	if (direction == 0) {//check for direction moved
		x -= (ENEMY_SPEED);
		if (x < 0.0f + 32.0f) {//check if screen edge is reached
			y -= ENEMY_SPEED_DOWN;
			return true;//if we hit a wall then we need to complain about it;
		}
	}
	else if (direction == 1) {
		x += (ENEMY_SPEED);
		if (x >(iScreenWidth - 32.0f)) {
			y -= ENEMY_SPEED_DOWN;
			return true;
		}
	}
	return false;//if we dont hit any walls or move downward the we are fine
}