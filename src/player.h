#ifndef PLAYER_H

#define PLAYER_H

#include "obj.h"
#include "shop.h"


typedef enum
{
    Idle,
    Mining,
    InBattle,
    Defeated,
    Won,
}PlayerState;


typedef struct Equips{
    struct Pickaxe pickaxe;
    struct Weapon weapon;
    struct Armor armor;
}Equips;


#endif
