#include "TextureManager.h"
#include "Tiles.h"
#include <iostream>

std::map<int, Texture2D> TextureManager::textures;

void TextureManager::LoadTextures() 
{
    textures[static_cast<int>(TileType::DIRT)] = LoadTexture("resources/Tiles/dirt.png");
    textures[static_cast<int>(TileType::STONE)] = LoadTexture("resources/Tiles/stone.png");

    //Set nearest-neighbor filtering to prevent blurry textures
    for (auto& texture : textures) 
    {
        SetTextureFilter(texture.second, TEXTURE_FILTER_POINT);
    }

    std::cout << "Textures Loaded Successfully!" << std::endl;
}

Texture2D TextureManager::GetTexture(int tileType) 
{
    return textures[tileType];
}

void TextureManager::UnloadTextures() 
{
    for (auto& texture : textures) 
    {
        UnloadTexture(texture.second);
    }
    textures.clear();
}