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

	//for set testing
	bool bUseSet = false;
	std::deque<int> arrivals = { 1, 2, 3, 5, 6, 7};
	std::deque<int> lengths = { 3, 8, 6, 4, 2, 4};

	//settings
	long totalProc = 25'000;				//how many processes to spawn
	const double shortPercent = 0.60;		//how many of them should be short...
	const double longPercent = 0.10;		//...or long
	const double spawnPercent = 0.05;		//what is a chance of spawning a process each cycle
	const int RRquant = 70;					//quant for round robin

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
	void spawnSet(long long int time);
	void printIntro();
};

