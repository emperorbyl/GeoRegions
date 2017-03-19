//
// Created by benja on 3/17/2017.
//

#ifndef GEOREGIONS_NATION_H
#define GEOREGIONS_NATION_H

#include "Region.h"

#include <string>

class Nation : public Region
{
public:
    Nation(const std::string data[]);
};


#endif //GEOREGIONS_NATION_H
