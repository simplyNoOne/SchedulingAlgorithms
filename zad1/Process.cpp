#include "Process.h"
#include <cstdlib>

Process::Process() {
	initWaitTime = 0;
	totalWaitTime = 0;		
	executionTime = 0;		
	processingTime = 0;

	bNew = true;
	bPaused = false;
	bFinished = false;
	bStarved = false;
}

Process::Process(int arrivalTime, ProcessType pt) : Process()
{
	this->arrivalTime = arrivalTime;
	this->pt = pt;

	if (pt == PT_long) {
		numLong++;
		duration = rand() % (pt - PT_medium) + PT_medium + 1;
	}
	else if (pt == PT_medium) {
		numMed ++;
		duration = rand() % (pt - PT_short) + PT_short + 1;
	}
	else {
		numShort++;
		duration = rand() % (pt - PT_none) +PT_none + 1;
	}
	timeLeft = duration;
	starvedThreshold = duration * starvedMult;
}

Process::Process(int arrivalTime, int duration)
{
	this->arrivalTime = arrivalTime;
	this->duration = duration;
	timeLeft = duration;
	starvedThreshold = duration * starvedMult;
}

Process::Process(Process &temp) : Process()
{
	arrivalTime = temp.arrivalTime;
	duration = temp.duration;
	timeLeft = temp.timeLeft;
	pt = temp.pt;
	starvedThreshold = temp.starvedThreshold;
}

void Process::tick(long long int time)
{
	if (bNew) {
		bNew = false;
		initWaitTime = time - arrivalTime;
		totalWaitTime = initWaitTime;
		startExecTime = time;
		if (initWaitTime > starvedThreshold)
			bStarved = true;
	}
	if (bPaused) {
		bPaused = false;
		totalWaitTime += (time - lastPauseTime);
		if (time - lastPauseTime > starvedThreshold)
			bStarved = true;
	}
	timeLeft--;
	if (timeLeft == 0)
		finish(time);
}


void Process::finish(long long int time)
{
	bFinished = true;
	processingTime = time - arrivalTime;
	executionTime = time - startExecTime;
}

void Process::pauseExecution(long long int time)
{
	bPaused = true;
	lastPauseTime = time;
}

int Process::numLong = 0;
int Process::numMed = 0;
int Process::numShort = 0;
