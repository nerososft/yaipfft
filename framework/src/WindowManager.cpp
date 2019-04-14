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

	// malloc new windows memory space
	Window *windowsMemoryAddr;
	if(windowNum == 0){
		windowNum=1;
	}else{
		windowNum++;
	}
	Log("create window, windowNum: %d \n",windowNum);

	windowsMemoryAddr = (Window *)malloc(windowNum * sizeof(Window));
	if(!windowsMemoryAddr){
		Log("window memory malloc failed! windowNum:",windowNum);
		return -1;
	}

	// copy windows to new windowsMemoryAddr;
	Window *tmp = this->windows;
	Window *tmpNewWindowsAddr = windowsMemoryAddr;

	// while(this->windows->GetWindowHeight()){
	// 	*windowsMemoryAddr = *windows;
	// 	windows++;
	// 	windowsMemoryAddr++;
	// }

	// add new Window
	*windowsMemoryAddr = *window;

	// release old windows memory
//	free(this->windows);

	// assign new windowMemoryAddr to windows
	this->windows = window;

	return 1;
}

int WindowManager::renderWindow(){
	// for(int i = 0; i<this->windowNum; i++){
		// new thread to render window;
		Thread *thread = new Thread();
		thread->assign(this->windows);
	    thread->start();
	// }
}

WindowManager::~WindowManager(){

}