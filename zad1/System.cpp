#include "System.h"


#include <iostream>
#include <random>
#include "Process.h"
#include "Algorithm.h"
#include "FCFS.h"
#include "SJFnp.h"
#include "SJFp.h"
#include "RR.h"


System::System()
{
    numProcToSpawn = totalProc;

    time = 0;
    bSimulationFinished = false;

    algorithms.push_back(new FCFS());
    algorithms.push_back(new SJFp());
    algorithms.push_back(new SJFnp());
  //  algorithms.push_back(new RR());
       
}

System::~System()
{
    }

void System::runSim()
{
  //  while (!SJFdone || !FCFSdone || !RRdone) {
    while (!bSimulationFinished) {
        time++;
        int finishedAlgs{};
        if (numProcToSpawn >= 0) {
            if (spawnProcess())
                numProcToSpawn--;
        }
        for each (Algorithm * a in algorithms) {
            a->simCycle(time);
            if (a->isFinished())
                finishedAlgs++;
        }
        if (finishedAlgs == algorithms.size())
            bSimulationFinished = true;

    }
    std::cout << "donaoieh\n";
}

void System::printResults()
{
}

ProcessType System::randomPT()
{
    std::normal_distribution normD{ 0.2, 1.3 };
    double prob = normD(gen);
    ProcessType pt;

    if (prob <= 0 || prob > 1)
        return PT_none;
    if (prob < 0.4)
        pt = PT_short;
    else if (prob < 0.7)
        pt = PT_medium;
    else
        pt = PT_long;
    return pt;
}

bool System::spawnProcess()
{
    if (numProcToSpawn == 0){
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







