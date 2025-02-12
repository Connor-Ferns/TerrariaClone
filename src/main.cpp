#include "raylib.h"
#include "TerrainGeneration.h"

int main()
{
	const int winWidth = 1080;
	const int winHeight = 920;

	InitWindow(winWidth, winHeight, "Terraria Clone Please Help");

	Texture dirtTexture = LoadTexture("resources/Tiles/dirt.png");
	Texture stoneTexture = LoadTexture("resources/Tiles/stone.png");

	// Apply nearest-neighbor filtering to keep pixels sharp
	SetTextureFilter(dirtTexture, TEXTURE_FILTER_POINT);
	SetTextureFilter(stoneTexture, TEXTURE_FILTER_POINT);

	TerrainSettings settings;
	settings.noiseFrequency = 0.02f;
	settings.minHeight = 10;
	settings.maxHeight = 70;
	settings.dirtDepth = 5;

	GenerateTerrain(settings, dirtTexture, stoneTexture);
	
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawWorld();
		EndDrawing();
	}

	UnloadTexture(dirtTexture);
	UnloadTexture(stoneTexture);

	CleanupWorld();
	CloseWindow();
	return 0;
}