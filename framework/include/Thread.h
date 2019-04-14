#ifndef __FRAMEWORK_THREAD_H__
#define __FRAMEWORK_THREAD_H__

#include "../include/Runnable.h"
#include <thread>

namespace framework{

	class Thread
	{
	friend bool operator==(Thread t1, Thread t2);
    friend bool operator!=(Thread t1, Thread t2);

	private:
		Runnable *task;
		int threadId;
  		std::thread thread;
	public:
		Thread(/* args */);
		void assign(Runnable *task);
 		void run();
    	void start();
    	int getThreadId(){return this->threadId;}

		~Thread();
	};
};

#endif // ! __FRAMEWORK_THREAD_H__