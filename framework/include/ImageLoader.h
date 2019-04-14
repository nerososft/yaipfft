#ifndef __FRAMEWORK_IMAGELOADER_H__
#define __FRAMEWORK_IMAGELOADER_H__

#include "../include/PixelMatrix.h"
#include "../include/IOManager.h"

namespace framework{
	typedef enum ImageFormat{
		PNG,
		JPG,
		JPEG,
		BMP,
	} ImageFormat;

	class ImageLoader
	{
		private:
			IOManager *io;
			PixelMatrix *pixels;
			
		public:
			ImageLoader(ImageFormat format);

			IOManager *getIO(){return this->io;}

			PixelMatrix *getPixelMatrix(){return this->pixels;};
			void setPixelMatrix(PixelMatrix *pixels){this->pixels=pixels;};

			virtual PixelMatrix *loadImage(const char *imgPath) = 0;

			~ImageLoader();
		};
	
};

#endif // ! __FRAMEWORK_IMAGELOADER_H__