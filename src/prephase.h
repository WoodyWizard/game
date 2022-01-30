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
public:
    unordered_map<int, BiomeObject> collector;
    void push(BiomeObject object);
};

class StarObject {
    int index = 0;
public:
    unordered_map<int, PlanetObject> collector;
    void push(PlanetObject object);
};

class GalaxyObject {
    int index = 0;
public:
    unordered_map<int, StarObject> collector;
    void push(StarObject object);
};





class WorldObject {
    GalaxyObject one;
    const unsigned int processor_count = std::thread::hardware_concurrency();
public:
    WorldObject();
    PlanetObject generate_p(const uint8_t, const int);
    BiomeObject  generate_b(const int);
    StarObject   generate_s(const uint8_t, const uint8_t, const int);

};