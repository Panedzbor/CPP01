#pragma once
#ifndef HARL_H
#define HARL_H

# include <string>
# include <iostream>

# define LVL_AMNT 4

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        void complain(std::string level);
};

#endif