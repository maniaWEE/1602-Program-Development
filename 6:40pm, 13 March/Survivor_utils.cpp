#include "Survivor_Class.h"
#include "gnuplot.h"
#include <iostream>
#include <random>
#include <array>
#include <cmath>
#include <numbers>

// Survivor Methods Implementation

const double pi = std::numbers::pi;

void Survivor::increaseStepLength(){
    stepLength += 1;
}

double Survivor::moveSurvivor(){ // Survivor takes step in a random direction (according to step length)

    // Generating a random angle
    static std::random_device rd; // gives a random seed
    static std::mt19937 gen(rd()); // Use that random seed to generate many random numbers
    std::uniform_real_distribution<double> dist(0, 2*pi);
    double angle = dist(gen);

    double x = survivorCurrentCoords[0];
    double y = survivorCurrentCoords[1];

    // Move survivor by a magnitude of stepLength in a random direction & update coords
    survivorCurrentCoords[0] = std::clamp(x + (stepLength*std::cos(angle)), -25.0, 25.0);
    survivorCurrentCoords[1] = std::clamp(y + (stepLength*std::sin(angle)), -25.0, 25.0);

    // Calculate distance between the two points and add it to the totalDistance
    double changeInX = survivorCurrentCoords[0] - x;
    double changeInY = survivorCurrentCoords[1] - y;
    double distance = sqrt(changeInX*changeInX + changeInY*changeInY);
    totalDistance += distance;
    return totalDistance;
}

void Survivor::setHealth(int currentHealth){
    health = currentHealth;
}

int Survivor::getHealth(){
    return health;
}

int Survivor::getStepLength(){
    return stepLength;
}

void Survivor::resetSurvivor(){
    health = 100; // Initial Health = 100 (max health)
    immunityLevel = 1;
    survivorCurrentCoords = {};
    totalDistance = 0;
}

bool Survivor::detectHitStalker(std::array<double, 2> stalker){ // Input stalker coordinates in array form
    double dist_between = std::sqrt( std::pow( (survivorCurrentCoords[0]-stalker[0]) , 2) + std::pow( (survivorCurrentCoords[1]-stalker[1]) , 2) );
    //std::cout << "distance between stalker: " << dist_between <<std::endl;

    if (dist_between <= 2){ //point is within circle, collided
        return true;
    }
    else{
        return false; //battery and point did not collide
    }
}
bool Survivor::detectHitParasite(std::vector<std::array<double,2>> coords_list){
    //if collide with a stalker/resource/parasite, return true, if not return false

    for (size_t i = 0; i < coords_list.size(); i++){
        //iterate thru each stalker/resource/parasite (type)
        //calc dist between survivor and type
        double dist_between = std::sqrt( std::pow( (survivorCurrentCoords[0]-coords_list[i][0]) , 2)
                                       + std::pow( (survivorCurrentCoords[1]-coords_list[i][1]) , 2) ) - 2;

        //std::cout << "distance between parasite: " << dist_between <<std::endl;
        if (dist_between <= 5){ // Radius of parasite is 1
            return true; // return true if survivor in range
        }
    }

    //managed to get out of iterating ALL points, means no collision --> returns false
    return false;
}

bool Survivor::detectHitResource(std::vector<std::array<double,2>> coords_list){ // Same to help with logic flow
    //if collide with a stalker/resource/parasite, return true, if not return false

    for (size_t i = 0; i < coords_list.size(); i++){
        //iterate thru each stalker/resource/parasite (type)
        //calc dist between survivor and type
        double dist_between = std::sqrt( std::pow( (survivorCurrentCoords[0]-coords_list[i][0]) , 2)
                                       + std::pow( (survivorCurrentCoords[1]-coords_list[i][1]) , 2) ) - 2;

        //std::cout << "distance between resource: " << dist_between <<std::endl;
        if (dist_between <= 5){ // Radius of parasite is 2
            return true; // return true if survivor in range
        }
    }

    //managed to get out of iterating ALL points, means no collision --> returns false
    return false;
}

std::array<double, 2> Survivor::getCoords(){
    return survivorCurrentCoords;
}

void Survivor::printCoords(){
    std::cout << "Survivor Coords: (" << survivorCurrentCoords[0] << ", " << survivorCurrentCoords[1] << ")" << std::endl;
    }

int Survivor::getTotalDistance(){
    return totalDistance;
}
