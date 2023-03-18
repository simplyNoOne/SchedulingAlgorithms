// zad1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <cmath>
#include "System.h"
#include <random>
#include "Process.h"

int main(){
    System system;

    std::cout << std::endl;

    system.runSim();
    
    system.printResults();
    return 0;
}


