//
// Created by benja on 3/17/2017.
//

#include "County.h"

County::County(const std::string data[]) : Region(CountyType, data)
{
    validate();
}