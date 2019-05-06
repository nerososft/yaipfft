#include "../../include/cnn/Cnn.h"

using namespace framework::cnn;

void CNN::input(ConvertionLayer *layer, int	sizeOfConvertionLayer, int batchSize, int epochNum, KernelGenerateMode kernelMode){

	this->sizeOfConvertionLayer = sizeOfConvertionLayer;
	this->batchSize = batchSize;

	this->epochNum = epochNum;
}


void CNN::init(){
	this->firstEpoch();
}

void CNN::train(){
	int epoch = 0;
	while(epoch<this->epochNum){
		this->epoch();
		epoch++;
	}
}

void CNN::generateModel(){
 	// TODO: output model to file
}

void CNN::firstEpoch(){
	ConvertionLayer *t_layer = this->layer;
	for(int layerNum = 0; layerNum<sizeOfConvertionLayer; layerNum++){

		this->convertionLayers.push_back(t_layer);
		t_layer = t_layer.convolution();
	}
	polling();
	fullConnect();
}

void CNN::epoch(){
	for(int layerNum = 0; layerNum<sizeOfConvertionLayer; layerNum++){
		
	}
	polling();
	fullConnect();
}

void CNN::forward(){
	
}

void CNN::polling(){

}

void CNN::fullConnect(){

}