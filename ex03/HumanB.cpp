#include "HumanB.hpp"
#include <iostream>

void HumanB::attack(void)
{
    std::cout << name << " attacks with their " << weapon->getType();
    std::cout << '\n';
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}