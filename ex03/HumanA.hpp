#pragma once
#ifndef HUMANA_H
#define HUMANA_H

# include <string>
# include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon& weapon;
        HumanA();
    public:
        HumanA(std::string name, Weapon& weapon);
        void attack(void);
};

#endif