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

unique_ptr<CoreGame> Asteroid::send_data()  {
    return std::make_unique<Asteroid>( *this ); 
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

void Asteroid::collector_use() {
    collector["type"] = (int)type;
    collector["size"] = size;
}

void Cell::collector_use() {
    collector["type"] = (int)type;
}

void Galaxy::add_to_container() {

}

void Star::add_to_container() {

}

void Planet::add_to_container() {

}

void Biome::add_to_container() {

}

void Cell::add_to_container() {

}

void Asteroid::add_to_container() {

}




Entity::Entity() {

}

unique_ptr<Entity> ALive::send_data() {
    return std::make_unique<ALive>( *this ); 
}

unique_ptr<Entity> Object::send_data() {
    return std::make_unique<Object>( *this ); 
}


void ALive::collector_use() {
    collector["type"] = (int)type;
    collector["x"] = x;
    collector["y"] = y;
}

void Object::collector_use() {
    collector["type"] = (int)type;
    collector["x"] = x;
    collector["y"] = y;
}