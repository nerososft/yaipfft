#ifndef __FRAMEWORK_FLITER_H__
#define __FRAMEWORK_FLITER_H__

#include "../include/PixelMatrix.h"

namespace framework{

	typedef enum FliterMode{
		GRAY_FLITER,
		BINARY_FLITER
	} FliterMode;

	class Fliter{
	private:
		FliterMode fliterMode;
		PixelMatrix *pixelMatrix;

	public:
		Fliter(PixelMatrix *pixelMatrix,FliterMode fliterMode);

		virtual PixelMatrix *doFliter() = 0; 

		PixelMatrix *getPixelMatrix(){return this->pixelMatrix;};

		~Fliter();
	};	
};


#endif // ! __FRAMEWORK_FLITER_H__