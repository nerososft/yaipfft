
#include <iostream>
#include "../../framework/include/JPGImageLoader.h"
#include "../../framework/include/GrayFliter.h"
#include "../../framework/include/Window.h"

int main(int argc, char *argv[]){
	
	framework::ImageLoader *jpgLoader = new framework::JPGImageLoader();

	framework::PixelMatrix *pixels = jpgLoader->loadImage("/Users/neroyang/project/sbwIP/img/nasa.jpg");

	framework::Window *window = framework::Window::GetInstance();
	window->setWindowHeight(pixels->getHeight());
	window->setWindowWidth(pixels->getWidth());

	framework::Fliter *grayFliter = new framework::GrayFliter(pixels);

	window->setPixelMatrix(grayFliter->doFliter());


	return window->Execute(argc, argv);
}