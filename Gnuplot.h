#ifndef GNUPLOT_H_INCLUDED
#define GNUPLOT_H_INCLUDED

#include <array>
#include <cstdio>
#include <string>
#include <format>

FILE* setup();

// =============== PARASITE/BACKPACK/STALKER/SURVIVOR ====================================
void drawCircle(FILE* plot, int id, std::array<double, 2> coords, std::string type);
//use it like drawCircle(plot, id, coords, "resource/survivor/stalker/parasite")
//id --> i for parasite, 5000+i for resource, 10000+i for survivor, 20000+i for stalker

void drawLine(FILE* plot, std::array<double, 2> P1, std::array<double, 2> P2);
void removeBatt(FILE* plot);

#endif // GNUPLOT_H_INCLUDED
