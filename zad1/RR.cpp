#include "RR.h"

RR::RR()
{
	leftQuant = quant;
}

void RR::addProcess(Process* procToAdd)
{
	Process* proc = new Process(*procToAdd);
	queue.push_back(proc);
}

void RR::simCycle(long long int time)
{
	if (!queue.empty()) {
		if (!current)
			current = queue.front();
		if (leftQuant == 0) {
			leftQuant = quant;
			totalSwitches++;
			current = queue.front();
		}
		leftQuant--;
		Algorithm::simCycle(time);
	}
	else if (bSpawningFinished)
		bAlgorithmFinished = true;
}

void RR::processFinished()
{
}
