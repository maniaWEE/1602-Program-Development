#ifndef BACKPACK_CLASS_H_INCLUDED
#define BACKPACK_CLASS_H_INCLUDED

#include <array>
#include <vector>

class Backpack{
    int resources {0}; //initiall at zero
    std::vector<std::array<double,2>> coords_of_resources {};

public:
    //functions related to num_of_parasites
    int getResources(); //get num of resources
    void picked_up_resources(); //increase num of resources by 1

    //functions related to coords_of_resources
    void print_Coords_list(); //print out coords of each resource, for debugging
    std::array<double,2> getCoords_of(size_t index); //get coords for a specific resource in {x,y} format

    void generateCoords_Draw(FILE* plot); //generate new coordinates and draw it, MUST RUN ONCE BEFORE MAIN PROG FOR FIRST SET OF RESOURCES

    //to interact with survivor
    int make_decision(double currenthp, double maxhp); //return new health of survivor
    /*currenthp is where u put .getHp for ur survivor, maxhp is the max health survivor had
    so use it like:
    newhp = backpack.make_decision(survivor.getHp, survivor.maxHp);
    survivor.setHp(newhp);
    or you can combine it into one line, ur choice
    */

    int use_heal(int currenthp); //return new health of survivor after healing and updates resources for make_decision
    //dont use this, use make_decision
};

#endif // BACKPACK_CLASS_H_INCLUDED
