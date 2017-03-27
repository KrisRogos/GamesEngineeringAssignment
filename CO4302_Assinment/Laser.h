#pragma once

struct Laser
{
    // position
    float locX;
    float locY;
#ifdef CONSOLE_3D
    float locZ;
#endif

    // angle, currently only on a 2D XY plane
    float angleZ;

};