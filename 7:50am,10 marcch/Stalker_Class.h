#ifndef STALKER_CLASS_H_INCLUDED
#define STALKER_CLASS_H_INCLUDED

#include <array>
#include <cstdio>
#include <vector>

class Stalker{
    int horrorLevel = 0;      // Depletion %: 1 --> 12%, 2 --> 10%, 3  --> 8%
    std::array<double,2> coords_of_stalker {0.0, 0.0}; // for movement of stalker

public:

    void StalkerSetUp();
    int getHorror();
    int loseResources(int currentR, int horrorLevel); // Stalker resource drop
    void movestalker(FILE* plot, int id); //move Stalker
    std::array<double,2> get_Coords(); //return coordinates of this specific stalker

};

#endif
