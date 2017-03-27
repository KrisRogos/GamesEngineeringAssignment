#include <iostream>
#include <string>
#include <array>
#include <stdlib.h>
#include <ctime>
#include <chrono>

#include "Definitions.h"
#include "RandomUtility.h"
#include "Circle.h"

#define TIME_RES microseconds
#define TIME_STR " microseconds"

const uint_fast32_t k_CircleCount = 100; // number of circles to be simulated

const float k_GenerationLimitX = 1000.0f; // positive world size in X, negative is calculated from this
const float k_GenerationLimitY = 1000.0f; // positive world size in Y, negative is calculated from this
#ifdef CONSOLE_3D 
const float k_GenerationLimitZ = 1000.0f; // positive world size in Z, negative is calculated from this
#endif

const float k_VelociyLimitX = 5.0f; // positive velocity X limit, negative is calculated from this
const float k_VelociyLimitY = 5.0f; // positive velocity Y limit, negative is calculated from this
#ifdef CONSOLE_3D 
const float k_VelociyLimitZ = 5.0f; // positive velocity Z limit, negative is calculated from this
#endif

void SetUp (std::array<Circle, k_CircleCount> & arr)
{
    // randomly position and size the objects in world space
    for (auto itr : arr)
    {
        // position
        itr.locX = RandomFloat (-k_GenerationLimitX, k_GenerationLimitX);
        itr.locY = RandomFloat (-k_GenerationLimitY, k_GenerationLimitY);
#ifdef CONSOLE_3D
        itr.locZ = RandomFloat (-k_GenerationLimitZ, k_GenerationLimitZ);
#endif

        // size
        itr.rad = 1.0f;

        // velocity
        itr.velocityX = RandomFloat (-k_VelociyLimitX, k_VelociyLimitX);
        itr.velocityY = RandomFloat (-k_VelociyLimitY, k_VelociyLimitY);
#ifdef CONSOLE_3D
        itr.velocityZ = RandomFloat (-k_VelociyLimitZ, k_VelociyLimitZ);
#endif
        // colour
        itr.R = 1.0f;
        itr.G = 1.0f;
        itr.B = 1.0f;

        // other parameters
        itr.life = 100;
        itr.name = "circle";
    }
}

int main ()
{
    auto timeBegin = std::chrono::high_resolution_clock::now ();
    std::cout << "program start\n";


    std::srand (std::time (NULL)); // set up the random seed

    // generate the circles
    std::array<Circle, k_CircleCount> r_Circles;

    auto timeStart = std::chrono::high_resolution_clock::now ();
    SetUp (r_Circles);
    auto timeEnd = std::chrono::high_resolution_clock::now ();

    std::cout << "Programmed finished in " << std::chrono::duration_cast<std::chrono::TIME_RES>(timeEnd - timeBegin).count () <<
        TIME_STR << "\nThe circle generation itself took " << std::chrono::duration_cast<std::chrono::TIME_RES>(timeEnd - timeStart).count () <<
        TIME_STR << "\n";
    
    system ("pause");

}