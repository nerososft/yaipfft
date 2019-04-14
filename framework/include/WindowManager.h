#ifndef __FRAMEWORK_WINDOW_MANAGER_H__
#define __FRAMEWORK_WINDOW_MANAGER_H__

#include "../include/Window.h"

namespace framework{

	class WindowManager
	{
	private:
		static WindowManager windowManagerInstance;

		int windowNum = 0;
		Window *windows;

	public:
		WindowManager(/* args */);

		static	WindowManager* GetWindowManagerInstance();


		int getWindowNum(){return this->windowNum;}

		int createWindow(Window* window);

		int renderWindow();

		~WindowManager();
	};

};


#endif // ! __FRAMEWORK_WINDOW_MANAGER_H__