#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " destroyed\n";
}

void Zombie::announce(void)
{
    std::cout << name << ":  BraiiiiiiinnnzzzZ...\n";
}
