#ifndef SHOP_H

#define SHOP_H

#include "obj.h"

/*Main tools*/
struct Pickaxe
{
    float mineSpeed;
    int mineLevel; /*hard-to-break rocks needs high level*/
}; /*mining tool, it can be anything not only pickaxe*/

struct Weapon
{
    float attack;
    float range;
    float attackSpeed;
};

struct Armor
{
    float flatDefense;
    float percentagDefense;
};
/*Shop features*/
typedef union
{
    struct Pickaxe pickaxe;
    struct Weapon weapon;
    struct Armor armor;
}Tools;

typedef struct Deal
{
    Tools tool;
    int price;
    int sellprice;
    float sale; /*for events*/
}Deal;

typedef struct Stocks
{
    Deal* deals;
    int size;
}Stocks;





#endif
