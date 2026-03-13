#ifndef STALKER_CLASS_H_INCLUDED
#define STALKER_CLASS_H_INCLUDED

#include <array>
#include <cstdio>
#include <vector>

class Stalker{
    int horrorLevel = 10;      // Depletion of resource by 10% upon coming in contact with survivor
    std::array<double,2> stalkerCurrentCoords {}; // for movement of stalker

public:
    void moveStalker();
    int depleteResources(int currentResources);
    void printCoords();
    std::array<double, 2> getCoords();
    void resetStalker();

};

#endif
