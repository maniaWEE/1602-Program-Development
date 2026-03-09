#include <cstdio>
#include <iostream>
#include <string>
#include <format>
#include <array>
#include <vector>

#include <thread>   // for sleep_for
#include <chrono>   // for seconds

#include "Parasite_Class.h"
#include "BackPack_Class.h"
#include "Survivor_Class.h"
#include "Stalker_Class.h"
#include "Stalkers_holder.h"
#include "Gnuplot.h"

double pi = 3.14159265;

int main()
{
    Parasite parasites; //create parasites object of class Parasite
    Backpack backpack; //create backpack object of class backpack
    Stalkers_holder stalkerS; //create stalkerS object of class Stalkers_holder

    // Declare survivors
    Survivor Sophia; //id 1
    Survivor Aqeelah; //id 2
    Survivor Alex; //id 3

    //set their stats --> step_length, immunity, max health
    Sophia.SurvivorSetUp();
    Aqeelah.SurvivorSetUp();
    Alex.SurvivorSetUp();

    Sophia.GetInfo();
    Aqeelah.GetInfo();
    Alex.GetInfo();

    // Declare stalkers
    Stalker stalker1;
    Stalker stalker2;
    Stalker stalker3;

    //set stalker stats --> horror level
    stalker1.StalkerSetUp();
    stalker2.StalkerSetUp();
    stalker3.StalkerSetUp();
    std::cout << "horror levels are: " << stalker1.getHorror() << stalker2.getHorror() << stalker3.getHorror() << std::endl;
    stalkerS.setNum(3);

    auto plot = setup();

    int n = 0;
    backpack.generateCoords_Draw(plot); // generate and draw first set of resources
    while (true){
        parasites.generateCoords_Draw(plot); // generate and draw parasites

        //move the stalkers
        stalker1.movestalker(plot, 1);
        stalkerS.update_coords(stalker1.get_Coords(), 1);

        stalker2.movestalker(plot, 2);
        stalkerS.update_coords(stalker2.get_Coords(), 2);

        stalker3.movestalker(plot, 3);
        stalkerS.update_coords(stalker3.get_Coords(), 3);

        stalkerS.print_Coords_list();

        //move the players
        Sophia.movesurvivor(plot, 1);
        Aqeelah.movesurvivor(plot, 2);
        Alex.movesurvivor(plot, 3);

        //Check for collision for each survivor
        if (Sophia.detect_Hit(stalkerS.getCoords_list(), 2) >= 0){
            int stalker_id = (Sophia.detect_Hit(stalkerS.getCoords_list(), 2) + 1);
            std::cout << "sophia hit stalker" << stalker_id << std::endl;
            switch (stalker_id){
                case 1:
                    backpack.update_resources(stalker1.loseResources(backpack.getResources(), stalker1.getHorror()));
                    break;
                case 2:
                    backpack.update_resources(stalker2.loseResources(backpack.getResources(), stalker2.getHorror()));
                    break;
                case 3:
                    backpack.update_resources(stalker3.loseResources(backpack.getResources(), stalker3.getHorror()));
            }
        }
        if (Aqeelah.detect_Hit(stalkerS.getCoords_list(), 2) >= 0){
            int stalker_id = (Aqeelah.detect_Hit(stalkerS.getCoords_list(), 2) + 1);
            std::cout << "aqeelah hit stalker" << stalker_id << std::endl;
            switch (stalker_id){
                case 1:
                    backpack.update_resources(stalker1.loseResources(backpack.getResources(), stalker1.getHorror()));
                    break;
                case 2:
                    backpack.update_resources(stalker2.loseResources(backpack.getResources(), stalker2.getHorror()));
                    break;
                case 3:
                    backpack.update_resources(stalker3.loseResources(backpack.getResources(), stalker3.getHorror()));
            }
        }
        if (Alex.detect_Hit(stalkerS.getCoords_list(), 2) >= 0){
            int stalker_id = (Alex.detect_Hit(stalkerS.getCoords_list(), 2) + 1);
            std::cout << "alex hit stalker" << stalker_id << std::endl;
            switch (stalker_id){
                case 1:
                    backpack.update_resources(stalker1.loseResources(backpack.getResources(), stalker1.getHorror()));
                    break;
                case 2:
                    backpack.update_resources(stalker2.loseResources(backpack.getResources(), stalker2.getHorror()));
                    break;
                case 3:
                    backpack.update_resources(stalker3.loseResources(backpack.getResources(), stalker3.getHorror()));
            }
        }
        std::cout << "resources left: " << backpack.getResources();

        std::cin.get();   // waits for Enter
        std::cin.ignore();

        // Wait for 0.15 second
        //std::this_thread::sleep_for(std::chrono::duration<double>(0.15));

        n++;
    }

    std::cout << "Press Enter to end terminal/GNUPlot" << std::endl;
    std::cin.get();   // waits for Enter
    pclose(plot);


    return 0;
}
