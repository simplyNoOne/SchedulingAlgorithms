#pragma once
#include "Algorithm.h"
#include <list>

class RR : public Algorithm
{
public:
	RR();
private:
	const int quant = 20;
	int leftQuant;
	std::list<Process*> queue;

public:

	virtual void addProcess(Process* procToAdd) override;
	virtual void simCycle(long long int time) override;
	virtual void processFinished() override;
};

