//
// Created by benja on 3/17/2017.
//

#ifndef GEOREGIONS_STATEUSERINTERFACE_H
#define GEOREGIONS_STATEUSERINTERFACE_H

#include "UserInterface.h"

class StateUserInterface : public UserInterface
{
public:
    StateUserInterface(Region* contextRegion);

    Region::RegionType getSubRegionType();
    void setupMenu();
};


#endif //GEOREGIONS_STATEUSERINTERFACE_H
