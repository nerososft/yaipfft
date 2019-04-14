#include "../../include/fliter/BinaryValFliter.h"


using namespace framework;


BinaryValFliter::BinaryValFliter(PixelMatrix *pixelMatrix):Fliter(pixelMatrix, FliterMode::BINARY_FLITER){

}
		
PixelMatrix *BinaryValFliter::doFliter(){
	for (int rows = 0; rows < this->getPixelMatrix()->getHeight(); rows++) {
    	for (int cols = 0; cols < this->getPixelMatrix()->getWidth(); cols ++) {
			Pixel pixel  = this->getPixelMatrix()->getPixels()[rows][cols];
			this->getPixelMatrix()->setPixel(rows,cols,new Pixel(new Color(
				pixel.getColor()->get2Val()
				)));
    	}  
    }
	return this->getPixelMatrix();
}
	
BinaryValFliter::~BinaryValFliter()
{
}