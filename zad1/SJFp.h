#pragma once
#include "Algorithm.h"
#include <set>


class SJFp : public Algorithm
{
public:
	SJFp();

private:
	
	std::set<Process*, ShorterJob> queue;

public:
	virtual void addProcess(Process* procToAdd) override;
	virtual void simCycle(long long int time) override;
	virtual void processFinished() override;
};

