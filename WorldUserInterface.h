//
// Created by benja on 3/17/2017.
//

#ifndef GEOREGIONS_WORLDUSERINTERFACE_H
#define GEOREGIONS_WORLDUSERINTERFACE_H


#include "UserInterface.h"
#include "World.h"

class WorldUserInterface : public UserInterface
{
public:
    WorldUserInterface(Region* region);

protected:
    Region::RegionType getSubRegionType();
    void setupMenu();
};

#endif //GEOREGIONS_WORLDUSERINTERFACE_H
