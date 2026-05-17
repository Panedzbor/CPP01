#include "Zombie.hpp"

Zombie::Zombie() : name("")
{
    std::cout << "Default zombie created\n";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Zombie " << name << " created\n";
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " destroyed\n";
}

void Zombie::announce(void)
{
    std::cout << name << ":  BraiiiiiiinnnzzzZ...\n";
}
