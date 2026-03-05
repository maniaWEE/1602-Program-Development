#ifndef SURVIVOR_CLASS_H_INCLUDED
#define SURVIVOR_CLASS_H_INCLUDED

#include <array>
#include <random>
#include <cmath>

class Survivor
{

public:
    std::array<double, 2> coords_of_survivor {0,0};
    int step_length = 0; // Integer from 3-8
    int immunity = 0;
    int health = 0;
    double total_distance = 0;
    // Constructor
    Survivor();

    // Calling Methods
    void getCoord_of_survivor() ;
    int getStep_length() ;
    int getImmunity() ;
    int getHealth();
    void randStep_length();
    void randHealth();
    void randImmunity();
    double movesurvivor(FILE* plot, int id); // Returns distance travelled per step
    double getTotalDistance();
    void setHealth(int newHealth);
    void GetInfo();
    bool detect_Hit(std::vector<std::array<double,2>> coords_list, double radius);

};
#endif // SURVIVOR_CLASS_H_INCLUDED

