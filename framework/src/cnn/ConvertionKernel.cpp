#include "../../include/cnn/ConvertionKernel.h"

using namespace framework;

double **generateOperator(int w, int h,double *arr){
	double** x = new double*[h];
	for(int i = 0; i<h; i++){
		x[i] = new double[w];
		for(int j = 0;j<w;j++){
			x[h][w] = *arr;
			arr++;
		}
	}
	return x;
}

ConvertionKernel::ConvertionKernel(int width,int height, double **w){

}

ConvertionKernel::~ConvertionKernel(){
	
}