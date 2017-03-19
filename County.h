//
// Created by benja on 3/17/2017.
//

#ifndef GEOREGIONS_COUNTY_H
#define GEOREGIONS_COUNTY_H
#include "Region.h"

#include <string>

class County : public Region{
public:
    County(const std::string data[]);
};


#endif //GEOREGIONS_COUNTY_H
