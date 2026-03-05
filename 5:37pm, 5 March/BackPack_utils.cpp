#include <cstdio>
#include <iostream>
#include <string>
#include <format>
#include <array>
#include <random>
#include <cmath>

#include "BackPack_Class.h"
#include "Gnuplot.h"

int Backpack::getResources(){
    return resources;
}

void Backpack::picked_up_resources(){
    resources += 1;
}

void Backpack::generateCoords_Draw(FILE* plot){
    //generate new coordinates

    //since this is being called, reset the coords list
    coords_of_resources = {};

    static std::random_device rd;         // Step 1: random seed
    static std::mt19937 gen(rd());        // Step 2: engine

    std::uniform_real_distribution<double> x(-50, 50);  // Step 3: distribution for x
    std::uniform_real_distribution<double> y(-50, 50);  // Step 3: distribution for y

    //BUT FIRST, generate how many to have
    std::uniform_real_distribution<double> num(3, 12); //distribution for no. of resources can appear
    int resources_on_grid = num(gen); //how many resources to put on grid

    for (int i = 0; i < resources_on_grid; i++){
        //for each resource
        std::array<double,2> coords = {x(gen), y(gen)}; //generate the x,y coords
        coords_of_resources.push_back(coords); //add into coords list
        int id = i + 5000; //for circle object id

        drawCircle(plot, id, coords, "resource");
    }
}

void Backpack::print_Coords_list(){
    std::cout << "Coordinates of all Resources present:" << std::endl;
    for (size_t i = 0; i < coords_of_resources.size(); i++){
        //print out coords of each resource
        std::cout << "{" << coords_of_resources[i][0] << "," << coords_of_resources[i][1] << "}" << std::endl;
    }
}

std::array<double,2> Backpack::getCoords_of(size_t index){
    //get coords for a specific resource
    if (index > coords_of_resources.size()){
        return {0,0}; //how the fuck is there an index out of its range
    }
    else{
        return {coords_of_resources[index][0], coords_of_resources[index][1]};
    }
}

int Backpack::use_heal(int currenthp){
    //use 5 units of resource to hel 3 units of health
    resources -= 5;
    return currenthp+3;
}

int Backpack::make_decision(double currenthp, double maxhp){
    //get true or false to heal or not
    if (resources > 5){
        //there is enough to heal
        static std::random_device rd;         // Step 1: random seed
        static std::mt19937 gen(rd());        // Step 2: engine

        //using Sigmoid Function
        double H =  currenthp / maxhp;
        double a = 10.0; //steepness
        double b = 0.46; //threshold --> more than b, probabily decrease alot, less than b, probability increase alot

        double healProbability = 1.0 / (1.0 + std::exp(a * (H - b)));
        std::cout << "Heal Probability: " << healProbability << std::endl;
        std::bernoulli_distribution healChance(healProbability);

        if (healChance(gen)){
            std::cout << "Decided to heal" << std::endl;
            return use_heal(currenthp);
        }
        else{
            std::cout << "Decided NOT to heal" << std::endl;
            return currenthp;
        }
    }
    else{
        std::cout << "Not enough resources to heal" << std::endl;
        return currenthp;
    }
}

std::vector<std::array<double,2>> Backpack::getCoords_list(){
    return coords_of_resources;
}

