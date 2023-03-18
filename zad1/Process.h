#pragma once

#include <stdio.h>
#include <iostream>
#include <memory>

enum ProcessType {
	//enum contains maximum durations for process types
	PT_none = 5,
	PT_short = 40,
	PT_medium = 90, 
	PT_long = 150
};

class Process
{
public:
	//settings
	const static int starvedMult = 10'000;

	//stats for quantity
	static int numLong;
	static int numMed;
	static int numShort;

	//logic
	ProcessType pt;
	
	int duration;
	int timeLeft;
	int starvedThreshold;
	long int arrivalTime;
	long int startExecTime{};
	long int lastPauseTime{};

	bool bNew;
	bool bPaused;
	bool bFinished;
	bool bStarved;

	//stats for actual results
	long int initWaitTime{};			//from arrival to start exec
	long int totalWaitTime{};		//from arrival including all waits
	long int executionTime{};		//from start of exec to end of exec
	long int processingTime{};			//from arrival to end of exec


	Process();
	Process(int arrivalTime, ProcessType pt); 
	Process(Process &temp);
	~Process() = default;

	void tick(long long int time);
	void pauseExecution(long long int time);
	void finish(long long int time);
	void starve() { if (initWaitTime > starvedThreshold) bStarved = true; }

	inline bool isFinished() { return bFinished; }

};

