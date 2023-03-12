#include "Algorithm.h"

void Algorithm::simCycle(long long int time)
{
	if (!current)
		return;
	current->Execute(time);
	if (current->isFinished())
		processFinished();
}

void Algorithm::processFinished()
{
	totalTotalWaitTime += current->totalWaitTime;
	totalInitWaitTime += current->initWaitTime;
	totalExecutionTime += current->executionTime;
	totalProcessingTime += current->processingTime;
}
