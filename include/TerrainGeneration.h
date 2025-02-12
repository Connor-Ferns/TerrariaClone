#ifndef TERRAINGENERATION_H
#define TERRAINGENERATION_H

#include "Tiles.h"
#include "FastNoiseLite.h"
#include "TerrainSettings.h"

const int WORLD_WIDTH = 200;
const int WORLD_HEIGHT = 100;
const int TILE_SIZE = 16;

extern Tile* world[WORLD_WIDTH][WORLD_HEIGHT];

void GenerateTerrain(const TerrainSettings& settings);
void DrawWorld();
void CleanupWorld();

#endif