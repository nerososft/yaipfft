#ifndef __FRAMEWORK_RUNNABLE_H__
#define __FRAMEWORK_RUNNABLE_H__

namespace framework
{
	class Runnable
	{
	private:
		/* data */
	public:
		Runnable(/* args */);

		virtual void Run() = 0;
		
		~Runnable();
	};	
};



#endif // ! __FRAMEWORK_RUNNABLE_H__