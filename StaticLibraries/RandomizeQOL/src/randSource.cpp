#include "RandomizeQOL.h"

int randomize::RandRange(int start, int end){
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> distrib(start, end);
    return distrib(gen);
}
