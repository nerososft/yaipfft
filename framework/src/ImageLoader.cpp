#include "../include/ImageLoader.h"

using namespace framework;

ImageLoader::ImageLoader(ImageFormat format){
	io = new IOManager();
}

ImageLoader::~ImageLoader(){
	delete io;
	delete pixels;
}