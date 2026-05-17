#include "HumanA.hpp"
#include <iostream>

void HumanA::attack(void)
{
    std::cout << name << " attacks with their " << weapon.getType();
    std::cout << '\n';
}