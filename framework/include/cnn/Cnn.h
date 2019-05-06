#ifndef __FRAMEWORK_CNN_H__
#ifndef __FRAMEWORK_CNN_H__

#include <vector>
#include "../../include/cnn/Layer.h"
#include "../../include/cnn/ConvertionLayer.h"
#include "../../include/cnn/PollingLayer.h"
#include "../../include/cnn/FullyConnectedLayer.h"


namespace framework{
	namespace cnn{
		class CNN{
			private:
				std::vector<ConvertionLayer*> convertionLayers;
				std::vector<PollingLayer*> convertionLayers;
				std::vector<FullyConnectedLayer*> convertionLayers;

				int	sizeOfConvertionLayer;

				int	epochNum;

				int batchSize;

				int loss;

				void init();

				void forward();
				void polling();
				void fullConnect();



				void firstEpoch();
				void epoch();


			public:

				CNN();

				void input(ConvertionLayer *layer, int	sizeOfConvertionLayer, int batchSize, int epochNum, KernelGenerateMode kernelMode);

				void train();

				void generateModel();

				~CNN();
		};
	};
};

#endif // ! #ifndef __FRAMEWORK_CNN_H__