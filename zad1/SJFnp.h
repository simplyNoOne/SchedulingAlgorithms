#pragma once
#include "Algorithm.h"

#include <queue>


class SJFnp : public Algorithm
{
public:
	SJFnp();
private:
	std::priority_queue<Process*, std::vector<Process*>, ShorterJob> queue;

public:
	virtual void addProcess(Process* procToAdd) override;
	virtual void simCycle(long long int time) override;
	virtual void processFinished() override;
};

