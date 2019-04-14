#include "../include/WindowManager.h"
#include "../include/Log.h"

using namespace framework;

WindowManager WindowManager::windowManagerInstance;


WindowManager* WindowManager::GetWindowManagerInstance() { return &WindowManager::windowManagerInstance;  }

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
	windowsMemoryAddr = (Window *)malloc(windowNum * sizeof(Window));
	if(!windowsMemoryAddr){
		Log("window memory malloc failed! windowNum:",windowNum);
		return -1;
	}

	// copy windows to new windowsMemoryAddr;
	Window *tmp = this->windows;
	Window *tmpNewWindowsAddr = windowsMemoryAddr;

	while(windows){
		*windowsMemoryAddr = *windows;
		windows++;
		windowsMemoryAddr++;
	}

	// add new Window
	*windowsMemoryAddr = *window;

	// release old windows memory
	free(this->windows);

	// assign new windowMemoryAddr to windows
	this->windows = tmpNewWindowsAddr;

	return 1;
}

int WindowManager::renderWindow(){
	
}

WindowManager::~WindowManager(){

}