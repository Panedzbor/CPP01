#include "Zombie.hpp"
#include "ZombieList.hpp"
#include <cstdlib>

static void display_menu(void);
static char get_input(void);
static std::string give_zombie_name(void);
static int choose_zombie(void);

int main(void)
{
    char input = 0;
    std::string name;
    Zombie *z;

    while (input != 'e')
    {
        display_menu();
        input = get_input();
        if (input == '1')
        {
            name = give_zombie_name();
            z = newZombie(name);
            addNewZombie(z); 
        }
        else if (input == '2')
        {
            name = give_zombie_name();
            randomChump(name);
        }
        else if (input == '3')
        {
            int zombie_i = choose_zombie();
            z = ZombieList::findZombie(zombie_i);
            z->announce();
            std::cout << '\n';
        }
        else if (input == '4')
        {
            int zombie_i = choose_zombie();
            z = ZombieList::findZombie(zombie_i);
            ZombieList *zl = ZombieList::findZombie(z);
            zl->destroyZombie();
        }
        else if (input != 'e')
            std::cout << "Invalid option\n\n";
        ZombieList::displayAll();
    }
    return (0);
}

static void display_menu(void)
{
    std::cout << "1: Create a new zombie\n";
    std::cout << "2: Create a random champ\n";
    std::cout << "3. Make a zombie announce himself\n";
    std::cout << "4: Destroy a zombie\n";
    std::cout << "e: Exit\n";
    std::cout << '\n';
}

static char get_input(void)
{
    char input = 0;
    
    while (!((input >= '1' && input <= '4') || input == 'e'))
    {
        std::cout << "Enter your choice: ";
        std::cin >> input;
        std::cin.ignore(1000, '\n');
    }
    std::cout << '\n';
    return (input);
}

static std::string give_zombie_name(void)
{
    std::string name;
    
    std::cout << "Give zombie a name: ";
    while (!std::getline(std::cin, name) || name.empty())
    {
        std::cin.ignore(1000, '\n');
        std::cout << "Give zombie a valid name: ";
    }
    std::cout << '\n';
    return (name);
}

static int choose_zombie(void)
{
    std::string s_index;
    int         i_index;
    
    std::cout << "Type in zombie's index you want to select: ";
    while (!(std::cin >> s_index) || s_index.empty() 
    || (i_index = std::atoi(s_index.c_str())) < 1 || i_index > ZombieList::get_total())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Type in a valid index: ";
    }
    std::cout << '\n';
    return (i_index - 1);
}