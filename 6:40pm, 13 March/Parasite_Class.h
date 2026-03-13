#ifndef PARASITE_CLASS_H_INCLUDED
#define PARASITE_CLASS_H_INCLUDED

#include <array>
#include <vector>

class Parasite{
    int num_of_parasites {5}; //initial number of parasite is 5
    std::vector<std::array<double,2>> coords_of_parasites {};

    public:
    //functions related to num_of_parasites
    int getNum(); //get num_of_parasites
    void increaseNum(); //increase num_of_parasites by 1

    //functions related to coords_of_parasites
    void print_Coords_list(); //print out coords of each parasite, for debugging
    std::vector<std::array<double,2>> getCoords_list();

    void generateCoords(); //generate new coordinates

    int deduct_Health(int currentHealth);
    /*pass thru getImmunity and getHp (whatever u call it into the argument)
    returns deducted health for that survivor
    so use it like:
    newhp = parasite.deduct_Health(survivor.getImmunity, survivor.getHp);
    survivor.setHp(newhp);
    or you can combine it into one line, ur choice
    */

    void resetParasite();
};
#endif // PARASITE_CLASS_H_INCLUDED
