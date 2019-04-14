
#include <iostream>
#include "../../framework/include/JPGImageLoader.h"
#include "../../framework/include/GrayFliter.h"
#include "../../framework/include/BinaryValFliter.h"
#include "../../framework/include/WindowManager.h"
#include "../../framework/include/Window.h"

int main(int argc, char *argv[]){
	
	framework::ImageLoader *jpgLoader = new framework::JPGImageLoader();
	framework::PixelMatrix *pixels = jpgLoader->loadImage("/Users/neroyang/project/sbwIP/img/nasa.jpg");

	framework::Fliter *binaryValFliter = new framework::BinaryValFliter(pixels);
	framework::Window *binaryWindow = new framework::Window(pixels->getWidth(), pixels->getHeight(), "二值化");
	binaryWindow->setPixelMatrix(binaryValFliter->doFliter());
	
	framework::Fliter *grayFliter = new framework::GrayFliter(pixels);
	framework::Window *grayWindow = new framework::Window(pixels->getWidth(), pixels->getHeight(), "灰度图");
	grayWindow->setPixelMatrix(grayFliter->doFliter());

	framework::WindowManager *manager = framework::WindowManager::GetWindowManagerInstance();
	manager->createWindow(binaryWindow);
	manager->createWindow(grayWindow);
	manager->renderWindow();

	return 1;
}