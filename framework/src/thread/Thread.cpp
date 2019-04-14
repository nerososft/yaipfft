#include "../../include/thread/Thread.h"

using namespace framework;


Thread::Thread(/* args */){
}


void Thread::assign(Runnable *task){
	this->task = task;
}

void Thread::run(){
	this->task->Run();
}

void Thread::start(){
	this->thread = std::thread(&Thread::run, this);
    this->thread.join();
}

Thread::~Thread(){
}