#ifndef __FRAMEWORK_BINARY_VAL_LITER_H__
#define __FRAMEWORK_BINARY_VAL_LITER_H__

#include "../include/Fliter.h"

namespace framework
{
	class BinaryValFliter : public Fliter
	{
	private:
	public:
		BinaryValFliter(PixelMatrix *pixelMatrix);
		
		PixelMatrix *doFliter(); 
		
		~BinaryValFliter();
	};	
};


#endif // ! __FRAMEWORK_BINARY_VAL_LITER_H__