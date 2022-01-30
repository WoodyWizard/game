#include "prephase.h"



void GalaxyObject::push(StarObject object) {
    collector[index] = object;
    index += 1;
}

void StarObject::push(PlanetObject object) {
    collector[index] = object;
    index += 1;
}

void PlanetObject::push(BiomeObject object) {
    collector[index] = object;
    index += 1;
}

void BiomeObject::push(Cell object) {
    collector[index] = object;
    index += 1;
}


WorldObject::WorldObject() {
    std::vector<PlanetObject> oneP;
    std::vector<BiomeObject> oneB;
    std::vector<StarObject> oneS;

    for(int star = 0; star < 100; star++) { // stars
        StarObject localStar;
        for(int i = 0; i < 10; i++) { // planets
            PlanetObject localPlanet;
            for(int b = 0; b < 10; b++) { // biome
                BiomeObject localBiome;
                for(int c = 0; c < 100000; c++) { // cells
                    Cell local1;
                    localBiome.collector[b] = local1;
                }
            localPlanet.collector[b] = localBiome;
            }
        localStar.collector[i] = localPlanet;
        std::cout << "Planets for Star " << star << " and Planet with number " << i << " generated " << std::endl;
        }
        oneS.push_back(localStar);
        std::cout << "Star " << star << " generated" << std::endl;
    }
}