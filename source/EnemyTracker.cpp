#include "EnemyTracker.h"
#include "Enemy.h"
#include "AIE.h"

EnemyTracker::EnemyTracker() {
	this->direction = LEFT;
	this->lastDirection = LEFT;
	this->changeDirection = false;
}

int EnemyTracker::GetDirection() {
	return direction;
}

void EnemyTracker::InformOfMove(bool in_shouldChange) {
	if (in_shouldChange) {
		changeDirection = true;
	}
}

void EnemyTracker::EndMoveCycle() {
	if (changeDirection) {
		if (direction != DOWN) {
			direction = DOWN;
		} else {
			if (lastDirection == LEFT) {
				direction = RIGHT;
				lastDirection = RIGHT;
			} else {
				direction = LEFT;
				lastDirection = LEFT;
			}
		}
		changeDirection = false;
	}
}

EnemyTracker::~EnemyTracker() {

}