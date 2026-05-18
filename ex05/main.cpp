#include "Harl.hpp"

static void display_menu(void);
static char get_input(void);

int main(void)
{
    Harl H;
    std::string msgTypes[LVL_AMNT] = {"1: DEBUG", "2: INFO", "3. WARNING", "4: ERROR"};
    char input = 0;

    while (input != 'e')
    {
        std::cout << "Choose the message type you want Harl to reproduce\n";
        std::cout << '\n';
        display_menu();
        input = get_input();
        for (int i = 0; i < LVL_AMNT; i++)
        {
            if (input == msgTypes[i].c_str()[0])
            {
                H.complain(msgTypes[i].substr(3));
                std::cout << '\n';
            }
        }
    }
    return (0);
}

static void display_menu(void)
{
    std::cout << "1: DEBUG\n";
    std::cout << "2: INFO\n";
    std::cout << "3: WARNING\n";
    std::cout << "4: ERROR\n";
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