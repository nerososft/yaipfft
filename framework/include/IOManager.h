#ifndef __FRAMEWORK_IO_MANAGER_H__
#define __FRAMEWORK_IO_MANAGER_H__

namespace framework{

	class IOManager
	{
	private:

		int bufferSize;
		char *buffer;

	public:

		IOManager(/* args */);

		void loadFile(const char *filePath);

		char *getBuffer(){return this->buffer;}

		int getBufferSize(){return this->bufferSize;}

		~IOManager();
	};
};

#endif // ! __FRAMEWORK_IO_MANAGER_H__