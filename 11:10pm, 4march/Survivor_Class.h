#ifndef SURVIVOR_CLASS_H_INCLUDED
#define SURVIVOR_CLASS_H_INCLUDED

#include <array>
#include <random>
#include <cmath>

class Survivor
{

public:
    std::array<double, 2> coords_of_survivors {0,0};
    int step_length = 0; // Integer from 3-8
    int immunity = 0;
    int health = 0;

    // Constructor
    Survivor();

    // Calling Methods
    void getCoord_of_survivors() ;
    int getStep_length() ;
    int getImmunity() ;
    int getHealth();
    void randStep_length();
    void randHealth();
    void randImmunity();
    void movesurvivor(FILE* plot, int id);
    void setHealth(int newHealth);
    void GetInfo();

    bool detect_Hit(std::vector<std::array<double,2>> coords_list, double radius);

};
#endif // SURVIVOR_CLASS_H_INCLUDED
