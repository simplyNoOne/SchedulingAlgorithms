#pragma once
#include "Process.h"

class Algorithm
{
public:
	std::string name;

	//sums
	long long int totalInitWaitTime{};
	long long int totalTotalWaitTime{};
	long long int totalExecutionTime{};
	long long int totalProcessingTime{};
	long int totalSwitches{};
	long int totalStarved{};

	//averages for stats
	double meanInitWaitTime{};
	double meanTotalWaitTime{};
	double meanExecutionTime{};
	double meanProcessingTime{};

protected:

	//logic
	long long int executed{};
	long int numProcesses{};
	bool bAlgorithmFinished = false;
	bool bSpawningFinished = false;

	//this is the one that will get executed every cycle *RIP*
	Process* current = nullptr;

public:
	inline Algorithm(int numProcesses) : numProcesses(numProcesses) {}

	virtual void addProcess(Process* procToAdd) = 0;
	virtual void spawnFinished();
	virtual void simCycle(long long int time);
	virtual void processFinished();
	virtual void finish();
	inline bool isFinished() { return bAlgorithmFinished; }
	std::string results();
};

struct ShorterJob final{
	bool operator()(Process const* p1, Process const* p2) const {
		//if true, p1 will be before p2		
		return p1->timeLeft < p2->timeLeft;
	}
};

template <typename T, typename Pred = std::less<T>>
struct ptr_compare : Pred
{
	ptr_compare(Pred const& p = Pred()) : Pred(p) { }
	bool operator()(T const* p1, T const* p2) const
	{
		return Pred::operator()(*p1, *p2);
	}
};