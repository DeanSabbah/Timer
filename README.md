Small timer class that I made to practice using lambdas and threads in C++.

Timer can be started with or without passing a lambda function.

check_time() returns the amount of time it's been running for in miliseconds.

check_done() returns true if the amount of time it's been running for is equal or greater than what the timer was set to.

If you set a timer with a lambda, a new thread will be created that will sleep for a given time, then execute the passed lambda function.
