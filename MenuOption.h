//
// Created by benja on 3/17/2017.
//

#ifndef GEOREGIONS_MENUOPTION_H
#define GEOREGIONS_MENUOPTION_H


#include <string>

class MenuOption {
private:
    std::string m_command;
    std::string m_description;

public:
    MenuOption(std::string command, std::string description);
    const std::string& getCommand() const { return m_command; }
    const std::string& getDescription() const { return m_description; }
};

#endif //GEOREGIONS_MENUOPTION_H
