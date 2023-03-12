#pragma once
#include <vector>
#include <queue>
#include <list>

#include <random>
#include "Process.h"
class Algorithm;


class System
{
public :
	//stats
	const long totalProc = 100'000;
	long numProcToSpawn;
	

	long long int time;
	bool bSimulationFinished;

	Process* tempProcess;
	std::vector<Algorithm*> algorithms;
	
	//for randoms
	std::random_device rd{};
	std::mt19937 gen{ rd() };

	System();
	~System();


	void runSim();
	void printResults();

	ProcessType randomPT();
	bool spawnProcess();


};

