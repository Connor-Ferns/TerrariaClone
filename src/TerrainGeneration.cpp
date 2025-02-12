#include "TerrainGeneration.h"

Tile* world[WORLD_WIDTH][WORLD_HEIGHT] = { nullptr };

void GenerateTerrain(const TerrainSettings& settings)
{
    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    noise.SetFrequency(settings.noiseFrequency);

    for (int x = 0; x < WORLD_WIDTH; x++) 
    {
        float noiseValue = noise.GetNoise(static_cast<float>(x), 0.0f) * 0.5f + 0.5f;
        int terrainHeight = static_cast<int>(noiseValue * (settings.maxHeight - settings.minHeight)) + settings.minHeight;

        for (int y = 0; y < WORLD_HEIGHT; y++) 
        {
            if (y < terrainHeight) 
            {
                world[x][y] = nullptr; //Empty Air
            }
            else if (y < terrainHeight + settings.dirtDepth) 
            {
                world[x][y] = new DirtTile(x, y);
            }
            else 
            {
                world[x][y] = new StoneTile(x, y);
            }
        }
    }
}

void DrawWorld() 
{
    for (int x = 0; x < WORLD_WIDTH; x++) 
    {
        for (int y = 0; y < WORLD_HEIGHT; y++) 
        {
            if (world[x][y] != nullptr) 
            {
                world[x][y]->Draw();
            }
        }
    }
}

void CleanupWorld() 
{
    for (int x = 0; x < WORLD_WIDTH; x++) 
    {
        for (int y = 0; y < WORLD_HEIGHT; y++) 
        {
            delete world[x][y];
            world[x][y] = nullptr;
        }
    }
}