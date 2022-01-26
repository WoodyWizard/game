#include "world.h"



CoreGame::CoreGame() {

}


unique_ptr<CoreGame> Galaxy::send_data() {
    return std::make_unique<Galaxy>( *this ); 
}

unique_ptr<CoreGame> Star::send_data()  {
    return std::make_unique<Star>( *this ); 
}

unique_ptr<CoreGame> Planet::send_data()  {
    return std::make_unique<Planet>( *this ); 
}

unique_ptr<CoreGame> Biome::send_data()  {
    return std::make_unique<Biome>( *this ); 
}

unique_ptr<CoreGame> Cell::send_data()  {
    return std::make_unique<Cell>( *this ); 
}


void Galaxy::collector_use() {
    collector["type"] = (int)type;
    collector["stars"] = stars;
}

void Star::collector_use() {
    collector["type"] = (int)type;
    collector["planets"] = (int)planets;
    collector["temperature"] = temperature;
    collector["size"] = size;
}

void Planet::collector_use() {
    collector["type"] = (int)type;
}

void Biome::collector_use() {
    collector["type"] = (int)type;
}

void Cell::collector_use() {
    collector["type"] = (int)type;
}