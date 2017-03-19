//
// Created by benja on 3/17/2017.
//

#include "State.h"

State::State(const std::string data[]) : Region(StateType, data)
{
    validate();
}
