#ifndef _Enemy_H_
#define _Enemy_H_

class Enemy{
public:
	unsigned int iSpriteID;

	float x;
	float y;
	bool active;
		
	bool Move(float fDeltaTime, int direction);
	void draw();
	void colide();
};

#endif