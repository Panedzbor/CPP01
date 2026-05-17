#include "ZombieList.hpp"

int ZombieList::total = 0;
ZombieList* ZombieList::head = NULL;

ZombieList::ZombieList(Zombie *ptr)
{
    this->ptr = ptr;
    if (!head)
    {
        head = this;
        this->prev = NULL;
    }
    else
    {
        ZombieList *cur = head;
        while (cur->next)
            cur = cur->next;
        this->prev = cur;
    }
    if (this->prev)
        this->prev->next = this;
    this->next = NULL;
    total++;
}

ZombieList::~ZombieList()
{
    if (this->prev)
        this->prev->next = this->next;
    if (this->next)
        this->next->prev = this->prev;
    if (this == head)
        head = this->next;
    delete this->ptr;
    this->ptr = NULL;
    this->prev = NULL;
    this->next = NULL;
    total--;
}

ZombieList* addNewZombie(Zombie *ptr)
{
    ZombieList *new_zombie;

    new_zombie = new ZombieList(ptr);
    return (new_zombie);
}

void ZombieList::destroyZombie(void)
{
    delete this;
}

int ZombieList::get_total(void)
{
    return (total);
}

Zombie* ZombieList::findZombie(int index)
{
    ZombieList *cur = head;
    
    for (int count = 0; count != index; count++)
        cur = cur->next;
    return (cur->ptr);
}

ZombieList* ZombieList::findZombie(Zombie *z)
{
    ZombieList *cur;
    
    for (cur = head; cur->ptr != z; cur = cur->next)
    {
        if (!cur)
            break;
    }
    return (cur);
}

void ZombieList::displayAll(void)
{
    int i = 0;
    
    if (!head)
    {
        std::cout << "No zombies created yet\n\n";
        return ;
    }
    std::cout << "Now all zombies put your hands up in the air! \n\n";
    for (ZombieList *cur = head; cur; cur = cur->next, i++)
    {
        std::cout << std::setw(7) << i + 1 << ". ";
        cur->ptr->announce();
    }
    std::cout << '\n';
}