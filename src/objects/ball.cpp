#include "ball.h"
#include "game.h"

extern Ball ball;


void drawBall()
{
	DrawCircle(static_cast<int>(ball.posX), static_cast<int>(ball.posY), static_cast<float>(ball.radius), ball.color);
}

void centerBall()
{
	reset();

	ball.speed.x = 0;
	ball.speed.y = 0;
}

void initBall()
{
	centerBall();
	randomizeBall();
}