#ifndef PLAYER_H

#define PLAYER_H

#include "obj.h"


typedef enum
{
    Idle,
    Mining,
    InBattle,
    Defeated,
    Won,
}PlayerState;



typedef struct 
{
    GameVector Position; 
    GameVector Size;
    GameVector Speed;
    PlayerState state;
    int hp;
    long coin;

}Player;



#endif
