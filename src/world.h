
#include <memory>
#include <stdint.h>
#include <vector>
#include <unordered_map>


using namespace std;

class CoreGame
{
  unordered_map<const char*, int> collector;
public:
  CoreGame();
  void set_collector(unordered_map<const char*, int>);
};


class Galaxy
{
  uint8_t type = 0;
  int stars = 0;
public:
  unordered_map<const char*, int> collector;
  unique_ptr<CoreGame> send_data();
  void collector_use();
  void add_to_container(unique_ptr<CoreGame> local);
};


class Star
{
  uint8_t type = 0;
  uint8_t planets = 0;
  int temperature = 0;
  int size = 0;
public:
  unordered_map<const char*, int> collector;
  unique_ptr<CoreGame> send_data();
  void collector_use();
  void add_to_container(unique_ptr<CoreGame> local);
};


class Planet 
{
  uint8_t type = 0;
public:
  unordered_map<const char*, int> collector;
  unique_ptr<CoreGame> send_data();
  void collector_use();
  void add_to_container(unique_ptr<CoreGame> local);
};


class Asteroid 
{
  uint8_t type = 0;
  int size = 0;
public:
  unordered_map<const char*, int> collector;
  unique_ptr<CoreGame> send_data();
  void collector_use();
  void add_to_container(unique_ptr<CoreGame> local);
};


class Biome
{
  uint8_t type = 0;
public:
  unordered_map<const char*, int> collector;
  unique_ptr<CoreGame> send_data();
  void collector_use();
  void add_to_container(unique_ptr<CoreGame> local);
};


class Cell 
{
  uint8_t type = 0;
public:
  unordered_map<const char*, int> collector;
  unique_ptr<CoreGame> send_data();
  void collector_use();
  void add_to_container(unique_ptr<CoreGame> local);
};






class Entity {
    unordered_map<const char*, int> collector;
public:
    virtual unique_ptr<Entity> send_data() = 0;
    virtual void collector_use() = 0;
    Entity();
    virtual ~Entity() {};
};


class ALive : public Entity {
    uint8_t type;
    int x;
    int y;
public:
    unordered_map<const char*, int> collector;
    virtual unique_ptr<Entity> send_data() override;
    virtual void collector_use() override;
};


class Object : public Entity {
    
    uint8_t type;
    int x;
    int y;
public:
    unordered_map<const char*, int> collector;
    virtual unique_ptr<Entity> send_data() override;
    virtual void collector_use() override;
};





