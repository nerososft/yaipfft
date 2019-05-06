#ifndef __FRAMEWORK_CNN_CONVERTION_LAYER_H__
#define __FRAMEWORK_CNN_CONVERTION_LAYER_H__

#include "../../include/cnn/Layer.h"

namespace framework{
		namespace cnn{
	class ConvertionLayer : public Layer{
		private:

		public:
			ConvertionLayer();

			void convolution();

			~ConvertionLayer();
	};
		};
};

#endif // ! __FRAMEWORK_CNN_CONVERTION_LAYER_H__