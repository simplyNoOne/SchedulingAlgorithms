#include "Process.h"

#include <memory>
#include <iostream>
#include <cstdlib>

Process::Process(int arrivalTime, ProcessType pt)
{
	this->arrivalTime = arrivalTime;
	this->pt = pt;

	if (pt == PT_long) 
		duration = rand() % (pt - PT_medium) + PT_medium + 1;
	else if (pt == PT_medium) 
		duration = rand() % (pt - PT_short) + PT_short + 1;
	else
		duration = rand() % pt + 1;
	timeLeft = duration;
	std::cout << "arrival " << arrivalTime << std::endl;
}

Process::Process(Process &temp)
{
	arrivalTime = temp.arrivalTime;
	duration = temp.duration;
	timeLeft = temp.timeLeft;
	pt = temp.pt;

}

void Process::Execute(long long int time)
{
	if (bNew) {
		initWaitTime = time - arrivalTime;
		totalWaitTime += initWaitTime;
		startExecTime = time;
		bNew = false;
	}
	timeLeft--;
	if (timeLeft == 0)
		Finish(time);
}


void Process::Finish(long long int time)
{
	bFinished = true;
	processingTime = time - arrivalTime;
	executionTime = time - startExecTime;

	std::cout << "Duration " << duration << std::endl;
	std::cout << "Wait time " << initWaitTime << std::endl;
	std::cout << "Execution time " << executionTime << std::endl;
}
