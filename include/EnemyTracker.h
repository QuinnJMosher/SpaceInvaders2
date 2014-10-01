#include "Enemy.h"

#ifndef _EnemyTracker_H_
#define _EnemyTracker_H_

class EnemyTracker {
public:
	EnemyTracker();

	int GetDirection();
	void InformOfMove(bool in_shouldChange);
	void EndMoveCycle();

	~EnemyTracker();

private:
	enum DIRECTION {//values for the direction that the enimies are moveing
		LEFT,
		RIGHT,
		DOWN
	};

	DIRECTION direction;
	DIRECTION lastDirection;
	bool changeDirection;

};

#endif