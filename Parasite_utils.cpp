#include <cstdio>
#include <iostream>
#include <string>
#include <format>
#include <array>
#include <random>

#include "Parasite_Class.h"
#include "Gnuplot.h"

int Parasite::getNum(){
    return  num_of_parasites;
}

void Parasite::increaseNum(){
    num_of_parasites += 1;
}

void Parasite::generateCoords_Draw(FILE* plot){
    //generate new coordinates and drawings

    static std::random_device rd;         // Step 1: random seed
    static std::mt19937 gen(rd());        // Step 2: engine

    std::uniform_real_distribution<double> x(-50, 50);  // Step 3: distribution for x
    std::uniform_real_distribution<double> y(-50, 50);  // Step 3: distribution for y

    //since this is being called, reset the coords list
    coords_of_parasites = {};

    for (int i = 0; i <  num_of_parasites; i++){
        //for each parasite
        std::array<double,2> coords = {x(gen), y(gen)}; //generate the x,y coords
        coords_of_parasites.push_back(coords); //add into coords list
        int id = i+1; //for circle object id

        drawCircle(plot, id, coords, "parasite");
    }
}

void Parasite::print_Coords_list(){
    std::cout << "Coordinates of all Parasites present:" << std::endl;
    for (size_t i = 0; i < static_cast<size_t>(num_of_parasites); i++){
        //print out coords of each parasite
        std::cout << "{" << coords_of_parasites[i][0] << "," << coords_of_parasites[i][1] << "}" << std::endl;
    }
}

std::array<double,2> Parasite::getCoords_of(size_t index){
    //get coords for a specific parasite
    return {coords_of_parasites[index][0], coords_of_parasites[index][1]};
}

int Parasite::deduct_Health(int immunity_level, int surv_current_hp){
    //returns deducted health fot that survivor
    switch (immunity_level){
        case 1: //level 1
            return surv_current_hp - 13; // deduct 13 health
        case 2: //level 1
            return surv_current_hp - 9; // deduct 9 health
        default:
            std::cout << "DID U PUT SOMETHING ELSE??????, fuck u." << std::endl;
            return surv_current_hp - 10000; //kys
    }
}
