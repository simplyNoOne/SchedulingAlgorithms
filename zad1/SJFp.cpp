#include "SJFp.h"

SJFp::SJFp()
{
}

void SJFp::addProcess(Process* procToAdd)
{
    Process* proc = new Process(*procToAdd);
    queue.insert(proc);
}

void SJFp::simCycle(long long int time)
{    
    if (!queue.empty()) {
        if (current != *queue.begin()) {
            totalSwitches++;
            current = *queue.begin();
        }
        Algorithm::simCycle(time);
    }
    else if (bSpawningFinished)
        bAlgorithmFinished = true;
}

void SJFp::processFinished()
{
    delete current;
    queue.erase(current);
    current = nullptr;
}
