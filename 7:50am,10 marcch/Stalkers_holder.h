#ifndef STALKERS_HOLDER_H_INCLUDED
#define STALKERS_HOLDER_H_INCLUDED

#include <array>
#include <cstdio>
#include <vector>

class Stalkers_holder{
    int num_of_stalkers {};  // number of stalkers on grid
    std::vector<std::array<double,2>> coords_of_stalkers {}; // coordinates of all stalkers for the detect thingy

public:

    void setNum(int num); //set how many stalkers on grid
    int getNum(); //return number of stalkers on grid
    void print_Coords_list(); //print coordinates of stalkers on grid
    std::vector<std::array<double,2>> getCoords_list(); //return coordinates of stalkers on grid
    void update_coords(std::array<double,2> coords, int id); //add coordinates of stalker into the vector

};

#endif // STALKERS_HOLDER_H_INCLUDED
