#include "Timer.h"

Timer::Timer(){}
Timer::~Timer() {}

/**
* Starts the timer without a lambda function.
*/
void Timer::start(float timer){
	start_time_ = std::chrono::steady_clock::now();
	time_ = timer;
	running = true;
	finished = false;
}

/*
* This function will check the time elapsed since the timer started.
* If the time elapsed is greater than or equal to the timer set, it will
* set finished to true and return the time elapsed.
*/
float Timer::check_time() {
    if (!running) {
        std::cerr << "Timer is not running!" << std::endl;
        return 0.0;
    }
    auto curr_time = std::chrono::steady_clock::now();
    auto time_diff = std::chrono::duration<float>(curr_time - start_time_).count();
    if (time_diff >= time_) {
        finished = true;
    }

    return time_diff;
}

/*
* This function will check if the timer is done.
* Only returns true if the timer was started since the last time it finished (or if it never finished).
*/
bool Timer::check_done(){
	if(check_time() >= time_ && running)
		running = false;
	
	return finished;
}