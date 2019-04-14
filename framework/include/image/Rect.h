#ifndef __FRAMEWORK_RECT_H__
#define __FRAMEWORK_RECT_H__

namespace framework
{
	class Rect
	{
	private:
		int posX;
		int posY;
		int width;
		int height;
	public:
		Rect(int posX, int posY, int width, int height);
		~Rect();
	};	
};


#endif // ! __FRAMEWORK_RECT_H__