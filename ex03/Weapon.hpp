#pragma once
#ifndef WEAPON_H
#define WEAPON_H

# include <string>

class Weapon {
    private:
        std::string type;
    public:
        Weapon() : type("") {};
        Weapon(std::string type) : type(type) {};
        const std::string&  getType(void) const;
        void                setType(std::string type);
};

#endif