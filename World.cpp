//
// Created by benja on 3/17/2017.
//

#include "World.h"
#include <iomanip>

const std::string worldData[3] = {"World", "0", "510100000.0"};

World::World() : Region(WorldType, worldData)
{
    validate();
}