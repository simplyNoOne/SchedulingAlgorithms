#pragma once
#include "Algorithm.h"

#include <set>


class SJFnp : public Algorithm
{
public:
	SJFnp(long int num);

private:
	std::multiset<Process*, ShorterJob> queue;
	std::multiset<Process*, ShorterJob>::iterator it;

public:
	virtual void addProcess(Process* procToAdd) override;
	virtual void simCycle(long long int time) override;
	virtual void processFinished() override;
	virtual void spawnFinished();
};

