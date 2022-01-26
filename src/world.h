
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
  CoreGame();
  virtual ~CoreGame() {};
};





class Galaxy : public CoreGame
{
  unordered_map<const char*, int> collector;
  uint8_t type = 0;
  int stars = 0;
public:
  virtual unique_ptr<CoreGame> send_data() override;
  virtual void collector_use() override;

};





class Star : public CoreGame
{
  unordered_map<const char*, int> collector;
  uint8_t type = 0;
  uint8_t planets = 0;
  int temperature = 0;
  int size = 0;
public:
  virtual unique_ptr<CoreGame> send_data() override;
  virtual void collector_use() override;
};





class Planet : public CoreGame
{
  unordered_map<const char*, int> collector;
  uint8_t type = 0;
public:
  virtual unique_ptr<CoreGame> send_data() override;
  virtual void collector_use() override;
};




class Biome : public CoreGame
{
  unordered_map<const char*, int> collector;
  uint8_t type = 0;
public:
  virtual unique_ptr<CoreGame> send_data() override;
  virtual void collector_use() override;
};


class Cell : public CoreGame
{
  unordered_map<const char*, int> collector;
  uint8_t type = 0;
public:
  virtual unique_ptr<CoreGame> send_data() override;
  virtual void collector_use() override;
};
