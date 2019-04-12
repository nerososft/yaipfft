#include "../include/Window.h"
#include "../include/Log.h"


using namespace framework;

Window Window::Instance;

Window::Window() {

}

void Window::OnEvent(SDL_Event* Event) {

}

bool Window::Init() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        Log("Unable to Init SDL: %s", SDL_GetError());
        return false;
                            
    }

    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        Log("Unable to Init hinting: %s", SDL_GetError());
                    
    }

    if((window = SDL_CreateWindow(windowName,
                    SDL_WINDOWPOS_UNDEFINED, 
                    SDL_WINDOWPOS_UNDEFINED,
                    windowWidth, windowHeight,
                    SDL_WINDOW_SHOWN)) == NULL) {
        Log("Unable to create SDL Window: %s", SDL_GetError());
        return false;
                            
    }

    primarySurface = SDL_GetWindowSurface(window);

    if((renderer = SDL_GetRenderer(window)) == NULL) {
        Log("Unable to create renderer '%s'", SDL_GetError());
        return false;                        
    }

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

    return true;

}


void Window::Loop() {

}
void Window::Render() {

    SDL_RenderClear(renderer);
    for(int i = 0; i< this->pixelMatrix->getHeight(); i++){
        for(int j = 0; j< this->pixelMatrix->getWidth(); j++){
            SDL_SetRenderDrawColor(renderer, 
				pixelMatrix->getPixels()[i][j].getColor()->getR(),
			 	pixelMatrix->getPixels()[i][j].getColor()->getG(), 
			 	pixelMatrix->getPixels()[i][j].getColor()->getB(), 255);
            SDL_RenderDrawPoint(renderer, j, i);
        }
    }
    SDL_RenderPresent(renderer);
}

void Window::Cleanup() {
    if(renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;                    
    }

    if(window) {
        SDL_DestroyWindow(window);
        window = NULL;                    
    }
    SDL_Quit();
}


int Window::Execute(int argc, char* argv[]) {
    if(!Init()) return 0;
        SDL_Event Event;
        while(running) {
            while(SDL_PollEvent(&Event) != 0) {
                OnEvent(&Event);
                if(Event.type == SDL_QUIT) running = false;                               
            }
            Loop();
            Render();
            SDL_Delay(1); // Breath                           
        }
        Cleanup();
        return 1;
}


Window* Window::GetInstance() { return &Window::Instance;  }

int Window::GetWindowWidth()  { return windowWidth;  }
int Window::GetWindowHeight() { return windowHeight;  }
