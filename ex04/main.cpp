#include "TransferClass.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Please run the program with 3 arguments: ./replace <filename> <str_to_find> <replacement>\n";
        return (1);
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    TransferClass t(filename);
    if (t.openIFile() && t.openOFile())
        t.replaceContent(s1, s2);
    else
        std::cout << "Problem opening the file\n";
    return (0);
}