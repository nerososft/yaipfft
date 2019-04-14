#ifndef __FRAMEWORK_WINDOW_MANAGER_H__
#define __FRAMEWORK_WINDOW_MANAGER_H__

#include "../../include/window/Window.h"
#include <vector>

namespace framework{

	class WindowManager
	{
	private:
		static WindowManager windowManagerInstance;

		int windowNum = 0;
		std::vector<Window*> windows;

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