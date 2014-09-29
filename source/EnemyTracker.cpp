#include "EnemyTracker.h"
#include "Enemy.h"
#include "AIE.h"

EnemyTracker::EnemyTracker() {
	this->direction = LEFT;
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

			if (direction == LEFT) {
				direction = RIGHT;
			} else {
				direction = LEFT;
			}

	}
}

EnemyTracker::~EnemyTracker() {

}