#include "Tiles.h"
#include "TextureManager.h"

// Base Tile Constructor
Tile::Tile(int x, int y, bool solid, TileType type) :
    x(x),
    y(y),
    isSolid(solid),
    type(type) ,
    texture(TextureManager::GetTexture(static_cast<int>(type)))
{}

bool Tile::IsSolid() 
{
    return isSolid;
}

TileType Tile::GetType() 
{
    return type;
}

// Dirt Tile Implementation
DirtTile::DirtTile(int x, int y) : 
    Tile(
        x,
        y,
        true,
        TileType::DIRT)
    {}

void DirtTile::Draw() 
{
    Rectangle source = { 0, 0, 128, 128 }; // Full texture (128x128)
    Rectangle dest = { x * 16, y * 16, 16, 16 }; // Scale to 16x16
    Vector2 origin = { 0, 0 }; // No rotation
    DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
}

// Stone Tile Implementation
StoneTile::StoneTile(int x, int y) : 
    Tile(
        x,
        y,
        true,
        TileType::STONE)
    {}

void StoneTile::Draw() {
    Rectangle source = { 0, 0, 128, 128 }; // Full texture (128x128)
    Rectangle dest = { x * 16, y * 16, 16, 16 }; // Scale to 16x16
    Vector2 origin = { 0, 0 }; // No rotation
    DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);
}