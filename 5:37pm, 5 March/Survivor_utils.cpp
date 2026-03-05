#include <cstdio>
#include <iostream>
#include <string>
#include <format>
#include <array>
#include <random>
#include <cmath>
#include <algorithm>

#include "Survivor_Class.h"
#include "Gnuplot.h"

constexpr double pi = 3.14159265;

voide Survivor::SurvivorSetup()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> stepDist(5, 20);
    std::uniform_int_distribution<int> immunityDist(1, 3);
    std::uniform_int_distribution<int> healthDist(50, 100);

    step_length = stepDist(gen);
    immunity = immunityDist(gen);
    maxhealth = healthDist(gen);

    coords_of_survivor = {0.0, 0.0};
}

void Survivor::getCoord_of_survivor() {
    std::cout << "x coord: " << coords_of_survivor[0] << " y coord: " << coords_of_survivor[1] << std::endl; // Change back when u use
}
/*
int Survivor::getStep_length() {
    return step_length ;
}
*/
int Survivor::getImmunity() {
    return immunity ;
}
int Survivor::getmaxHealth() {
    return maxhealth ;
}
int Survivor::getcurrentHealth() {
    return currenthealth ;
}

/*
void Survivor::randStep_length(){
    static std::random_device rd;         // Step 1: random seed
    static std::mt19937 gen(rd());        // Step 2: engine
    std::uniform_int_distribution<int> step_lengthrand(5, 15);  // Step 3: distribution for step length from 5-15
    step_length = step_lengthrand(gen);
}

void Survivor::randHealth(){
    static std::random_device rd;         // Step 1: random seed
    static std::mt19937 gen(rd());        // Step 2: engine
    std::uniform_int_distribution<int> healthrand(50, 100);
}

void Survivor::randImmunity(){
    static std::random_device rd;         // Step 1: random seed
    static std::mt19937 gen(rd());        // Step 2: engine
    std::uniform_int_distribution<int> immunityrand(1, 3);  // Step 3: distribution for step length from 5-15
}
*/

double Survivor::movesurvivor(FILE* plot, int id){
    static std::random_device rd;         // Step 1: random seed
    static std::mt19937 gen(rd());        // Step 2: engine
    std::uniform_real_distribution<double> angle_rand(0, 2 * pi);

    double angle = angle_rand(gen);

    double x = coords_of_survivor[0];
    double y = coords_of_survivor[1];
    double new_x = x + (step_length*std::cos(angle));
    double new_y = y + (step_length*std::sin(angle));

    coords_of_survivor[0] = new_x;
    coords_of_survivor[1] = new_y;

    // Calculate distance per step
    double changeX = new_x - x;
    double changeY = new_y - y;
    double distance = sqrt(changeX*changeX + changeY*changeY);

    total_distance += distance;
    x = new_x;
    y = new_y;

    std::cout << coords_of_survivor[0] << " " << coords_of_survivor[1] << std::endl;

    // reminder remember what id belongs to which survivor, 3 ids = 3 survivors
    drawCircle(plot, 10000+id, coords_of_survivor, "survivor");

    //Clamp cuz flying everywhere
    coords_of_survivor[0] = std::clamp(coords_of_survivor[0], -50.0, 50.0);
    coords_of_survivor[1] = std::clamp(coords_of_survivor[1], -50.0, 50.0);
    return distance;
}

 double Survivor::getTotalDistance(){//Get distance covered at the end
     return total_distance;
}

void Survivor::GetInfo(){
    std::cout << "StepLength: " << step_length << std::endl;
    std::cout << "Immunity: " << immunity << std::endl;
    std::cout << "MaxHealth: " << maxhealth << std::endl;
    std::cout << "Current Health: " << currenthealth << std::endl;
}

void Survivor::setHealth(int newHealth){
    currenthealth = newHealth;
    }

bool Survivor::detect_Hit(std::vector<std::array<double,2>> coords_list, double radius){
    //if collide with a stalker/resource/parasite, return true, if not return false

    for (size_t i = 0; i < coords_list.size(); i++){
        //iterate thru each stalker/resource/parasite (type)
        //calc dist between survivor and type
        double dist_between = std::sqrt( std::pow( (coords_of_survivor[0]-coords_list[i][0]) , 2)
                                       + std::pow( (coords_of_survivor[1]-coords_list[i][1]) , 2) );
        if (dist_between <= radius){
            return true; // return true, function immediately finishes
        }
    }
    //managed to get out of iterating ALL points, means no collision
    return false;
}






