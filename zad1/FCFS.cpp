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
	if (!queue.empty()) {
		if (!current) {
			current = queue.front();
			totalSwitches++;
		}
		Algorithm::simCycle(time);
	}
	else if (bSpawningFinished)
		bAlgorithmFinished = true;
}

void FCFS::processFinished()
{
	current = nullptr;
	delete queue.front();
	queue.pop();
}
