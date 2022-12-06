#include "raylib.h"
#include "objects/game.h"


int main()
{ 

	InitWindow(1920, 1080, "Pong");
	InitAudioDevice();

	ToggleFullscreen();

	SetWindowState(FLAG_VSYNC_HINT);

	game();

	CloseAudioDevice();
	CloseWindow();
}

