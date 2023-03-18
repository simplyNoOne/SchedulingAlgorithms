#include "FCFS.h"

FCFS::FCFS(long int num) : Algorithm(num)
{
	name = "FCFS (First Come First Served)";
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
		finish();
}

void FCFS::processFinished()
{
	Algorithm::processFinished();
	current = nullptr;
	delete queue.front();
	queue.pop();
}

inline void FCFS::spawnFinished()
{
	Algorithm::spawnFinished();
	std::cout << "remaining processes " << queue.size() << std::endl;
}

void FCFS::finish()
{
	Algorithm::finish(); 
	totalStarved = 0;
}
