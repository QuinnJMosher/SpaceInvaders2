#include "AIE.h"
#include <iostream>
#include "PlayerCannon.h"
#include "Enemy.h"
#include "EnemyTracker.h"
#include "Bullet.h"
#include "BulletContainer.h"

//constants
const int ScreenWidth = 672;
const int ScreenHeight = 780;

const int enemyArrLength = 24;
const int enemyArrRows = 4;
const int enemyArrCols = 6;

const char* pInvadersFont = "./fonts/invaders.fnt";

//prototypes 
void UpdateMainMenu();
void DrawGameState();
void UpdateGameState(float deltaTime);
void CreateEnemies();
void MoveEnemies(float deltaTime);
void ResetEnemies();

//states 
enum GAMESTATES
{
	MAIN_MENU,
	GAMEPLAY,
	END
};

//sprite vars
unsigned int iArcadeMarquee;

enum DIRECTION {//values for the direction that the enimies are moveing
	LEFT,
	RIGHT,
	DOWN
};

DIRECTION enemyDirection;
DIRECTION nextDirection;
Enemy alienShips[enemyArrLength];
EnemyTracker enemyTracker;
BulletContainer bullets;

float fireInteval = 0;

PlayerCannon player;


int main( int argc, char* argv[] )
{	

	Initialise(ScreenWidth, ScreenHeight, false, "Space Invaders");
    
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));

	//player settings
	player.SetSize(64.0f, 32.0f);
	player.iSpriteID = CreateSprite("./images/cannon.png", player.fWidth, player.fHeight, true);
	player.SetMovementExtremes(0.0f, ScreenWidth);
	player.SetMovementKeys(65, 68);
	player.x = ScreenWidth * 0.5f;
	player.y = 88.0f;

	//startPlayerTracker
	enemyTracker = EnemyTracker();
	//ready bullets
	bullets = BulletContainer();


	//create Marquee sprite
	iArcadeMarquee = CreateSprite("./images/Space-Invaders-Marquee.png", ScreenWidth, ScreenHeight, true);

	//enemy creation
	CreateEnemies();
	enemyDirection = RIGHT;
	nextDirection = RIGHT;

	//font setting
	AddFont(pInvadersFont);

	//game state declaration
	GAMESTATES eCurrentState = MAIN_MENU;

    //Game Loop
    do
    {
		float fDeltaT = GetDeltaTime();

		switch (eCurrentState) {
		case MAIN_MENU:

			UpdateMainMenu();

			//input
			if (IsKeyDown(257) && !IsKeyDown(256)) {
				eCurrentState = GAMEPLAY;
				ResetEnemies();
			}

			break;

		case GAMEPLAY:

			UpdateGameState(fDeltaT);
			DrawGameState();

			//ChangeState
			if (IsKeyDown(256)) {
				eCurrentState = MAIN_MENU;
			}

			break;

		case END:
			break;

		default:
			break;
		}

		//clear screen
		ClearScreen();


    } while(!FrameworkUpdate());

	Shutdown();

    return 0;
}

void UpdateMainMenu() {
	//purty tings
	MoveSprite(iArcadeMarquee, ScreenWidth / 2, ScreenHeight / 2);
	DrawSprite(iArcadeMarquee);

	//text
	SetFont(pInvadersFont);
	DrawString("INSERT COINS", ScreenWidth * 0.37f, ScreenHeight * 0.5f);
	DrawString("00", ScreenWidth* (0.37f + 0.1f), ScreenHeight * 0.45f);

}

void UpdateGameState(float deltaTime) {

	if (fireInteval > 0)  {
		fireInteval -= deltaTime;
	} else {
		if (IsKeyDown(' ') && bullets.CanAdd()) {
			bullets.AddBullet(player.x, player.y + (player.fHeight / 2));
			fireInteval += 0.36f;
		}
	}

	player.Move(deltaTime, 300.f);
	MoveEnemies(deltaTime);
	bullets.MoveBullets(deltaTime);
	
}

void DrawGameState() {
	//draw sprites
	DrawSprite(player.iSpriteID);
	bullets.DrawBullets();

	for (int i = 0; i < enemyArrLength; i++) {
		DrawSprite(alienShips[i].iSpriteID);
	}

	DrawLine(0, 40, ScreenWidth, 40, SColour(0x00, 0xFC, 0x00, 0xFF)); //doesn't acctually draw anything?

	//drawstrings
	SetFont(pInvadersFont);
	DrawString("SCORE < 1 >", ScreenWidth * 0.025f, ScreenHeight - 2);
	DrawString("0000", ScreenWidth * 0.11f, ScreenHeight - 32);
	DrawString("HI-SCORE", ScreenWidth * 0.35f, ScreenHeight - 2);
	DrawString("0020", ScreenWidth * (0.05f + 0.35f), ScreenHeight - 32);
	DrawString("SCORE < 2 >", ScreenWidth * 0.65f, ScreenHeight - 2);
	DrawString("0000", ScreenWidth * (0.05f + 0.65f), ScreenHeight - 32);
}

void CreateEnemies() {
	float fEnemyX = ScreenWidth * 0.2f;// prepare start variables	
	float fEnemyY = ScreenHeight * 0.7f;

	int iteration = 0;
	for (int i = 0; i < enemyArrRows; i++) {// double loops to get to the multiple arrays
		for (int j = 0; j < enemyArrCols; j++) {
			alienShips[iteration].iSpriteID = CreateSprite("./images/invaders/invaders_1_00.png", 64, 62, true);//create
			alienShips[iteration].x = fEnemyX;// set the x and y values in their proper place based on the screen and sprite sizes
			alienShips[iteration].y = fEnemyY;
			MoveSprite(alienShips[iteration].iSpriteID, alienShips[iteration].x, alienShips[iteration].y);//put in positions
			fEnemyX += 0.12f * ScreenWidth; //change position for next iteration
			iteration++;
		}
		fEnemyY -= 0.1f * ScreenHeight;//change height
		fEnemyX = ScreenWidth * 0.2f;//reset x value
	}

	enemyDirection = RIGHT;
}

void ResetEnemies() {
	enemyDirection = RIGHT;
	float fEnemyX = ScreenWidth * 0.2f;
	float fEnemyY = ScreenHeight * 0.7f;

	int iteration = 0;
	for (int i = 0; i < enemyArrRows; i++) {
		for (int j = 0; j < enemyArrCols; j++) {
			alienShips[iteration].x = fEnemyX;
			alienShips[iteration].y = fEnemyY;
			MoveSprite(alienShips[iteration].iSpriteID, alienShips[iteration].x, alienShips[iteration].y);//put in positions
			fEnemyX += 0.12f * ScreenWidth; //change position for next iteration
			iteration++;
		}
		fEnemyY -= 0.1f * ScreenHeight;//change height
		fEnemyX = ScreenWidth * 0.2f;//reset x value
	}
}

void MoveEnemies(float deltaTime) {

	for (int i = 0; i < enemyArrLength; i++) {//loops to get to each array
		enemyTracker.InformOfMove(alienShips[i].Move(deltaTime, enemyTracker.GetDirection()));//if something hits a wall it will Return true
		MoveSprite(alienShips[i].iSpriteID, alienShips[i].x, alienShips[i].y);//commit sprtie movement (multiple returns in move meathod make it easier to have this live here instaead)
	}
	enemyTracker.EndMoveCycle();
}