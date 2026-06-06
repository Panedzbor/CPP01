#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon() {};

HumanB::HumanB(std::string name, Weapon* weapon) : name(name), weapon(weapon) {};

void HumanB::attack(void)
{
    std::cout << name << " attacks with their " << weapon->getType();
    std::cout << '\n';
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}