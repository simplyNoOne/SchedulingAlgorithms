#pragma once
#include "Algorithm.h"
#include <set>
#include <queue>


class SJFp : public Algorithm
{
public:
	SJFp(int num);

private:
	std::priority_queue<Process*, std::vector<Process*>, ShorterJob> queue;

public:
	virtual void addProcess(Process* procToAdd) override;
	virtual void simCycle(long long int time) override;
	virtual void processFinished() override;
	virtual void spawnFinished();
};

