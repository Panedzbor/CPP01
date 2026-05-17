#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " destroyed\n";
    std::cout << '\n';
}

void Zombie::announce(void)
{
    std::cout << name << ":  BraiiiiiiinnnzzzZ...\n";
}
