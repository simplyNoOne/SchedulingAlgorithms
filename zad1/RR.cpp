#include "RR.h"

RR::RR()
{
	leftQuant = quant;
	it = queue.begin();
}

void RR::addProcess(Process* procToAdd)
{
	Process* proc = new Process(*procToAdd);
	queue.insert(proc);
}

void RR::simCycle(long long int time)
{
	if (!queue.empty()) {
		if (!current) {
			it = queue.begin();
			current = *it;		//will only happen once during the start of the algorithm.
		}
		if (leftQuant == 0) {
			leftQuant = quant;
			totalSwitches++;
			it++;
			if (it == queue.end())
				it = queue.begin();
			current = *it;
		}
		leftQuant--;
		Algorithm::simCycle(time);
	}
	else if (bSpawningFinished)
		bAlgorithmFinished = true;
}

void RR::processFinished()
{
	//first, we move the iterator, so that it will continute pointing to a valid object
	it++;
	if (it == queue.end())
		it = queue.begin();
	totalSwitches++;
	delete current;		
	queue.erase(current);		//then we delete the pointer and the set shrinks, it points now to a valid place one index too far
	if (queue.size() == 0) {			//there might be the case, where we just removed the last element
		current = nullptr;
		return;
	}
	if (it != queue.begin())
		it--;
	current = *it;
	//correction, if process finishes at the same time as quant. current is already assigned, so it would be skipped
	if (leftQuant == 0)
		leftQuant = quant;
}
