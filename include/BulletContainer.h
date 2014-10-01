#include <vector>
#include "Bullet.h"

#ifndef _BulletContainer_h_
#define _BulletContainer_h_

class BulletContainer {
public:
	BulletContainer();
	~BulletContainer();

	void MoveBullets(float in_deltaTime);
	void CheckBounds();
	bool CanAdd();
	void AddBullet(float in_x, float in_y);
	void DrawBullets();

private:
	std::vector<Bullet> bullets;
	int MaxBullets;
};

#endif