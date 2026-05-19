#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese burger. I really do!\n";
    std::cout << '\n';
}

void Harl::info(void)
{
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money.\n";
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
    std::cout << '\n';
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free.\n";
    std::cout << "I’ve been coming for years, whereas you started working here just last month.\n";
    std::cout << '\n';
}

void Harl::error(void)
{
    std::cout << "[ERROR]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
    std::cout << '\n';
}

typedef void (Harl::*ptrToMemFunc)(void);

void Harl::complain(std::string level)
{
    static const std::string levels[LVL_AMNT] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    static const ptrToMemFunc functions[LVL_AMNT] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < LVL_AMNT; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
};