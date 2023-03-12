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
protected:
	//logic
	bool bAlgorithmFinished = false;
	bool bSpawningFinished = false;
	Process* current;
public:
	virtual void addProcess(Process* procToAdd) = 0;
	inline void spawnFinished() { bSpawningFinished = true; }
	inline virtual void simCycle(long long int time) {
		if (!current)
			return;
		current->Execute(time); 
		if (current->isFinished())
			processFinished();
	}
	virtual void processFinished() = 0;
	inline bool isFinished() { return bAlgorithmFinished; }

	
};

struct ShorterJob {
	bool operator()(Process const* p1, Process const* p2) {
		//if true, p1 will be before p2
		return p1->timeLeft < p2->timeLeft;
	}
};