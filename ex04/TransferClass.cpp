#include "TransferClass.hpp"

TransferClass::TransferClass(std::string filename) : filename(filename) {}

bool TransferClass::openIFile(void)
{
    file.open(filename.c_str());
    return (file.is_open());
}

bool TransferClass::openOFile(void)
{
    std::string outname = filename + ".replace";
    replaceFile.open(outname.c_str());
    return (replaceFile.is_open());
}

void TransferClass::replaceContent(std::string s1, std::string s2)
{
    size_t s1len = s1.length();
    size_t linelen;

    if (!s1len)
        return;
    while (std::getline(file, line))
    {
        std::string newLine = "";
        size_t      cur_index = 0;
        size_t      match = 0;
        
        linelen = line.length();
        while ((match = line.find(s1, cur_index)) != std::string::npos)
        {
            newLine += line.substr(cur_index, match - cur_index);
            newLine += s2;
            cur_index = match + s1len;
        }
        newLine += line.substr(cur_index, linelen - cur_index);
        replaceFile << newLine << '\n';
    }
}