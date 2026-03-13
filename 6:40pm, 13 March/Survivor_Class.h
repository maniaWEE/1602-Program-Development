#ifndef SURVIVOR_CLASS_H_INCLUDED
#define SURVIVOR_CLASS_H_INCLUDED

#include <random>
#include <array>
#include <cmath>
#include <numbers>
#include <cstdio>

// Survivor Class Declaration

class Survivor {

    int health {100}; // Initial Health = 100 (max health)
    int stepLength {1}; // Variable
    int immunityLevel {1};
    std::array<double, 2> survivorCurrentCoords {};
    double totalDistance {};

public:
    double moveSurvivor();
    bool detectHitStalker(std::array<double, 2> stalker);
    bool detectHitParasite(std::vector<std::array<double,2>> coords_list);
    bool detectHitResource(std::vector<std::array<double,2>> coords_list);
    void printCoords();
    void setHealth(int currentHealth);
    int getHealth();
    std::array<double, 2> getCoords();
    int getTotalDistance();
    void increaseStepLength();
    int getStepLength();
    void resetSurvivor();
};

#endif // SURVIVOR_CLASS_H_INCLUDED

