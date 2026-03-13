#include <cstdio>
#include <iostream>
#include <string>
#include <format>
#include <array>
#include <random>

#include "Parasite_Class.h"
#include "Gnuplot.h"

int Parasite::getNum(){ //gets number of parasites
    return  num_of_parasites;
}

void Parasite::increaseNum(){ //increases number of parasites
    num_of_parasites += 1;
}

void Parasite::generateCoords(){
    //generate new coordinates and drawings

    static std::random_device rd;         // Step 1: random seed
    static std::mt19937 gen(rd());        // Step 2: engine

    std::uniform_real_distribution<double> x(-25, 25);  // Step 3: distribution for x
    std::uniform_real_distribution<double> y(-25, 25);  // Step 3: distribution for y

    //since this is being called, reset the coords list
    coords_of_parasites = {};

    for (int i = 0; i <  num_of_parasites; i++){
        //for each parasite
        std::array<double,2> coords = {x(gen), y(gen)}; //generate the x,y coords
        coords_of_parasites.push_back(coords); //add into coords list

    }
}

void Parasite::print_Coords_list(){
    std::cout << "Coordinates of all Parasites present:" << std::endl;
    for (size_t i = 0; i < static_cast<size_t>(num_of_parasites); i++){
        //print out coords of each parasite
        std::cout << "{" << coords_of_parasites[i][0] << "," << coords_of_parasites[i][1] << "}" << std::endl;
    }
}

int Parasite::deduct_Health(int currentHealth){
    //returns deducted health for that survivor
    int newHealth = currentHealth - 10; // deduct 10 health for every parasite hit

    /* COMMENT FOR NOW JUST IN CASE WE USE LATER FOR ANOTHER GRAPH
    switch (immunity_level){
        case 1: //level 1
            newhp = surv_current_hp - 10; // deduct 10 health
            break;
        case 2: //level 2
            newhp = surv_current_hp - 7; // deduct 7 health
            break;
        case 3: //level 3
            newhp = surv_current_hp - 4; // deduct 4 health
            break;
        default:
            std::cout << "DID U PUT SOMETHING ELSE??????, fuck u." << std::endl;
            return surv_current_hp - 10000; //kys
    }
*/

    // Check if below zero or not
    if (newHealth < 0){
        newHealth = 0;
    }
    return newHealth;
}


std::vector<std::array<double,2>> Parasite::getCoords_list(){
    return coords_of_parasites;
}

void Parasite::resetParasite(){
    num_of_parasites = 5;
    coords_of_parasites = {};
}
