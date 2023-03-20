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
	//for set testing
	std::deque<int> arrivals = { 1, 2, 3, 5, 6 };
	std::deque<int> lengths = { 3, 8, 6, 4, 2};


	Process* tempProcess;
	std::vector<Algorithm*> algorithms;

	//settings
	const long totalProc = 100'000;		//how many processes to spawn
	const int RRquant = 70;
	const double shortPercent = 0.95;	//how many of them should be short...
	const double longPercent = 0.01;		//...or long
	const double spawnPercent = 0.02;		//what is a chance of spawning a process each cycle

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
};

