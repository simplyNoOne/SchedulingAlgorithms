#include "FCFS.h"

FCFS::FCFS()
{
}

void FCFS::addProcess(Process* procToAdd)
{
	Process* proc = new Process(*procToAdd);
	queue.push(proc);
}

void FCFS::simCycle(long long int time)
{
	current = nullptr;
	if (!queue.empty()) {
		current = queue.front();
		Algorithm::simCycle(time);
	}
	else if (bSpawningFinished)
		bAlgorithmFinished = true;
}

void FCFS::processFinished()
{
	totalSwitches++;
	delete queue.front();
	queue.pop();
}
