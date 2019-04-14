	#include "../../include/image/Rect.h"
	
	using namespace framework;
	
	Rect::Rect(int posX, int posY, int width, int height){
		this->posX = posX;
		this->posY = posX;
		this->width = width;
		this->height = height;
	}
	
	Rect::~Rect()
	{
	}