#include "../../include/io/IOManager.h"
#include "../../include/log/Log.h"
#include <memory>
#include <fstream>


using namespace framework;

IOManager::IOManager(/* args */){
	this->bufferSize = 0;
}

void IOManager::loadFile(const char *filePath){
	// open file
	std::streampos fileSize;
	std::ifstream file(filePath, std::ios::binary);

	// get its size:
	file.seekg(0, std::ios::end);
	fileSize = file.tellg();

	this->bufferSize = fileSize;

	file.seekg(0, std::ios::beg);
	// read the data:
	this->buffer = (char*)malloc(fileSize * sizeof(char));
	if(!this->buffer){
		Log("file load error: %s \n",filePath);
	}
	file.read(this->buffer, fileSize);
}
	
IOManager::~IOManager(){
	free(this->buffer);
}