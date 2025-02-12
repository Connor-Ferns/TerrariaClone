#ifndef TILES_H
#define TILES_H

#include "raylib.h"

// Enum for tile types
enum class TileType 
{
    AIR,
    DIRT,
    STONE
};

// Base Tile Class
class Tile 
{
protected:
    int x, y;
    bool isSolid;
    TileType type; // Store the tile type
    Texture2D texture;

public:
    Tile(int x, int y, bool solid, TileType type);
    virtual ~Tile() {}

    virtual void Draw() = 0; // Pure virtual function for rendering
    bool IsSolid();
    TileType GetType();
};

// Dirt Tile
class DirtTile : public Tile 
{
public:
    DirtTile(int x, int y);
    void Draw() override;
};

// Stone Tile
class StoneTile : public Tile 
{
public:
    StoneTile(int x, int y);
    void Draw() override;
};

#endif // TILES_H