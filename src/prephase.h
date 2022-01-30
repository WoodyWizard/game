#include "geventhandler.cpp"
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
public:
    WorldObject();
};