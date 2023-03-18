#include "RR.h"

RR::RR(int num, int quant) : Algorithm(num)
{
	name = "RR (Round Robin)";
	this->quant = quant;
	leftQuant = quant;
}

void RR::addProcess(Process* procToAdd)
{
	Process* proc = new Process(*procToAdd);
	queue.push(proc);
}

void RR::simCycle(long long int time)
{
	if (!queue.empty()) {
		if (!current) {
			leftQuant = quant;
			current = queue.front();
			totalSwitches++;
		}
		else if (leftQuant == 0) {
			leftQuant = quant;
			current->pauseExecution(time);
			queue.push(current);
			queue.pop();
			current = queue.front();
			totalSwitches++;
		}

		Algorithm::simCycle(time);
		leftQuant--;
	}
	else if (bSpawningFinished)
		finish();
}

void RR::processFinished()
{
	Algorithm::processFinished();
	delete current;
	queue.pop();
	current = nullptr;
}

void RR::finish() {
		Algorithm::finish();
		totalStarved = 0;
}
void RR::spawnFinished()
{
	Algorithm::spawnFinished();
	std::cout << "remaining processes " << queue.size() << std::endl;
}
