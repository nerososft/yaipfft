#ifndef __FRAMEWORK_CNN_CONVERTION_KERNEL_H__
#define __FRAMEWORK_CNN_CONVERTION_KERNEL_H__


namespace framework{
		namespace cnn{
	typedef enum KernelGenerateMode{
		RANDOM,
	} KernelGenerateMode;

	class ConvertionKernel
	{
	private:
		/* data */
		private:
			int width;
			int height;
			double **w;

	public:
		ConvertionKernel(int width,int height, double **w);
		
		int getWidth(){return this->width;};
		int getHeight(){return this->height;};

		double **getW(){ return this->w;};
		void setW(double **w){ this->w = w;};

		~ConvertionKernel();
	};
		};
	
};

#endif // ! __FRAMEWORK_CNN_CONVERTION_KERNEL_H__