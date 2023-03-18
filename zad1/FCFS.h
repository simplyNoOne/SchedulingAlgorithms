#pragma once
#include "Algorithm.h"
#include <queue>

class FCFS : public Algorithm
{
public:
	FCFS(long int num);

private:
	std::queue<Process*> queue;

public:
	virtual void addProcess(Process* procToAdd) override;
	virtual void simCycle(long long int time) override;
	virtual void processFinished() override;
	virtual void spawnFinished();
	virtual void finish() override;
};

