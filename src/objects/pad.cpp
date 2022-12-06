#include "raylib.h"
#include "pad.h"

 Pads pad1;

 Pads pad2{ 1885 };


void padsMovement()
{

	if (IsKeyDown(KEY_UP) && (pad2.y - pad2.height / 2) > 0)
		pad2.y -= pad2.speed * GetFrameTime();

	if (IsKeyDown(KEY_DOWN) && (pad2.y + pad2.height / 2) < GetScreenHeight())
		pad2.y += pad2.speed * GetFrameTime();

	if (IsKeyDown(KEY_W) && (pad1.y - pad1.height / 2) > 0)
		pad1.y -= pad1.speed * GetFrameTime();

	if (IsKeyDown(KEY_S) && (pad1.y + pad1.height / 2) < GetScreenHeight())
		pad1.y += pad1.speed * GetFrameTime();
}

void drawPads()
{
	DrawRectangle(static_cast<int>(pad1.x - pad2.width / 2), static_cast<int>(pad1.y- pad1.height / 2), static_cast<int>(pad1.width), static_cast<int>(pad1.height), WHITE);
	DrawRectangle(static_cast<int>(pad2.x - pad2.width / 2), static_cast<int>(pad2.y - pad2.height / 2), static_cast<int>(pad2.width), static_cast<int>(pad2.height), WHITE);
}
