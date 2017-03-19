//
// Created by benja on 3/17/2017.
//

#ifndef GEOREGIONS_CITY_H
#define GEOREGIONS_CITY_H
#include "Region.h"

#include <string>

class City : public Region{
public:
    City(const std::string data[]);
};


#endif //GEOREGIONS_CITY_H
