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



void Galaxy::set_type(uint8_t object) {
    type = object;
}

uint8_t Galaxy::get_type() {
    return type;
}

void Galaxy::set_stars(int object) {
    stars = object;
}

int Galaxy::get_stars() {
    return stars;
}

void Star::set_type(uint8_t object) {
    type = object;
}

uint8_t Star::get_type() {
    return type;
}

void Star::set_planets(uint8_t object) {
    planets = object;
}

uint8_t Star::get_planets() {
    return planets;
}

void Star::set_temperature(int object) {
    temperature = object;
}

int Star::get_temperature() {
    return temperature;
}

void Star::set_size(int object) {
    size = object;
}

int Star::get_size() {
    return size;
}

void Planet::set_type(uint8_t object) {
    type = object;
}

uint8_t Planet::get_type() {
    return type;
}

void Asteroid::set_type(uint8_t object) {
    type = object;
}

uint8_t Asteroid::get_type() {
    return type;
}

void Asteroid::set_size(int object) {
    size = object;
}

int Asteroid::get_size() {
    return size;
}

void Biome::set_type(uint8_t object) {
    type = object;
}

uint8_t Biome::get_type() {
    return type;
}

void Biome::set_size(int object) {
    size = object;
}

int Biome::get_size() {
    return size;
}

void Cell::set_type(uint8_t object) {
    type = object;
}

uint8_t Cell::get_type() {
    return type;
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