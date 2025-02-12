#include "Tiles.h"

// Base Tile Constructor
Tile::Tile(int x, int y, bool solid, TileType type) : x(x), y(y), isSolid(solid), type(type) {}

bool Tile::IsSolid() {
    return isSolid;
}

TileType Tile::GetType() {
    return type;
}

// Dirt Tile Implementation
DirtTile::DirtTile(int x, int y) : Tile(x, y, true, TileType::DIRT) {}

void DirtTile::Draw() {
    DrawRectangle(x * 16, y * 16, 16, 16, BROWN);
}

// Stone Tile Implementation
StoneTile::StoneTile(int x, int y) : Tile(x, y, true, TileType::STONE) {}

void StoneTile::Draw() {
    DrawRectangle(x * 16, y * 16, 16, 16, DARKGRAY);
}