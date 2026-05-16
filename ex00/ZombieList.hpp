#pragma once
#ifndef ZOMBIELIST_H
#define ZOMBIELIST_H

# include "Zombie.hpp"
# include "iomanip"

class ZombieList {
    private:
        Zombie              *ptr;
        ZombieList          *next;
        ZombieList          *prev;
        static ZombieList   *head;
        static int          total;
        ZombieList();
    public:
        ZombieList(Zombie *ptr);
        ~ZombieList();
        void                destroyZombie(void);
        static int          get_total(void);
        static Zombie       *findZombie(int index);
        static ZombieList   *findZombie(Zombie *z);
        static void         displayAll(void);
};

ZombieList *addNewZombie(Zombie *ptr);

#endif

