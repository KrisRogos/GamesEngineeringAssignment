#include <string>
#include "Definitions.h"

struct Circle
{
    // position
    float locX;
    float locY;
#ifdef CONSOLE_3D
    float locZ;
#endif
    
    // size
    float rad;
    
    // speed
    float velocityX;
    float velocityY;
#ifdef CONSOLE_3D
    float velocityZ;
#endif

    // colour
    float R;
    float G;
    float B;

    // life
    int life;

    // identifiers
    std::string name;

};