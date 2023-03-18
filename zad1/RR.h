#pragma once
#include "Algorithm.h"
#include <queue>

class RR : public Algorithm
{
public:
	RR(int num, int quant);

private:
	std::queue <Process*>queue;
	int quant;
	int leftQuant;

public:

	virtual void addProcess(Process* procToAdd) override;
	virtual void simCycle(long long int time) override;
	virtual void processFinished() override;
	virtual void finish() override; 
	virtual void spawnFinished() override; 
};

