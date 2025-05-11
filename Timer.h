#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>

class Timer {
	public:
		Timer();
		~Timer();
		/**
		 * Starts the timer with a lambda function.
		 * @param timer The time in seconds to wait before executing the lambda function.
		 * @param lambda The lambda function to execute after the timer expires.
		 */
		template<typename Lambda>
		void start(float timer, Lambda&& lambda){
			start_time_ = std::chrono::steady_clock::now();
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
		std::chrono::steady_clock::time_point start_time_;
		float time_ = NULL;

		bool finished = false;
		bool running = false;
		
};