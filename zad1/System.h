#pragma once
#include <vector>
#include <queue>
#include <list>

#include <random>
#include "Process.h"
class Algorithm;


class System
{
private:
	Process* tempProcess;
	std::vector<Algorithm*> algorithms;

	//settings
	const long totalProc = 200'000;		//how many processes to spawn
	const int RRquant = 30;
	const double shortPercent = 0.8;	//how many of them should be short...
	const double longPercent = 0.07;		//...or long
	const double spawnPercent = 0.05;		//what is a chance of spawning a process each cycle

	//logic
	int numProcToSpawn;
	long int time;
	bool bSimulationFinished;
	bool bSpawningFinished;

public:
	System();
	~System();

	void runSim();
	void printResults();		

private:
	ProcessType randomPT();
	bool spawnProcess();
};

