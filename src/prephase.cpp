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







    BiomeObject  WorldObject::generate_b(const int RANGE) {
        BiomeObject biome;
        for(int c = 0; c < RANGE; c++) { // cells
            Cell local1;
            biome.collector[c] = local1;
        }
    return biome;
    }



    PlanetObject WorldObject::generate_p(const uint8_t n_biomes, const int n_cells) {
        PlanetObject planet;
        for(int c = 0; c < n_biomes; c++) { // biomes
            planet.collector[c] = generate_b(n_cells);
        }
    return planet;
    }



    StarObject   WorldObject::generate_s(const uint8_t n_planets, const uint8_t n_biomes, const int n_cells) {
        StarObject star;
        for(int c = 0; c < n_planets; c++) { // Planets
            star.collector[c] = generate_p(n_biomes, n_cells);
        }
        std::cout << "Star generated " << std::endl;
    return star;
    }






WorldObject::WorldObject() {

    int stars = 100;
    std::vector<std::thread> threads;
    std::vector<StarObject> oneS;



    for (int i = 0; i < 12; i++) {
        threads.push_back( std::thread{[&] {
                oneS.push_back(generate_s(10, 10, 100000));
            }
        });
    std::cout << "i: " << i << std::endl;
    }

    
    for (auto &th : threads) {
        th.join();
        std::cout << "waiting" << std::endl;
    }


    std::cout << oneS.size() << " Size of ONES" << std::endl;
}