#include "Timer.h"

Timer::Timer(){}
Timer::~Timer() {}

/**
* Starts the timer without a lambda function.
* 
* @param <float> time: The time in seconds to wait before executing the lambda function.
*/
void Timer::start(float timer){
	start_time_ = std::chrono::steady_clock::now();
	time_ = timer;
	running = true;
	finished = false;
}

/**
* Starts the timer with a lambda function.
* @param <float> time The time in seconds to wait before executing the lambda function.
* @param <void()> lambda: The lambda function to execute after the timer expires.
* 
* If the passed function's parent object is deleted (dynamic) or goes out of scope (static), this
* will result in a read access violation.
*/
void Timer::start(float time, std::function<void()> lambda) {
	start(time);
	std::thread([time, lambda]() mutable {
		std::this_thread::sleep_for(std::chrono::milliseconds((int)(time * 1000)));
		lambda();
		}).detach();
}

/**
* This function will check the time elapsed since the timer started.
* If the time elapsed is greater than or equal to the timer set, it will
* set finished to true and return the time elapsed.
* 
* @returns <float>: Time since timer started
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

/**
* This function will check if the timer is done.
* Only returns true if the timer was started since the last time it finished (or if it never finished).
* (In other words, the timer must be running)
* 
* @returns <bool>: True if finished, false otherwise
*/
bool Timer::check_done(){
	if(running && check_time() >= time_)
		running = false;
	
	return finished;
}