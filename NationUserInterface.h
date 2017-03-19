//
// Created by benja on 3/17/2017.
//

#ifndef GEOREGIONS_NATIONUSERINTERFACE_H
#define GEOREGIONS_NATIONUSERINTERFACE_H

#include "UserInterface.h"

class NationUserInterface : public UserInterface
{
public:
    NationUserInterface(Region* contextRegion);

    Region::RegionType getSubRegionType();
    void setupMenu();
};

#endif //GEOREGIONS_NATIONUSERINTERFACE_H
