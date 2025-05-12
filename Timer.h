#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

class Timer {
	public:
		Timer();
		~Timer();
		
		void start(float time, std::function<void()> lambda);
		void start(float time);

		float check_time();
		bool check_done();
	
	private:
		std::chrono::steady_clock::time_point start_time_;
		float time_ = NULL;

		bool finished = false;
		bool running = false;
		
};