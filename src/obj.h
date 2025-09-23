#ifndef OBJ_H
#define OBJ_H

#define OBJ_COUNT 256 
#define UI_COUNT 128
#include <raylib.h>
#include "ui.h"
#include "player.h"
#include "enemy.h"

typedef struct
{
    struct
    {
        float ratio;
        int offset;
    }x;
    struct
    {
        float ratio;
        int offset;
    }y;

}GameVector;

typedef enum 
{
    
    TYPE_FRAME,
    TYPE_BUTTON,
    TYPE_TEXT,
    TYPE_PLAYER,
    TYPE_PLANET
}objtype;

struct FrameExtra
{

    Color BackroundColor; 
    short BackgroundTransparency;
    long parentid;
};

struct ButtonExtra 
{
    Color BackgroundColor;
    short BackGroundTransparency;
    short TextTransparency;
    Color TextColor;
    char *text;
    long parentid;
};

struct TextExtra 
{
    Color TextColor;
    short TextTransparency;
    char *text;
    long parentid;
};

typedef enum
{
    Iron,
    Gold,
    Diamond
}OreType;

struct Mine
{
    
    OreType type;

    float weight;

};

struct PlanetExtra
{
    Mine Ores[3]; /*MAXIMUM 3 ORES IN ONE PLANET*/

};


struct PlayerExtra
{

   PlayerState state;
   int hp;
   long coin;
   GameVector Speed;

};

typedef union
{
    struct FrameExtra;
    struct ButtonExtra;
    struct TextExtra;
    struct PlayerExtra;
    struct PlanetExtra;
}ObjExtras;

typedef struct 
{
    
    GameVector Position,Size;

    objtype type;

}CoreObj;  /*Core Materials of a physical object, rather than an ui object.*/

typedef struct 
{
    
    CoreObj core;
    ObjExtras extra;


}Object;        /*combining both core and the type's own properties resulting in a whole object */

typedef struct 
{

    Object obj[OBJ_COUNT];
    Object UI[UI_COUNT];

    long objid[OBJ_COUNT];

}Explorer;


#endif
