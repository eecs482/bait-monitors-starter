/**
 * Discussion 2: Monitors
 * Starter Code
 * Ben Reeves Winter 2018
 * Tony Bai Winter 2021
 */
#include <iostream>
#include <vector>

#include "cpu.h"
#include "mutex.h"
#include "cv.h"

using std::cout;
using std::endl;
using std::vector;

// Steps: 
// 1. Identify shared data.
// 2. Assign locks to shared data.
// 3. Identify the waiting conditions of the threads.
// 4. Assign condition variables for each situation.
// 5. Use while (!condition) { wait }
// 6. Call signal()/broadcast() when threads modify data that affects the conditions.

// TODO: Implement barrier class

class barrier {
private:
	// Add your private variables here

public:
	// Constructs a new barrier that will allow number_of_threads
	//      threads to check in.
	barrier(int number_of_threads);

	// Called by a thread checking in to the barrier. Should return
	//      true if the thread was the last thread to check in (in POSIX threads
	//      lingo, the "serial thread") and false otherwise. This function should
	//      block until all threads have checked in.
	bool wait();

	// Delete copy constructor and copy assignment operators
	barrier(const barrier&) = delete;
	barrier& operator=(const barrier&) = delete;
	barrier(barrier&&) = delete;
	barrier& operator=(barrier&&) = delete;
};

barrier::barrier(int number_of_threads) {
	// TODO: Implement
	cout << "barrier::barrier(" << number_of_threads << ")" << endl;
}

bool barrier::wait() {
	// TODO: Implement
	cout << "barrier::wait()" << endl;
	return false;
}


int NUM_RUNNERS = 10;
barrier starting_line(NUM_RUNNERS);
mutex print_mutex;

void runner_ready(void * i)
{
	print_mutex.lock();
	cout << "Runner " << (intptr_t)i << " is ready!" << endl;
	print_mutex.unlock();

	if (starting_line.wait()) {
		cout << (intptr_t)i << ": BANG!" << endl;
	}
	else {
		cout << (intptr_t)i << " starting" << endl;
	}
}

void launch_threads(void *) {
	cout << "Hello world!" << endl;
	for (int iter = 0; iter < 3; ++iter)
	{
		vector<thread*> threads;
		for (int i = 0; i < NUM_RUNNERS; ++i) {
			thread * t = new thread((thread_startfunc_t)runner_ready, (void*)(intptr_t)i);
			threads.push_back(t);
		}
		for (thread * tptr : threads) {
			// tptr->join();
			delete tptr;
		}
	}
}

int main(int argc, char **argv) {
	cpu::boot(launch_threads, 0, 0);
	return 0;
}
