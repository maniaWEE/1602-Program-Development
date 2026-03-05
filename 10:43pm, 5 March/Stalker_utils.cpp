#include "Stalker_Class.h"
#include "Gnuplot.h"
#include <iostream>
#include <random>
#include <cmath>
#include <algorithm>

constexpr double pi = 3.14159265;


int Stalker::getNum(){ //gets number of parasites
    return  num_of_stalkers;
}

void Stalker::print_Coords_list(){
    std::cout << "Coordinates of all Stalkers present:" << std::endl;
    for (size_t i = 0; i < Stalker::getNum(); i++){
        //print out coords of each stalker
        std::cout << "{" << coords_of_stalkers[i][0] << "," << coords_of_stalkers[i][1] << "}" << std::endl;
    }
}

void Stalker::generateCoords_Draw(FILE* plot){
    //generate new coordinates and drawings

    static std::random_device rd;         // Step 1: random seed
    static std::mt19937 gen(rd());        // Step 2: engine

    std::uniform_real_distribution<double> x(-50, 50);  // Step 3: distribution for x
    std::uniform_real_distribution<double> y(-50, 50);  // Step 3: distribution for y

    //since this is being called, reset the coords list
    coords_of_stalkers = {};

    for (int i = 0; i <  Stalker::getNum(); i++){
        //for each stalker
        std::array<double,2> coords = {x(gen), y(gen)}; //generate the x,y coords
        coords_of_stalkers.push_back(coords); //add into coords list
        int id = i+1; //for circle object id

        drawCircle(plot, id, coords, "parasite");
    }
}

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

std::vector<std::array<double,2>> Stalker::getCoords_list(){
    return coords_of_stalkers;
}
