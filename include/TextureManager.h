#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "raylib.h"
#include <map>

class TextureManager 
{
    public:
        static void LoadTextures();  // Load all textures
        static Texture2D GetTexture(int tileType);  // Retrieve a texture
        static void UnloadTextures();  // Free memory

    private:
        static std::map<int, Texture2D> textures;  // Map of textures
};
#endif // TEXTUREMANAGER_H