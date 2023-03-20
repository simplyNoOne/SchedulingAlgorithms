#include "SJFp.h"

SJFp::SJFp(int num) : Algorithm(num)
{
    name = "SJFp (Shortest Job First, preemptive)";
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
            if (current)
                current->pauseExecution(time);
            totalSwitches++;
            current = *queue.begin();
        }
        Algorithm::simCycle(time);
    }
    else if (bSpawningFinished)
        finish();
}

void SJFp::processFinished()
{
    Algorithm::processFinished();
    delete *queue.begin();
    queue.erase(queue.begin());
    current = nullptr;
}

void SJFp::spawnFinished()
{
    Algorithm::spawnFinished();
    std::cout << "remaining processes " << queue.size() << std::endl;
}
