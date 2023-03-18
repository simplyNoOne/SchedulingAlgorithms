#include "SJFp.h"

SJFp::SJFp(int num) : Algorithm(num)
{
    name = "SJFp (Shortest Job First, preemptive)";
}

void SJFp::addProcess(Process* procToAdd)
{
    Process* proc = new Process(*procToAdd);
    queue.push(proc);
}

void SJFp::simCycle(long long int time)
{    
    if (!queue.empty()) {
        if (current != queue.top()) {
            if (current)
                current->pauseExecution(time);
            totalSwitches++;
            current = queue.top();
        }
        Algorithm::simCycle(time);
    }
    else if (bSpawningFinished)
        finish();
}

void SJFp::processFinished()
{
    Algorithm::processFinished();
    delete queue.top();
    queue.pop();
    current = nullptr;
}

void SJFp::spawnFinished()
{
    Algorithm::spawnFinished();
    std::cout << "remaining processes " << queue.size() << std::endl;
}
