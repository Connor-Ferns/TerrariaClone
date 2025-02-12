#ifndef TERRAINSETTINGS_H
#define TERRAINSETTINGS_H

struct TerrainSettings {
    float noiseFrequency = 0.02f;  // Controls smoothness of terrain
    int minHeight = 20;            // Minimum ground level
    int maxHeight = 60;            // Maximum ground level
    int dirtDepth = 4;             // How deep the dirt layer goes before stone starts
};

#endif // TERRAINSETTINGS_H