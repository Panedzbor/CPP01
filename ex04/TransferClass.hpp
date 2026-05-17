#pragma once
#ifndef TRANSFERCLASS_H
#define TRANDFERCLASS_H

# include <fstream>
# include <iostream>
# include <string>

class TransferClass {
    private:
        std::string filename;
        std::ifstream file;
        std::ofstream replaceFile;
        std::string line;
        TransferClass();
    public:
        TransferClass(std::string filename) : filename(filename) {};
        bool openIFile(void);
        bool openOFile(void);
        void replaceContent(std::string s1, std::string s2);
};

#endif