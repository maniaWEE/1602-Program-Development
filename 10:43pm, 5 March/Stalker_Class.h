#ifndef STALKER_CLASS_H_INCLUDED
#define STALKER_CLASS_H_INCLUDED

#include <array>
#include <cstdio>
#include <vector>



class Stalker{
    int num_of_stalkers {3};  // fixed number
    int horrorLevel = 0;      // Depletion %: 1 --> 12%, 2 --> 10%, 3  --> 8%

    std::vector<std::array<double,2>> coords_of_stalkers {}; // coordinates of all stalkers for the detect thingy
    std::array<double,2> coords_of_stalker {0.0, 0.0}; // for movement of stalker

public:

    int getNum();
    void print_Coords_list();
    std::vector<std::array<double,2>> getCoords_list();
    void generateCoords_Draw(FILE* plot); // similar to Parasite

    void StalkerSetUp();

    int loseResources(int currentR, int horrorLevel); // Stalker resource drop
    void movestalker(FILE* plot, int id); //move Stalker

};

#endif
