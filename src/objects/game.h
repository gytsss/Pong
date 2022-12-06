#pragma once
#include "ball.h"
#include "pad.h"

const Color TRANSPARENT = Color{ 30, 255, 5, 0 };

enum Screen {
	Menu,
	Game,
	Options,
	Credits,
	Quit
};


void game();

void randomizeBall();

void reset();

void checkWin(int& winsPlayer1, int& winsPlayer2);

void drawGame(int& winsPlayer1, int& winsPlayer2, Texture2D background, const char* winText, Font font);

void drawMenu(Texture2D background, Font font, int& currentScreen);

void drawMenuText(Font font);

void mainMenuLogic(int& currentScreen);

void drawRules(Texture2D background, Font font);

void gamePlay( int& winsPlayer1, int& winsPlayer2);

void resetFullGame( int& winsPlayer1, int& winsPlayer2);

void drawBack(Font font);

bool checkCollisionBallPaddle(Vector2 a1, Vector2 a2, Vector2 b1, Vector2 b2);

