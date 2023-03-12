#pragma once
#include "Algorithm.h"
#include <queue>

class FCFS : public Algorithm
{
public:
	FCFS();
private:
	std::queue<Process*> queue;

public:

	virtual void addProcess(Process* procToAdd) override;
	virtual void simCycle(long long int time) override;
	virtual void processFinished() override;
};

