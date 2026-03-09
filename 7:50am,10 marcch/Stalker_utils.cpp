#include "Stalker_Class.h"
#include "Gnuplot.h"
#include <iostream>
#include <random>
#include <cmath>
#include <algorithm>

constexpr double pi = 3.14159265;

void Stalker::StalkerSetUp(){
    // horrorLevel random
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> horrorDist(1,3);

    horrorLevel = horrorDist(gen);
    coords_of_stalker = {0.0, 0.0};
}

// Stalker random movement
void Stalker::movestalker(FILE* plot, int id)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_real_distribution<double> angle_rand(0, 2 * pi);

    double angle = angle_rand(gen);

    coords_of_stalker[0] += 10 * std::cos(angle); // Fix 10 step length
    coords_of_stalker[1] += 10 * std::sin(angle);

    drawCircle(plot, 20000 + id, coords_of_stalker, "stalker");

    //Clamp cuz flying everywhere
    coords_of_stalker[0] = std::clamp(coords_of_stalker[0], -50.0, 50.0);
    coords_of_stalker[1] = std::clamp(coords_of_stalker[1], -50.0, 50.0);
}

int Stalker::getHorror(){
    return horrorLevel;
}

// Resource depletion
int Stalker::loseResources(int currentR, int horrorLevel)
{
    int newR = 0;
    if (horrorLevel == 1){ // if stalker is horrorLevel=1 --> 12% resource lose
        newR = static_cast<int>(currentR * (1.0 - 0.12));
    }

    else if (horrorLevel == 2){// if stalker is horrorLevel=2 --> 10% resource lose
        newR = static_cast<int>(currentR * (1.0 - 0.12));
    }

    else{
        newR = static_cast<int>(currentR * (1.0 - 0.08));// if stalker is horrorLevel=3 --> 8% resource lose
    }

    return newR;
}

std::array<double,2> Stalker::get_Coords(){
    return coords_of_stalker;
}
