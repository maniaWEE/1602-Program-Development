#include <iostream>
#include <array>
#include <cstdio>
#include <string>
#include <format>

#include "Gnuplot.h"

FILE* setup(){
    // Open a pipe to a gnuplot process for writing commands
    FILE* gnuPlot = popen("\"C:/Program Files/gnuplot/bin/gnuplot.exe\"", "w");

    // Check if the pipe opened successfully
    if (!gnuPlot) {
        perror("popen failed");
        return NULL;
    }

    // wxt is an interactive GUI window using wxWidgets library
    // noraise prevents the GUI window from being automatically brought to the front
    fprintf(gnuPlot, "set term wxt noraise\n");

    // Configure the plotting area
    fprintf(gnuPlot, "set xrange [-50:50] \n"); // X-axis limits from -50 to 50
    fprintf(gnuPlot, "set yrange [-50:50] \n"); // Y-axis limits from -50 to 0
    //fprintf(gnuPlot, "set xrange [-10:10]\n");   // X-axis limits from -10 to 10
    //fprintf(gnuPlot, "set yrange [-10:10]\n");   // Y-axis limits from -10 to 10
    fprintf(gnuPlot, "set size ratio -1\n");     // Keep equal scaling on both axes
    fprintf(gnuPlot, "set xtics 5\n");           // Tick marks every 1 unit on X-axis
    fprintf(gnuPlot, "set ytics 5\n");           // Tick marks every 1 unit on Y-axis
    fprintf(gnuPlot, "set grid xtics ytics\n");  // Show grid lines for both axes

    // Initialize an empty plot
    fprintf(gnuPlot, "plot NaN notitle\n");

    // Command for C++ to flush the output stream (of the gnuplot pipeline)
    fflush(gnuPlot);

    // Return the handle to the plot window (otherwise you lose it when the function returns)
    return gnuPlot;
}

// =============== PARASITE/BACKPACK/STALKER/SURVIVOR ====================================
void drawCircle(FILE* plot, int id, std::array<double, 2> coords, std::string type){
    std::string command_line {};

    for (char &c : type) {
        //convert all uppercase
        c = std::toupper(static_cast<unsigned char>(c));
    }

    std::string color {};
    double radius {};

    if (type == "PARASITE"){
        color = "#8B4513";
        radius = 0.8;
    }
    else if (type == "RESOURCE"){
        color = "green";
        radius = 1.2;
    }
    else if (type == "SURVIVOR"){
        color = "blue";
        radius = 2;
    }
    else if (type == "STALKER"){
        color = "red";
        radius = 2;
    }
    else{
        std::cout << "how does this even happen? check ur spelling" << std::endl;
        color = "black";
        radius = 10;
    }

    // Command for instructing the gnuplot application to draw a circle at location battery
    command_line = std::format("set object {} circle at {}, {} radius {} fillcolor rgb \"{}\" fillstyle solid\n", id, coords[0], coords[1], radius, color);
    fprintf(plot, command_line.c_str());

    // Command for instructing the gnuplot application to update the figure
    fprintf(plot, "replot\n");

    // Command for C++ to flush the output stream (of the gnuplot pipeline)
    fflush(plot);
}

void drawLine(FILE* plot, std::array<double, 2> P1, std::array<double, 2> P2){
    std::string command_line {};

    // Command for instructing the gnuplot application to draw a circle at location P1
    command_line = std::format("set object circle at {}, {} radius char 0.5 fillcolor rgb 'black' fillstyle solid\n", P1[0], P1[1]) ;
    fprintf(plot, command_line.c_str());

    // Command for instructing the gnuplot application to draw a circle at location P2
    command_line = std::format("set object circle at {}, {} radius char 0.5 fillcolor rgb 'red' fillstyle solid\n", P2[0], P2[1]) ;
    fprintf(plot, command_line.c_str());

    // Command for instructing the gnuplot application to draw an arrow from P1 to P2
    command_line = std::format("set arrow from {}, {} to {}, {} head size screen 0.02,20 lw 1\n", P1[0], P1[1], P2[0], P2[1]) ;
    fprintf(plot, command_line.c_str());

    // Command for instructing the gnuplot application to update the figure
    fprintf(plot, "replot\n");

    // Command for C++ to flush the output stream (of the gnuplot pipeline)
    fflush(plot);
}

void removeBatt(FILE* plot){
    fprintf(plot, "unset object 999\n"); //remove object 999 --> battery

    // Command for instructing the gnuplot application to update the figure
    fprintf(plot, "replot\n");

    // Command for C++ to flush the output stream (of the gnuplot pipeline)
    fflush(plot);
}
