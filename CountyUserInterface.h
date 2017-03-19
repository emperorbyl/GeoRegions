//
// Created by benja on 3/17/2017.
//

#ifndef GEOREGIONS_COUNTYUSERINTERFACE_H
#define GEOREGIONS_COUNTYUSERINTERFACE_H

#include "UserInterface.h"

class CountyUserInterface : public UserInterface
{
public:
    CountyUserInterface(Region* region);

protected:
    Region::RegionType getSubRegionType();
    void setupMenu();

};

#endif //GEOREGIONS_COUNTYUSERINTERFACE_H
