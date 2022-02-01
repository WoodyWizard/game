#include <memory>
#include <stdint.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <thread>
#include <future>
#include <fstream>
#include "ZipLib/ZipFile.h"
#include "ZipLib/streams/memstream.h"
#include "ZipLib/methods/Bzip2Method.h"
#include <filesystem>

#define GH

class GHandler {
    const unsigned int processor_count = std::thread::hardware_concurrency();
public:
    unsigned int get_proc_count();
};