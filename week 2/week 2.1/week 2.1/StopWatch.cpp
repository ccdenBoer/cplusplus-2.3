#include "StopWatch.h"

#include <chrono>



    std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime;


    StopWatch::StopWatch() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    void StopWatch::start() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    void StopWatch::stop() {
        endTime = std::chrono::high_resolution_clock::now();
    }

    long long StopWatch::getElapsedTime() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    }


