#include "raylib.h"
#include "TerrainGeneration.h"

int main()
{
	const int winWidth = 1080;
	const int winHeight = 920;

	InitWindow(winWidth, winHeight, "Terraria Clone Please Help");

	TerrainSettings settings;
	settings.noiseFrequency = 0.02f;
	settings.minHeight = 10;
	settings.maxHeight = 70;
	settings.dirtDepth = 5;

	GenerateTerrain(settings);
	
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawWorld();
		EndDrawing();
	}
	CleanupWorld();
	CloseWindow();
	return 0;
}