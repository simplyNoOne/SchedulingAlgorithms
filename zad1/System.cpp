#include "System.h"

#include <iomanip>
#include <iostream>
#include <random>
#include "Process.h"
#include "Algorithm.h"
#include "FCFS.h"
#include "SJFnp.h"
#include "SJFp.h"
#include "RR.h"

using std::cout, std::endl;

System::~System()
{
    for each (Algorithm* a in algorithms)
    {
        delete a;
    }
}

System::System()
{
    numProcToSpawn = totalProc;

    time = 0;
    bSimulationFinished = false;
    bSpawningFinished = false;

    algorithms.push_back(new FCFS(numProcToSpawn));
    algorithms.push_back(new SJFp(numProcToSpawn));
    algorithms.push_back(new SJFnp(numProcToSpawn));
    algorithms.push_back(new RR(numProcToSpawn, RRquant));
}


void System::runSim()
{
    while (!bSimulationFinished) {
        time++;
        int finishedAlgs{};
        if (!bSpawningFinished) {
            if (spawnProcess())
                numProcToSpawn--;
        }
        for each (Algorithm* a in algorithms) {
            a->simCycle(time);
            if (a->isFinished())
                finishedAlgs++;
        }
        if (finishedAlgs == algorithms.size())
            bSimulationFinished = true;
    }
}

void System::printResults()
{
    cout << "Long: "<< Process::numLong << "\tMedium: " << Process::numMed << "\tShort: " << Process::numShort<<"\n";

    cout << std::setw(160) << std::setfill('_') << " \n" << std::setfill(' ');

    cout << std::fixed << std::setprecision(2) << std::setw(45) << std::left << "Name:" << std::right << "|";
    cout << std::setw(15) << "Switches" << " |";
    cout << std::setw(15) << "Starved" << " |";
    cout << std::setw(15) << "Init Wait" << " |";
    cout << std::setw(15) << "Total Wait" << " |";
    cout << std::setw(15) << "Processing" << " |";
    cout << std::setw(15) << "Execution" << " |\n";

    cout<<std::setw(160) << std::setfill('_')<<" \n";

    for each (Algorithm* a in algorithms)
    {
        std::cout << std::endl;
        std::cout << a->results()<<std::endl;

    }
    cout << std::setw(160) << std::setfill('_') << " \n";
}

ProcessType System::randomPT()
{
    if (rand() % 1000 > spawnPercent*1000)
        return PT_none;
    double prob = (double) rand() / RAND_MAX;
    ProcessType pt;
    if (prob < shortPercent)
        pt = PT_short;
    else if (prob < 1 - longPercent)
        pt = PT_medium;
    else
        pt = PT_long;
    return pt;
}

bool System::spawnProcess()
{
    if (numProcToSpawn == 0){
        bSpawningFinished = true;
        for each (Algorithm * a in algorithms)
        {
            a->spawnFinished();
        }
        return false;
    }
    ProcessType pt = randomPT();
    if (pt == PT_none)
        return false;
    tempProcess = new Process(time, pt);
    for each (Algorithm* a in algorithms)
    {
        a->addProcess(tempProcess);
    }
    delete tempProcess;
    return true;
}






