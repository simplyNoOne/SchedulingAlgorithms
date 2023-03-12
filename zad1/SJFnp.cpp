#include "SJFnp.h"

SJFnp::SJFnp()
{
}

void SJFnp::addProcess(Process* procToAdd)
{
    Process* proc = new Process(*procToAdd);
    queue.push(proc);
}

void SJFnp::simCycle(long long int time)
{
    if (!queue.empty()) {
        if (!current)
            current = queue.top();
        Algorithm::simCycle(time);
    }
    else if (bSpawningFinished)
        bAlgorithmFinished = true;
}

void SJFnp::processFinished()
{
    //totalWaitTime += current->waitTime;
    totalSwitches++;
    delete queue.top();
    queue.pop();
    if(!queue.empty())
        current = queue.top();
}
