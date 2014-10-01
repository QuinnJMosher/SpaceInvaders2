#ifndef _Bullet_h_
#define _Bullet_h_

class Bullet
{
public:
	Bullet(float in_x, float in_y);
	Bullet();
	~Bullet();

	float x;
	float y;

	float width;
	float height;

	unsigned int spriteID;

	float velocityX;
	float velocityY;

	void Update(float delta);
	void Draw();

	const char* TEXTURE_FILE = "./images/invaders/invaders_5_00.png";
};

#endif