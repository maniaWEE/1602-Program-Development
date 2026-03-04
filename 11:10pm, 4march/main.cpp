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
#include "Gnuplot.h"

/*
void timestep(){
    //Press Enter Key for next timestep
    std::cout << "Proceed to Step?" << std::endl;
    std::cin.get();   // waits for Enter
}
*/
double pi = 3.14159265;

int main()
{
    Parasite parasites; //create parasites object of class Parasite
    Backpack backpack; //create backpack object of class backpack

    // Declare survivors
    Survivor survivor1;
    Survivor survivor2;
    Survivor survivor3;

    Stalker stalker1;
    Stalker stalker2;
    Stalker stalker3;

    // Declare stalkers

/*
    survivor1.GetInfo();//Just to see if random
    survivor2.GetInfo();
    survivor3.GetInfo();
*/



    int health = 0;
    auto plot = setup();

    // =============== PARASITE ====================================
    //testing the spread and let it run by itself
/*
    int i = 0;
    std::cout << "Parasite Spreader" << std::endl;
    while (i < 10){ //loop 10 times oni, if u wanna explore put more also can
        std::cout << parasites.getNum() << ",";
        parasites.generateCoords_Draw(plot);
        parasites.increaseNum();

        // Wait for 0.15 second
        std::this_thread::sleep_for(std::chrono::duration<double>(0.15));

        i++;
    }
    std::cout << parasites.getNum() << ",";
    std::cout << "\n\n";


    //testing the coords_of_parasites stuff
    parasites.generateCoords_Draw(plot);
    parasites.print_Coords_list();
    std::array<double, 2> placeholder = parasites.getCoords_of(1);
    std::cout << "{" << placeholder[0] << "," << placeholder[1] << "}" << std::endl;

    std::cout << "Press Enter to end terminal/GNUPlot" << std::endl;
    std::cin.get();   // waits for Enter
    pclose(plot);
*/


    // testing deduction
    //std::cout << "deducted survivor health: " << parasites.deduct_Health(2, 100) << std::endl;


    // =============== BACKPACK ====================================
    /* testing basic stuff
    std::cout << backpack.getResources();
    backpack.picked_up_resources();
    std::cout << backpack.getResources();
    */

    /*testing the coords_of_resources stuff, HOW TO USE IT FOR SPECIFIC SCENARIO OF TOUCHING RESOURCE
    char choice {};
    backpack.generateCoords_Draw(plot); //generate and draw the first set of resources
    backpack.print_Coords_list(); //print first set of resources
    std::array<double, 2> placeholder = backpack.getCoords_of(1);
    std::cout << "{" << placeholder[0] << "," << placeholder[1] << "}" << std::endl;

    while (true){
        std::cout << "survivor hit? Y/N: " << std::endl;
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 'Y'){
            //since hit, collect and generate new set of resources
            backpack.picked_up_resources();
            backpack.generateCoords_Draw(plot);
            backpack.print_Coords_list();
        }
        else{
            //havent hit, so current set stays
        }
    }
    */

    // testing Sigmoid Function
    //std::cout << "Health Now: " << backpack.make_decision(80, 100) << std::endl;

    // =============== FOR ELLE TO TEST OUT WITH YOUR OWN SURVIVOR FUNCTIONS ====================================
    //BTW you dont have to follow the way i write the survivor functions, i just showing how to use my shit with an Example

    //parasites.generateCoords_Draw(plot); //generate a set of parasites
    //backpack.generateCoords_Draw(plot); //generate a set of resources
/*
    //how to print coordinates of parasites and resources
    parasites.print_Coords_list();
    std::cout << "\n";
    backpack.print_Coords_list();

    //how to get coords of a specific parasites and resources
    std::array<double, 2> placeholder = backpack.getCoords_of(1); //resource of index 1
    std::cout << "Resource Coordinate: {" << placeholder[0] << "," << placeholder[1] << "}" << std::endl;
    placeholder = parasites.getCoords_of(1); //parasite of index 1
    std::cout << "Parasite Coordinate: {" << placeholder[0] << "," << placeholder[1] << "}" << std::endl;
*/

    //when collide with parasite --> set new health of survivor
    /*
    int newHp = parasite.deduct_Health(survivor.getImmunity, survivor.getHp);
    survivor.setHp(newHp);
    */
/*
    //when collide with resource, pick it up
    backpack.picked_up_resources(); //initially got zero resources
    std::cout << "Number of Resources: " << backpack.getResources() << std::endl; //print new num of resources
*/
    //make decision whether survivor use resource to heal and give the newhp / currenthp back if dont use to heal
    /*
    int newHp = parasite.deduct_Health(survivor.getImmunity, survivor.getHp);
    survivor.setHp(newHp);
    */

    //you are also gonna draw circles for stalker and survivor --> check gnuplot.h how to use drawCircle and also update the
    //drawCircle function in utils to have ur stuffs



// =============== STALKER ====================================
    //test stalker movement and resource depletion


    //testing the coords_of_stalkers stuff
    stalker1.generateCoords_Draw(plot); //initial pos
    stalker1.print_Coords_list();
    stalker2.generateCoords_Draw(plot); //initial pos
    stalker2.print_Coords_list();
    stalker3.generateCoords_Draw(plot); //initial pos
    stalker3.print_Coords_list();

while (true){
    stalker1.movestalker(plot, 1);
    stalker2.movestalker(plot, 2);
    stalker3.movestalker(plot, 3);

    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
    std::cout << "Press Enter to end terminal/GNUPlot" << std::endl;
    std::cin.get();   // waits for Enter
    pclose(plot);



    // resource loss test
    //std::cout << "deducted survivor health: " << parasites.deduct_Health(2, 100) << std::endl;

/*
    // Test Survivors Looping
    while (true){
    survivor1.movesurvivor(plot, 1);
    survivor2.movesurvivor(plot, 2);
    survivor3.movesurvivor(plot, 3);

    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
*/
    std::cout << "Press Enter to end terminal/GNUPlot" << std::endl;
    std::cin.get();   // waits for Enter
    pclose(plot);


    return 0;
}
