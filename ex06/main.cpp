#include "Harl.hpp"

int main(int argc, char* argv[])
{
    Harl H;
    std::string msgTypes[LVL_AMNT] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    if (argc != 2)
    {
        std::cout << "Run the program with a paramenter!\n";
        return (1);
    }
    int i;
    for (i = 0; i < LVL_AMNT; i++)
    {
        if (argv[1] == msgTypes[i])
            break;
    }
    switch (i)
    {
        case 0: 
            H.complain("DEBUG");
            /* fall through */
        case 1: 
            H.complain("INFO");
            /* fall through */
        case 2: 
            H.complain("WARNING");
            /* fall through */
        case 3: 
            H.complain("ERROR");
            break;
        default: 
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
    return (0);
}