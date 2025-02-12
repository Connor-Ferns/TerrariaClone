#include "raylib.h"
#include "TerrainGeneration.h"
#include "TextureManager.h"

int main()
{
	const int winWidth = 1080;
	const int winHeight = 920;

	InitWindow(winWidth, winHeight, "Terraria Clone Please Help");

	TextureManager::LoadTextures();

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

	TextureManager::UnloadTextures();

	CleanupWorld();
	CloseWindow();
	return 0;
}