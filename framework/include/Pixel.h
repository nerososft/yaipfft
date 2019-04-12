#ifndef __FRAMEWORK_PIXEL_H__
#define __FRAMEWORK_PIXEL_H__

namespace framework{

	typedef unsigned int ui32;

	class Color{
		private:
			ui32 color;
		public:
			Color(ui32 gray);
			Color(ui32 r, ui32 g, ui32 b);
			Color(ui32 r, ui32 g, ui32 b, ui32 alpha);

			ui32 setR(ui32 r);
			ui32 setG(ui32 g);
			ui32 setB(ui32 b);
			ui32 setAlpha(ui32 alpha);

			ui32 getR();
			ui32 getG();
			ui32 getB();
			ui32 getAlpha();

			ui32 getGray(/* TODO: Need multi mode */);
			ui32 get2Val();

			~Color();
	};
	class Pixel
	{
	private:
		Color *color;

	public:

		Color *getColor(){return this->color;}
		void setColor(Color *color){this->color = color;}

		Pixel();
		Pixel(Color *color);
		Pixel(ui32 r, ui32 g, ui32 b);
		Pixel(ui32 r, ui32 g, ui32 b,ui32 alpha);

	

		~Pixel();
	};
};

#endif // ! __FRAMEWORK_PIXEL_H__