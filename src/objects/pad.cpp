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
	DrawRectangle(pad1.x - pad2.width / 2, pad1.y - pad1.height / 2, pad1.width, pad1.height, WHITE);
	DrawRectangle(pad2.x - pad2.width / 2, pad2.y - pad2.height / 2, pad2.width, pad2.height, WHITE);
}
