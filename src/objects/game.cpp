#include <string>
#include "raylib.h"
#include "game.h"
#include "pad.h"
#include "ball.h"

using namespace std;


Ball ball;

extern Pads pad1;

extern Pads pad2;

void game()
{

	Texture2D background = LoadTexture("./Fondo/Fondo.png");

	Sound music = LoadSound("Fondo/music.wav"); //https://www.youtube.com/watch?v=gND8t9aYNC8&ab_channel=DiegoLuque

	Font font = LoadFontEx("Fondo/font.ttf", 164, 0, 0);

	const char* winText = nullptr;

	int winsPlayer1 = 0;
	int winsPlayer2 = 0;
	int currentScreen = Menu;

	bool gameFinish = false;

	SetSoundVolume(music, 1.0f);

	randomizeBall();

	PlaySound(music);

	while (!WindowShouldClose() && !gameFinish)
	{


		if (IsKeyPressed(KEY_SPACE))
			currentScreen = Menu;


		switch (currentScreen)
		{
		case Menu:
			winText = nullptr;
			resetFullGame(winsPlayer1, winsPlayer2);
			drawMenu(background, font, currentScreen);
			break;
		case Game:
			gamePlay(currentScreen, background, winsPlayer1, winsPlayer2, winText);

			if (winsPlayer1 == 3)
			{
				winText = "Player 1 Wins!";
				centerBall();
				if (IsKeyPressed(KEY_SPACE))
					currentScreen = Menu;
			}


			if (winsPlayer2 == 3)
			{
				winText = "Player 2 Wins!";
				centerBall();
				if (IsKeyPressed(KEY_SPACE))
					currentScreen = Menu;

			}

			drawGame(winsPlayer1, winsPlayer2, background, winText, font);
			break;
		case Options:
			drawRules(background, font);
			break;
		case Quit:
			gameFinish = true;
			break;
		default:
			break;
		}

	}
	StopSoundMulti();

	UnloadTexture(background);
	UnloadSound(music);
}

void randomizeBall()
{
	int randomX;
	int randomY;

	do
	{
		randomX = GetRandomValue(-350, 350);

	} while (randomX != 350 && randomX != -350);

	do
	{
		randomY = GetRandomValue(-350, 350);

	} while (randomY != 350 && randomY != -350);


	ball.speed.x = randomX;
	ball.speed.y = randomY;
}

void reset()
{
	ball = { 960, 510 };

	pad1 = { 35, 425 };
	pad2 = { 1885 , 425 };

	randomizeBall();
}

void checkWin(int& winsPlayer1, int& winsPlayer2)
{


	if (ball.posX < 0)
	{
		winsPlayer2++;
		reset();
	}


	if (ball.posX > GetScreenWidth())
	{
		winsPlayer1++;
		reset();
	}



}

void drawGame(int& winsPlayer1, int& winsPlayer2, Texture2D background, const char* winText, Font font)
{

	string score1 = to_string(winsPlayer1);
	string score2 = to_string(winsPlayer2);

	BeginDrawing();
	ClearBackground(BLACK);

	DrawTexture(background, 0, 0, WHITE);

	DrawText(score1.c_str(), (GetScreenWidth() / 2) - (GetScreenHeight() / 10), GetScreenHeight() / 10, GetScreenHeight() / 10, GREENNEON);
	DrawText(score2.c_str(), (GetScreenWidth() / 2) + (GetScreenHeight() / 10) / 2, GetScreenHeight() / 10, GetScreenHeight() / 10, GREENNEON);

	drawPads();

	DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);

	drawBall();

	drawBack(font);

	DrawFPS(10, 10);


	if (winText)
	{
		int textWidth = MeasureText(winText, 100);
		DrawText(winText, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight() / 2 - 30, 100, REDNEON);
	}

	EndDrawing();
}

void drawMenu(Texture2D background, Font font, int& currentScreen)
{
	BeginDrawing();
	ClearBackground(GREENNEON);
	DrawTexture(background, 0, 0, WHITE);

	mainMenuLogic(currentScreen);

	drawMenuText(font);

	EndDrawing();
}

void drawMenuText(Font font)
{
	float titleWidht = MeasureText("Pong", font.baseSize);

	Vector2 mainTextPosition = { GetScreenWidth() / 2 - titleWidht / 2, 100 };

	DrawTextEx(font, TextFormat("Pong"), mainTextPosition, (float)font.baseSize, 0, GREENNEON);
	DrawTextEx(font, TextFormat("Play"), Vector2{ 10, 350 }, 100, 0, GREENNEON);
	DrawTextEx(font, TextFormat("Options"), Vector2{ 10, 500 }, 100, 0, GREENNEON);
	DrawTextEx(font, TextFormat("Credits"), Vector2{ 10, 650 }, 100, 0, GREENNEON);
	DrawTextEx(font, TextFormat("Quit"), Vector2{ 10, 800 }, 100, 0, GREENNEON);
}

void mainMenuLogic(int& currentScreen)
{
	Rectangle menuBox1{ 0, 370 , 200, 70 };
	Rectangle menuBox2{ 0, 520 , 310, 70 };
	Rectangle menuBox3{ 0, 670 , 300, 70 };
	Rectangle menuBox4{ 0, 820 , 175, 70 };


	DrawRectangleRec(menuBox1, TRANSPARENT);
	DrawRectangleRec(menuBox2, TRANSPARENT);
	DrawRectangleRec(menuBox3, TRANSPARENT);
	DrawRectangleRec(menuBox4, TRANSPARENT);

	if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), menuBox1)))
		currentScreen = Game;
	if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), menuBox2)))
		currentScreen = Options;
	if ((IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), menuBox3)))
		OpenURL("https://tgodd.itch.io/");
	if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), menuBox4)))
		currentScreen = Quit;

}

void drawRules(Texture2D background, Font font)
{
	const char* rules = "Pong is a game based on table tennis, in which 2 players face each other by moving their paddles.\nA ball will come out from the middle of the screen randomly and the goal of the players is to\nreturn it to prevent the ball from touching the end line.The player who gets 3 points, win the\nmatch.";

	float titleWidht = MeasureText("Rules", font.baseSize);

	Vector2 optionsTextPosition = { GetScreenWidth() / 2 - titleWidht / 2, 100 };

	BeginDrawing();
	ClearBackground(GREENNEON);
	DrawTexture(background, 0, 0, WHITE);

	DrawTextEx(font, TextFormat("Rules"), optionsTextPosition, (float)font.baseSize, 0, GREENNEON);
	DrawTextEx(font, rules, Vector2{ 10, 350 }, 50, 0, REDNEON);

	drawBack(font);

	DrawTextEx(font, TextFormat("Player 1\n     W\n      S"), Vector2{ (float) GetScreenWidth() / 2 - 400, (float)GetScreenHeight() / 2 + 200 }, 64, 0, GREENNEON);
	DrawTextEx(font, TextFormat("Player 2\n     Up\n  Down"), Vector2{ (float)GetScreenWidth() / 2 + 200, (float)GetScreenHeight() / 2 + 200 }, 64, 0, GREENNEON);

	EndDrawing();

}

void gamePlay(int& currentScreen, Texture2D background, int& winsPlayer1, int& winsPlayer2, const char* winText)
{
	
	padsMovement();


	ball.posX += ball.speed.x * GetFrameTime();
	ball.posY += ball.speed.y * GetFrameTime();


	if (ball.posY < 0)
	{
		ball.posY = 0;
		ball.speed.y *= -1;
	}

	if (ball.posY > GetScreenHeight())
	{
		ball.posY = GetScreenHeight();
		ball.speed.y *= -1;
	}

	
	if (checkCollisionBallPaddle(Vector2{ ball.posX - ball.radius, ball.posY - ball.radius }, Vector2{ ball.posX + ball.radius, ball.posY + ball.radius }, Vector2{ pad1.x - pad1.width / 2, pad1.y - pad1.height / 2 }, Vector2{pad1.x + pad1.width / 2, pad1.y + pad1.height / 2}))
	{
		if (ball.speed.x < 0)
		{
			ball.speed.x *= -1.1f;
			ball.speed.y = (ball.posY - pad1.y) / (pad1.height / 2) * ball.speed.x;
		}

	}
	if (checkCollisionBallPaddle(Vector2{ ball.posX - ball.radius, ball.posY - ball.radius }, Vector2{ ball.posX + ball.radius, ball.posY + ball.radius }, Vector2{ pad2.x - pad2.width / 2, pad2.y - pad2.height / 2 }, Vector2{ pad2.x + pad2.width / 2, pad2.y + pad2.height / 2 }))
	{
		if (ball.speed.x > 0)
		{
			ball.speed.x *= -1.1f;
			ball.speed.y = (ball.posY - pad2.y) / (pad2.height / 2) * ball.speed.x * -1;
		}
	}

	checkWin(winsPlayer1, winsPlayer2);

}

void resetFullGame(int& winsPlayer1, int& winsPlayer2)
{
	winsPlayer1 = 0;
	winsPlayer2 = 0;

	initBall();
}

void drawBack(Font font)
{
	DrawTextEx(font, TextFormat("Space to return"), Vector2{ (float)GetScreenWidth() - 350 , (float)GetScreenHeight() - 100 }, 50, 0, GREENNEON);
}

bool checkCollisionBallPaddle(Vector2 a1, Vector2 a2, Vector2 b1, Vector2 b2)
{

	if (a1.x < b2.x && a2.x > b1.x &&
		a2.y > b1.y && a1.y < b2.y)
		return true;
	else
		return false;
	
}