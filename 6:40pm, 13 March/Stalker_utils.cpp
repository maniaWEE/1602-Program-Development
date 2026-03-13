#include "Stalker_Class.h"
#include "Gnuplot.h"
#include <iostream>
#include <random>
#include <cmath>
#include <algorithm>

const double pi = std::numbers::pi;

// Stalker random movement
void Stalker::moveStalker()
{
    // Generating a random angle
    static std::random_device rd; // gives a random seed
    static std::mt19937 gen(rd()); // Use that random seed to generate many random numbers
    std::uniform_real_distribution<double> dist(0, 2*pi);
    double angle = dist(gen);

    double x = stalkerCurrentCoords[0];
    double y = stalkerCurrentCoords[1];

    // Move survivor by a magnitude of 2 in a random direction & update coords
    stalkerCurrentCoords[0] = std::clamp(x + (2*std::cos(angle)), -25.0, 25.0);
    stalkerCurrentCoords[1] = std::clamp(y + (2*std::sin(angle)), -25.0, 25.0);
}


// Resource depletion
int Stalker::depleteResources(int currentResources)
{
    //std::cout << "Current Resources: " << currentResources << std::endl;
    int newResources = static_cast<int>(currentResources * (1.0 - 0.1));
    //std::cout << "New Resources: " << newResources << std::endl;
    return newResources;
    // Add more if gonna vary
}

std::array<double, 2> Stalker::getCoords(){
    return stalkerCurrentCoords;
}

void Stalker::printCoords(){
    std::cout << "Stalker Coords: (" << stalkerCurrentCoords[0] << ", " << stalkerCurrentCoords[1] << ")" << std::endl;
    }

void Stalker::resetStalker(){
    stalkerCurrentCoords = {};
}
