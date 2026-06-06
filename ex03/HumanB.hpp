#pragma once
#ifndef HUMANB_H
#define HUMANB_H

# include <string>
# include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon* weapon;
        HumanB();
    public:
        HumanB(std::string name);
        HumanB(std::string name, Weapon* weapon);
        void attack(void);
        void setWeapon(Weapon& weapon);
};

#endif