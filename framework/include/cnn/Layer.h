#ifndef __FRAMEWORK_CNN_LAYER_H__
#define __FRAMEWORK_CNN_LAYER_H__

#include "../../include/cnn/ConvertionKernel.h"

#include <vector>

namespace framework{
		namespace cnn{
	class Layer{
		private:
			int width;
			int height;

			int batchSize;
			
			std::vector<double **> values; // batch

			ConvertionKernel *w;
		public:
			Layer(int width, int height, int batchSize, std::vector<double **> values, ConvertionKernel *w);

			virtual void convolution() = 0;

			~Layer();
	};
		};
};

#endif // ! __FRAMEWORK_CNN_LAYER_H__