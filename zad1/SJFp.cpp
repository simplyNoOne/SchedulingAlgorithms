#include "SJFp.h"

SJFp::SJFp()
{
}

void SJFp::addProcess(Process* procToAdd)
{
    Process* proc = new Process(*procToAdd);
    queue.push(proc);
}

void SJFp::simCycle(long long int time)
{    
    if (!queue.empty()) {
        if (current != queue.top())
            totalSwitches++;
        current = queue.top();
        Algorithm::simCycle(time);
    }
    else if (bSpawningFinished)
        bAlgorithmFinished = true;
}

void SJFp::processFinished()
{
    delete queue.top();
    queue.pop();
}
