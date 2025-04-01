#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>




using namespace std;

int n=10;
mutex mtx;
bool isfoo_printed=false;
condition_variable cv;

void foo()
{
	for(int i=0;i<n;i++)
	{
		unique_lock lock(mtx);
		cv.wait( lock, []{ return !isfoo_printed; } );
		cout<<"foo";
		isfoo_printed=true;
		cv.notify_all();
		
	}
}

void bar()
{
	for(int i=0;i<n;i++)
	{
		unique_lock  lock(mtx);
		cv.wait(lock, []{ return isfoo_printed; });
		cout<<"bar"<<endl;
		isfoo_printed=false;
		cv.notify_all();
	}
}

int main()
{
	thread t1(foo);
	thread t2(bar);

	t1.join();
	t2.join();
	return 0;
}
