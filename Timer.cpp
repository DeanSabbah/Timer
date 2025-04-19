// Timer.cpp : Defines the entry point for the application.
//

#include "Timer.h"

Timer::Timer(){}
Timer::~Timer() {}

void Timer::start(float timer){
	time(&start_time_);
	time_ = timer;
	running = true;
	finished = false;
}

float Timer::check_time(){
	time_t curr_time, time_diff;
	time(&curr_time);
	time_diff = curr_time - start_time_;
	if (time_diff >= time_){
		finished = true;
		time_diff = time_;
	}
	return time_diff;
}

bool Timer::check_done(){
	if(check_time() >= time_ && running){
		running = false;
		return true;
	}
	return false;
}