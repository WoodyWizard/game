#include "world.h"



CoreGame::CoreGame() {

}

void CoreGame::set_collector(unordered_map<const char*, int> local) {
    collector = local;
}


unique_ptr<CoreGame> Galaxy::send_data() {
    CoreGame object;
    collector_use();
    object.set_collector(collector);
    return std::make_unique<CoreGame>(object);
}

unique_ptr<CoreGame> Star::send_data()  {
    CoreGame object;
    collector_use();
    object.set_collector(collector);
    return std::make_unique<CoreGame>(object);
}

unique_ptr<CoreGame> Planet::send_data()  {
    CoreGame object;
    collector_use();
    object.set_collector(collector);
    return std::make_unique<CoreGame>(object);
}

unique_ptr<CoreGame> Biome::send_data()  {
    CoreGame object;
    collector_use();
    object.set_collector(collector);
    return std::make_unique<CoreGame>(object);
}

unique_ptr<CoreGame> Asteroid::send_data()  {
    CoreGame object;
    collector_use();
    object.set_collector(collector);
    return std::make_unique<CoreGame>(object);
}

unique_ptr<CoreGame> Cell::send_data()  {
    CoreGame object;
    collector_use();
    object.set_collector(collector);
    return std::make_unique<CoreGame>(object);
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