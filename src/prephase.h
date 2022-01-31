#ifndef GH
#include "geventhandler.cpp"
#endif
#include "world.cpp"




class BiomeObject {
    int index = 0;
public:
    unordered_map<int, Cell> collector;
    void push(Cell object);
};

class PlanetObject {
    int index = 0;
    int biomes = 0;
public:
    unordered_map<int, Biome> containing;
    unordered_map<int, BiomeObject> collector;
    void push(BiomeObject object);
    void push_container(Biome object);
};

class StarObject {
    int index = 0;
    int planets = 0;
public:
    unordered_map<int, Planet> containing;
    unordered_map<int, PlanetObject> collector;
    void push(PlanetObject object);
    void push_container(Planet object);
};

class GalaxyObject {
    int index = 0;
    int stars = 0;
public:
    unordered_map<int, Star> containing;
    unordered_map<int, StarObject> collector;
    void push(StarObject object);
    void push_container(Star object);
    void set_stars(int);
    int get_stars();
};





class WorldObject {
    GalaxyObject one;
    const unsigned int processor_count = std::thread::hardware_concurrency();
    int planet_index = 0;
public:
    WorldObject();
    PlanetObject generate_p(const uint8_t, const int);
    BiomeObject  generate_b(const int);
    StarObject   generate_s(const uint8_t, const uint8_t, const int);
    void         generate_star_system(const uint8_t, const uint8_t, const int);
    void         generate_cache_b(const int);


};