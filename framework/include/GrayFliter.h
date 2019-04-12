#ifndef __FRAMEWORK_GRAYFLITER_H__
#define __FRAMEWORK_GRAYFLITER_H__

#include "../include/Fliter.h"

namespace framework
{
	class GrayFliter : public Fliter
	{
	private:
	public:
		GrayFliter(PixelMatrix *pixelMatrix);
		
		PixelMatrix *doFliter(); 
		
		~GrayFliter();
	};	
};


#endif // ! __FRAMEWORK_GRAYFLITER_H__