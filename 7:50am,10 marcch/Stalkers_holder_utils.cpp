#include "Stalkers_holder.h"
#include "Gnuplot.h"
#include <iostream>
#include <random>
#include <cmath>
#include <algorithm>

void Stalkers_holder::setNum(int num){
    num_of_stalkers = num;
}

int Stalkers_holder::getNum(){
    return num_of_stalkers;
}

void Stalkers_holder::print_Coords_list(){
    std::cout << "Coordinates of all Stalkers present:" << std::endl;
    for (size_t i = 0; i < static_cast<size_t>(getNum()); i++){
        //print out coords of each stalker
        std::cout << "{" << coords_of_stalkers[i][0] << "," << coords_of_stalkers[i][1] << "}" << std::endl;
    }
}

std::vector<std::array<double,2>> Stalkers_holder::getCoords_list(){
    //return coordinates of stalkers on grid
    return coords_of_stalkers;
}

void Stalkers_holder::update_coords(std::array<double,2> coords, int id){
    //add coordinates of stalker into the vector
    if ( static_cast<size_t>(id) > coords_of_stalkers.size() ){
        //does not exist, add it in
        coords_of_stalkers.push_back(coords);
    }
    else{
        //it does exist, update it only
        coords_of_stalkers[static_cast<size_t>(id-1)] = coords;
    }
}
