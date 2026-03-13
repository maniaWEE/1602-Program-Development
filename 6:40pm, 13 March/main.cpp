#include "Survivor_Class.h"
#include "Parasite_Class.h"
#include "BackPack_Class.h"
#include "Stalker_Class.h"
#include "Gnuplot.h"

#include <iostream>
#include <random>
#include <array>
#include <cmath>
#include <numbers>

#include <thread>   // for sleep_for
#include <chrono>   // for seconds


const double pi = std::numbers::pi;

// Graph axis labels thingy
std::vector<int> stepLengthGraph = {};
std::vector<int> distanceGraph = {};

int main()
{
    Survivor survivor; // create Aqeelah object of class Survivor
    Stalker stalker; // create Liyana object of class Stalker
    Parasite parasites; // create parasites object of class Parasite
    Backpack backpack; //create backpack object of class Backpack

    for (int i=0; i<20; i++){ // Running through 10 simulations, increasing step length by 1 each time
        survivor.resetSurvivor();
        backpack.resetBackpack();
        parasites.resetParasite();;
        stalker.resetStalker();


        backpack.generateCoords();
        parasites.generateCoords();
        bool done = false;

        while (!done) {

            if (backpack.getResources() >= 100){
                stepLengthGraph.push_back(survivor.getStepLength()); // Push back step length only if win
                std::cout << "WIN" << std::endl;
                distanceGraph.push_back(survivor.getTotalDistance());
                done = true;
            }
            else{
                if (survivor.getHealth() <= 0){
                    std::cout << "LOSE U IDIOT" << std::endl;
                    done = true; // end the loop
                }

                else{
                    //parasites.print_Coords_list();

                    //backpack.print_Coords_list();

                    stalker.moveStalker(); // Spawn stalker
                    //stalker.printCoords();

                    survivor.moveSurvivor(); // Spawn survivor
                    //survivor.printCoords();


                    // Check if stalker hit or not
                    if (survivor.detectHitStalker(stalker.getCoords()) == true){
                        // Resources will deplete
                        backpack.update_resources(stalker.depleteResources(backpack.getResources()));
                    }

                    //std::cout << "Before Health: " << survivor.getHealth() << std::endl;

                    // Check if stalker hit or not
                    if (survivor.detectHitParasite(parasites.getCoords_list()) == true){
                        // Reduce Health
                        survivor.setHealth(parasites.deduct_Health(survivor.getHealth()));
                        parasites.increaseNum();
                        parasites.generateCoords();
                        //std::cout << "After Health: " << survivor.getHealth() << std::endl;
                    }

                    //std::cout << "Old Resources: " << backpack.getResources() << std::endl;
                    if (survivor.detectHitResource(backpack.getCoords_list()) == true){
                        backpack.picked_up_resources();
                        backpack.generateCoords(); // Spawn new resources after collecting old resource
                        //std::cout << "New Resources: " << backpack.getResources() << std::endl;
                    }

                    // Make decision to heal or not
                    survivor.setHealth(backpack.make_decision(survivor.getHealth()));

                }
            }

        }

        survivor.increaseStepLength();
    }

    for (size_t i = 0; i < stepLengthGraph.size(); i++){
        std::cout << "StepLength: " << stepLengthGraph[i] << std::endl;
    }

    for (size_t i = 0; i < distanceGraph.size(); i++){
        std::cout << "Distance: " << distanceGraph[i] << std::endl;
    }

    std::cout << "Points to plot stepLength: " << stepLengthGraph.size() << std::endl;
    std::cout << "Points to plot distance: " << distanceGraph.size() << std::endl;

    FILE* gnuplot = popen("C:/Progra~1/gnuplot/bin/gnuplot.exe", "w");

    if (!gnuplot){
        std::cout<<"Error opening gnuplot";
        return 1;
    }


    //Tell gnuplot we will send inline data
    fprintf(gnuplot,"plot '-' with linespoints\n");

    //Send x y values
    for(size_t i=0;i<stepLengthGraph.size();i++){
        fprintf(gnuplot,"%d %d\n",stepLengthGraph[i],distanceGraph[i]);
    }

    //End data stream
    fprintf(gnuplot,"e\n");

    fflush(gnuplot);

    std::cin.get();

    pclose(gnuplot);

    return 0;

}



