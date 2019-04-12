#ifndef __FRAMEWORK_JPG_IMAGELOADER_H__
#define __FRAMEWORK_JPG_IMAGELOADER_H__

#include "../include/ImageLoader.h"
#include <iostream>

extern "C" {
    #include <jpeglib.h>
}

namespace framework{

	typedef enum SegmentType{
		SOI = 0xD8, //     文件头
		EOI = 0xD9, //     文件尾	
		SOF0 = 0xC0,//     帧开始（标准 JPEG）
		SOF1 = 0xC1,//     同上
		DHT =  0xC4,//     定义 Huffman 表（霍夫曼表）
		SOS = 0xDA,//     扫描行开始
		DQT = 0xDB,//     定义量化表
		DRI = 0xDD,//     定义重新开始间隔
		APP0 = 0xE0,//     定义交换格式和图像识别信息
		COM = 0xFE,//     注释
	} SegmentType;

	typedef struct SOI{
		char segFlag;
		char segType;
	} JPEG_SOI_T;

	typedef struct APP0{
		char segFlag;
		char segType;
		char* segLen;
	} JPEG_APP0_T;

	typedef struct JPEG{
		
	} JPEG_T;

	class JPGImageLoader : public ImageLoader
	{
	private:
		/* data */
		void write_pixel_data(j_decompress_ptr cinfo, unsigned char *output_buffer);
		int read_jpeg_file(const char *input_filename);
	public:
		JPGImageLoader();

		PixelMatrix *loadImage(const char *imgPath);

		~JPGImageLoader();
	};	
};

#endif // ! __FRAMEWORK_JPG_IMAGELOADER_H__