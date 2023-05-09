// week 2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <random>
#include "StopWatch.h"

int main() {
    int numbers[100000];
    std::mt19937 rng;
    std::generate(numbers, numbers + 100000, rng);

    StopWatch stopwatch;
    stopwatch.start();
    std::sort(numbers, numbers + 100000);
    stopwatch.stop();

    std::cout << "Sorting 100000 numbers took " << stopwatch.getElapsedTime() << " milliseconds." << std::endl;

    return 0;
}