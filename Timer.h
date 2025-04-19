#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>

class Timer {
	public:
		Timer();
		~Timer();
		template<typename Lambda>
		void start(float timer, Lambda&& lambda){
			time(&start_time_);
			time_ = timer;
			running = true;
			finished = false;
			std::thread([timer, lambda = std::forward<Lambda>(lambda)]() mutable {
				std::this_thread::sleep_for(std::chrono::milliseconds((int)(timer * 1000)));
				lambda();
				}).detach();
		}
		void start(float time);

		float check_time();
		bool check_done();
	
	private:
		time_t start_time_ = NULL;
		time_t time_ = NULL;

		bool finished = false;
		bool running = false;
		
};