#include "../include/WindowManager.h"
#include "../include/Log.h"
#include "../include/Thread.h"

using namespace framework;

WindowManager WindowManager::windowManagerInstance;


WindowManager* WindowManager::GetWindowManagerInstance() { 
	return &WindowManager::windowManagerInstance;  
}

WindowManager::WindowManager(/* args */){

}
	
int WindowManager::createWindow(Window* window){
	if(windowNum == 0){
		windowNum=1;
	}else{
		windowNum++;
	}
	Log("create window, windowNum: %d \n",windowNum);

	// add new Window
	this->windows.push_back(window);

	return 1;
}

int WindowManager::renderWindow(){
	Log("render window, windowNum: %d \n",windowNum);
	for(int i = 0; i < this->windows.size(); i++){
		// new thread to render window;
		Thread thread;
		thread.assign(this->windows.at(i));
	    thread.start();
	}
}

WindowManager::~WindowManager(){

}