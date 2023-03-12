#pragma once
#include "Algorithm.h"
#include <list>
#include <unordered_set>

class RR : public Algorithm
{
public:
	RR();
private:
	std::unordered_set<Process*> queue;
	std::unordered_set<Process*>::iterator it;
	const int quant = 20;
	int leftQuant;

	

public:

	virtual void addProcess(Process* procToAdd) override;
	virtual void simCycle(long long int time) override;
	virtual void processFinished() override;
};

