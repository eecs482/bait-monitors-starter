/**
 * Discussion 2: Monitors
 * File Access Starter Code
 * Tony Bai Winter 2021
 */
#include <iostream>

#include "thread.h"

using std::cout;
using std::endl;

// Steps: 
// 1. Identify shared data.
// 2. Assign locks to shared data.
// 3. Identify the waiting conditions of the threads.
// 4. Assign condition variables for each situation.
// 5. Use while (!condition) { wait }
// 6. Call signal()/broadcast() when threads modify data that affects the conditions.

int LIMIT = 100, total = 0;

void getAccess(void* priority_ptr)
{
	int priority = (int)(intptr_t)priority_ptr;

	// TODO Implement me

}

void releaseAccess(void* priority_ptr)
{
	int priority = (int)(intptr_t)priority_ptr;

	// TODO Implement me

}

void launch_threads(void *)
{
	// 20, 41, 63, 86, (86+24)
	for (int i = 0; i < 5; ++i) {
		thread t((thread_startfunc_t)getAccess, (void*)(intptr_t)(24));
	}
	for (int i = 0; i < 5; ++i) {
		thread t1((thread_startfunc_t)releaseAccess, (void*)(intptr_t)(20));
		thread t2((thread_startfunc_t)getAccess, (void*)(intptr_t)(25+i));
	}
}

int main(int argc, char **argv) {
	cpu::boot(launch_threads, 0, 0);
	return 0;
}
