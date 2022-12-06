#include "ball.h"
#include "game.h"

extern Ball ball;


void drawBall()
{
	DrawCircle(ball.posX, ball.posY, ball.radius, ball.color);
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