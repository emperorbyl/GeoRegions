//
// Created by benja on 3/17/2017.
//

#include "Nation.h"

Nation::Nation(const std::string data[]) : Region(NationType, data)
{
    validate();
}