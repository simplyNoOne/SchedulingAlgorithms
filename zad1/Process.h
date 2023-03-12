#pragma once


#include <stdio.h>
#include <iostream>
#include <memory>

enum ProcessType {
	//enum contains maximum durations for process types
	PT_none = 0,
	PT_short = 5,
	PT_medium = 15, 
	PT_long = 30
};

class Process
{
public:
	ProcessType pt;

	long long int arrivalTime;
	int duration;
	int timeLeft;
	long long int startExecTime{};

	long long int initWaitTime{};			//from arrival to start exec
	long long int totalWaitTime{};		//from arrival including all waits
	long long int executionTime{};		//from start of exec to end of exec
	long long int processingTime{};			//from arrival to end of exec

	bool bNew;
	bool bFinished;

	Process();
	Process(int arrivalTime, ProcessType pt); 
	Process(Process &temp);
	~Process() = default;

	void Execute(long long int time);
	void Finish(long long int time);

	inline bool isFinished() { return bFinished; }

};

