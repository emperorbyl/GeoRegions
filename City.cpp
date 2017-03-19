//
// Created by benja on 3/17/2017.
//

#include "City.h"

City::City(const std::string data[]) : Region(CityType, data)
{
    validate();
}