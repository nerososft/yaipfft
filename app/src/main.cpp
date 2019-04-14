
#include <iostream>
#include "../../framework/include/JPGImageLoader.h"
#include "../../framework/include/GrayFliter.h"
#include "../../framework/include/BinaryValFliter.h"
#include "../../framework/include/Window.h"

int main(int argc, char *argv[]){
	
	framework::ImageLoader *jpgLoader = new framework::JPGImageLoader();
	framework::PixelMatrix *pixels = jpgLoader->loadImage("/Users/neroyang/project/sbwIP/img/nasa.jpg");

	framework::Window *window = new framework::Window(pixels->getWidth(), pixels->getHeight(), "二值化");
	//framework::Fliter *grayFliter = new framework::GrayFliter(pixels);
	framework::Fliter *binaryValFliter = new framework::BinaryValFliter(pixels);
	window->setPixelMatrix(binaryValFliter->doFliter());

	return window->Execute(argc, argv);
}