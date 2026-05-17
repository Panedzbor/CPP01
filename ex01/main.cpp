#include "Zombie.hpp"
#include <cstdlib>
#include <iomanip>

static std::string give_zombie_name(void);
static int choose_amount(void);
static void announce_all(Zombie* z, int n);
static void deallocate(Zombie* z);

int main(void)
{
    char input;
    int amount;
    std::string name;
    Zombie *z;

    std::cout << "Let's create a horde of zombies!\n\n";
    amount = choose_amount();
    name = give_zombie_name();
    z = zombieHorde(amount, name);
    std::cout << '\n';
    announce_all(z, amount);
    std::cout << "All zombies created and announced. Ready to quit?\n\n";
    std::cin >> input;
    deallocate(z);
    return (0);
}

static void announce_all(Zombie *z, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << std::setw(5) << i + 1 << ". ";
        z[i].announce();
    }
    std::cout << '\n';
}

static void deallocate(Zombie* z)
{
    delete[] z;
    z = NULL;
}

static std::string give_zombie_name(void)
{
    std::string name;
    
    std::cout << "Give zombies a name: ";
    while (!std::getline(std::cin, name) || name.empty())
    {
        std::cin.ignore(1000, '\n');
        std::cout << "Give zombies a valid name: ";
    }
    std::cout << '\n';
    return (name);
}

static int choose_amount(void)
{
    std::string s_amount;
    int         i_amount;
    
    std::cout << "How many zombies do you want to create?\n";
    while (!(std::cin >> s_amount) || s_amount.empty() 
    || (i_amount = std::atoi(s_amount.c_str())) < 1)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Type in a valid amount: ";
    }
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << '\n';
    return (i_amount);
}