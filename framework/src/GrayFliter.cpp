#include "../include/GrayFliter.h"


using namespace framework;


GrayFliter::GrayFliter(PixelMatrix *pixelMatrix):Fliter(pixelMatrix, FliterMode::GRAY_FLITER){

}
		
PixelMatrix *GrayFliter::doFliter(){
	for (int rows = 0; rows < this->getPixelMatrix()->getHeight(); rows++) {
    	for (int cols = 0; cols < this->getPixelMatrix()->getWidth(); cols ++) {
			Pixel pixel  = this->getPixelMatrix()->getPixels()[rows][cols];
			this->getPixelMatrix()->setPixel(rows,cols,new Pixel(new Color(
				pixel.getColor()->getGray()
				)));
    	}  
    }
	return this->getPixelMatrix();
}
	
GrayFliter::~GrayFliter()
{
}