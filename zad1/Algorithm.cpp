#include "Algorithm.h"
#include <sstream>
#include <iomanip>

void Algorithm::spawnFinished()
{
	 bSpawningFinished = true; 
	 std::cout<<name<<": executed: " << executed << std::endl;
}

void Algorithm::simCycle(long long int time)
{
	if (!current)
		return;
	current->tick(time);
	if (current->isFinished())
		processFinished();
}

void Algorithm::processFinished()
{
	executed++;
	totalTotalWaitTime += current->totalWaitTime;
	totalInitWaitTime += current->initWaitTime;
	totalExecutionTime += current->executionTime;
	totalProcessingTime += current->processingTime;
	if(current->bStarved)
		totalStarved++;
}

void Algorithm::finish()
{
	bAlgorithmFinished = true;
	meanInitWaitTime = totalInitWaitTime / numProcesses;
	meanTotalWaitTime = totalTotalWaitTime / numProcesses;
	meanExecutionTime = totalExecutionTime / numProcesses;
	meanProcessingTime = totalProcessingTime / numProcesses;
}

std::string Algorithm::results()
{
	std::stringstream res;
	res << std::fixed << std::setprecision(2) << std::setw(45) << std::left << this->name + ":" << std::right << "|";
	res << std::setw(15) << this->totalSwitches << " |";
	res << std::setw(15) << this->totalStarved << " |";
	res << std::setw(15) << this->meanInitWaitTime << " |";
	res << std::setw(15) << this->meanTotalWaitTime << " |";
	res << std::setw(15) << this->meanProcessingTime << " |";
	res << std::setw(15) << this->meanExecutionTime << " |";
	return res.str();
}
