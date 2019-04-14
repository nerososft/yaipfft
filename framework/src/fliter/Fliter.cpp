#include "../../include/fliter/Fliter.h"

using namespace framework;



Fliter::Fliter(PixelMatrix *pixelMatrix,FliterMode fliterMode){
	this->pixelMatrix = pixelMatrix;
	this->fliterMode = fliterMode;
}

Fliter::~Fliter(){
	delete pixelMatrix;
}
