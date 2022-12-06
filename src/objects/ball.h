#pragma once
#include "raylib.h"

const Color GREENNEON = Color{ 30, 255, 5, 255 };
const Color REDNEON = Color{ 255, 5, 52, 255 };

struct Ball
{
	float posX = 960;
	float posY = 510;
	int radius = 15;
	float width = 7.5;
	float height = 7.5;
	Vector2 speed = { 350.0f, 350.0f };
	Color color = GREENNEON;

};

void drawBall();

void centerBall();

void initBall();