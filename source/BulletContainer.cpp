#include "BulletContainer.h"
#include "Bullet.h"
#include <vector>

using namespace std;

BulletContainer::BulletContainer() {
	MaxBullets = 20;
	bullets = vector<Bullet>();
}

BulletContainer::~BulletContainer() {
	bullets.~vector();
}

void BulletContainer::MoveBullets(float in_deltaTime) {
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].Update(in_deltaTime);
	}
	CheckBounds();
}

void BulletContainer::CheckBounds() {
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i].x > /*screen width*/672  + bullets[i].width//beyond the right
			|| bullets[i].x < 0 - bullets[i].width//beyond the left
			|| bullets[i].y > /*screen height*/780 + bullets[i].height//beyond the top
			|| bullets[i].y < 0 - bullets[i].height) {// beyond the bottom

			bullets.erase(bullets.begin() + i);
		}
	}
}

bool BulletContainer::CanAdd() {
	return (MaxBullets > bullets.size());
}

void BulletContainer::AddBullet(float in_x, float in_y) {
	if (CanAdd()) {
		bullets.emplace_back(Bullet(in_x, in_y));
	}
}

void BulletContainer::DrawBullets() {
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].Draw();
	}
}