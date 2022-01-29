#include "geventhandler.cpp"
#include "world.cpp"



class BiomeObject {
    public:
    unordered_map<int, Cell> collector;
};

class PlanetObject {
    public:
    unordered_map<int, BiomeObject> collector;
};

class StarObject {
    public:
    unordered_map<int, PlanetObject> collector;
};

class GalaxyObject {
    public:
    unordered_map<int, StarObject> collector;
};





class WorldObject {
    GalaxyObject one;
public:

};