#pragma once
#ifndef _STOPWATCH_H_
#define _STOPWATCH_H_
class StopWatch
{
public:
	StopWatch();
	void start();
	void stop();
	long long getElapsedTime();
};
#endif

