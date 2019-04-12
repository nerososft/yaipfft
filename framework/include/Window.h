#ifndef __FRAMEWORK_WINDOW_H__
#define __FRAMEWORK_WINDOW_H__

#include <SDL2/SDL.h>
#include "../include/PixelMatrix.h"

namespace framework
{
	class Window{
   		private:
	
   		    static Window Instance;
   		    bool running = true;

   		    SDL_Window* window = NULL;
   		    SDL_Renderer* renderer = NULL;
   		    SDL_Surface* primarySurface = NULL;

   		    int windowWidth=256;
   		    int windowHeight=256;

			char *windowName = "framework window";

			PixelMatrix *pixelMatrix;

			
	
   		private:
	
   		    Window();

   		    // Capture SDL Events
   		    void OnEvent(SDL_Event* Event);
	
   		    // Initialize our SDL game / app
   		    bool Init();
	
   		    // Logic loop
   		    void Loop();
	
   		    // Render loop (draw)
   		    void Render();
	
   		    // Free up resources
   		    void Cleanup();
	



   		public:
	
   		    int Execute(int argc, char* argv[]);

   		public:
	
   		    static Window* GetInstance();

   		    int GetWindowWidth();
   		    int GetWindowHeight();

			void setWindowWidth(int width){this->windowWidth = width;};
   		    void setWindowHeight(int height){this->windowHeight = height;};

			void setWindowName(char *name){this->windowName = name;};

			void setPixelMatrix(PixelMatrix *pixelMatrix){this->pixelMatrix = pixelMatrix;}

	};
};
#endif // !__FRAMEWORK_WINDOW_H__