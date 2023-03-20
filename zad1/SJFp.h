#pragma once
#include "Algorithm.h"
#include <set>


class SJFp : public Algorithm
{
public:
	SJFp(int num);

private:
	std::multiset<Process*, ShorterJob> queue;

public:
	virtual void addProcess(Process* procToAdd) override;
	virtual void simCycle(long long int time) override;
	virtual void processFinished() override;
	virtual void spawnFinished();
};

