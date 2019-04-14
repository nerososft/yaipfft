#ifndef __FRAMEWORK_THREAD_H__
#define __FRAMEWORK_THREAD_H__


namespace framework{

	class Thread
	{
	friend bool operator==(Thread my1, Thread my2);
    friend bool operator!=(Thread my1, Thread my2);
	private:
		/* data */
	public:
		Thread(/* args */);
		~Thread();
	};
};

#endif // ! __FRAMEWORK_THREAD_H__