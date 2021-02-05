/**
 * Discussion 2: Monitors
 * Starter Code
 * Ben Reeves Winter 2018
 */
#include <iostream>

#include "cpu.h"
#include "mutex.h"
#include "cv.h"

using std::cout;
using std::endl;

// Steps: 
// 1. Identify shared data.
// 2. Assign locks to shared data.
// 3. Identify the waiting conditions of the threads.
// 4. Assign condition variables for each situation.
// 5. Use while (!condition) { wait }
// 6. Call signal()/broadcast() when threads modify data that affects the conditions.

// TODO: Add any globals you need here

// TODO: Implement these

void big10_fan_enters(void*) {

}

void big10_fan_leaves(void*) {

}

void pac12_fan_enters(void*) {

}

void pac12_fan_leaves(void*) {

}

void launch_threads(void *) {
	cout << "Hello world!" << endl;
	{ thread t((thread_startfunc_t)big10_fan_enters, 0); }
	{ thread t((thread_startfunc_t)big10_fan_enters, 0); }
	{ thread t((thread_startfunc_t)pac12_fan_enters, 0); }
	{ thread t((thread_startfunc_t)big10_fan_leaves, 0); }
	{ thread t((thread_startfunc_t)big10_fan_leaves, 0); }
}

int main(int argc, char **argv) {
	cpu::boot(launch_threads, 0, 0);
	return 0;
}
