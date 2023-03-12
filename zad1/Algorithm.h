#pragma once
#include "Process.h"

class Algorithm
{
public:
	//stats
	long long int totalInitWaitTime{};
	long long int totalTotalWaitTime{};
	long long int totalExecutionTime{};		
	long long int totalProcessingTime{};
	long long int totalSwitches{};

	long long int meanInitWaitTime{};
	long long int meanTotalWaitTime{};
	long long int meanExecutionTime{};
	long long int meanProcessingTime{};

protected:
	//logic
	long int numProcesses;
	bool bAlgorithmFinished = false;
	bool bSpawningFinished = false;
	Process* current;

public:
	virtual void addProcess(Process* procToAdd) = 0;
	inline void spawnFinished() { bSpawningFinished = true; }
	virtual void simCycle(long long int time);
	
	virtual void processFinished();
	inline bool isFinished() { return bAlgorithmFinished; }
	
};

struct ShorterJob final{
	bool operator()(Process const* p1, Process const* p2) const {
		//if true, p1 will be before p2
		return p1->timeLeft < p2->timeLeft;
	}
};