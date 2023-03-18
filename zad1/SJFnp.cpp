#include "SJFnp.h"
#include <algorithm>

SJFnp::SJFnp(long int num) : Algorithm(num)
{
    name = "SJFnp (Shortest Job First, non-preemptive)";
}

void SJFnp::addProcess(Process* procToAdd)
{
    Process* proc = new Process(*procToAdd);
    queue.emplace(proc);
}

void SJFnp::simCycle(long long int time)
{
    if (!queue.empty()) {
        if (!current) {
            it = queue.begin();
            current = *it;
            totalSwitches++;
        }
        Algorithm::simCycle(time);
    }
    else if (bSpawningFinished)
        finish();
}

void SJFnp::processFinished()
{
    Algorithm::processFinished();
    queue.erase(it);
    delete current;
    current = nullptr;
}

inline void SJFnp::spawnFinished()
{
    Algorithm::spawnFinished();
    std::cout << "remaining processes " << queue.size() << std::endl;
}
