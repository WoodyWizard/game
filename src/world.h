
#include <memory>
#include <stdint.h>
#include <vector>
#include <unordered_map>


using namespace std;

class CoreGame
{
  unordered_map<const char*, int> collector;
public:
  virtual unique_ptr<CoreGame> send_data() = 0;
  virtual void collector_use() = 0;
  virtual void add_to_container() = 0;
  CoreGame();
  virtual ~CoreGame() {};
};


class Galaxy : public CoreGame
{
  unordered_map<int, CoreGame*> containing;
  uint8_t type = 0;
  int stars = 0;
public:
  unordered_map<const char*, int> collector;
  virtual unique_ptr<CoreGame> send_data() override;
  virtual void collector_use() override;
  virtual void add_to_container() override;
};


class Star : public CoreGame
{
  unordered_map<int, CoreGame*> containing;
  uint8_t type = 0;
  uint8_t planets = 0;
  int temperature = 0;
  int size = 0;
public:
  unordered_map<const char*, int> collector;
  virtual unique_ptr<CoreGame> send_data() override;
  virtual void collector_use() override;
  virtual void add_to_container() override;
};


class Planet : public CoreGame
{
  unordered_map<int, CoreGame*> containing;
  uint8_t type = 0;
public:
  unordered_map<const char*, int> collector;
  virtual unique_ptr<CoreGame> send_data() override;
  virtual void collector_use() override;
  virtual void add_to_container() override;
};


class Asteroid : public CoreGame
{
  unordered_map<int, CoreGame*> containing;
  uint8_t type = 0;
  int size = 0;
public:
  unordered_map<const char*, int> collector;
  virtual unique_ptr<CoreGame> send_data() override;
  virtual void collector_use() override;
  virtual void add_to_container() override;
};


class Biome : public CoreGame
{
  unordered_map<int, CoreGame*> containing;
  uint8_t type = 0;
public:
  unordered_map<const char*, int> collector;
  virtual unique_ptr<CoreGame> send_data() override;
  virtual void collector_use() override;
  virtual void add_to_container() override;
};


class Cell : public CoreGame
{
  unordered_map<int, CoreGame*> containing;
  uint8_t type = 0;
public:
  unordered_map<const char*, int> collector;
  virtual unique_ptr<CoreGame> send_data() override;
  virtual void collector_use() override;
  virtual void add_to_container() override;
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





