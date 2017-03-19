//
// Created by benja on 3/17/2017.
//

#ifndef GEOREGIONS_USERINTERFACE_H
#define GEOREGIONS_USERINTERFACE_H

#include "Region.h"
#include <string>

class Menu;

class UserInterface {
protected:
    Region*   m_currentRegion = nullptr;
    Menu*     m_menu = nullptr;
    Region::RegionType  m_subRegionType;

public:
    UserInterface(Region* contextRegion);
    ~UserInterface();
    void run();

protected:
    virtual Region::RegionType getSubRegionType();
    virtual void setupMenu();
    virtual void cleanup();
    virtual void add();
    virtual void list();
    virtual void edit();
    virtual void editName(Region* region);
    virtual void editPopulation(Region* region);
    virtual void editArea(Region* region);
    virtual void remove();
    virtual void print();
    virtual void changeToSubRegion();
};



#endif //GEOREGIONS_USERINTERFACE_H
