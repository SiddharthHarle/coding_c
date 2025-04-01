#include<iostream>
#include<thread>
#include <mutex>

using namespace std;

mutex m;

void fun(int x)
{
	m.lock();
	cout<<"thread id :: "<<this_thread::get_id()<<endl;
	for(int i=0;i<100;i++)
	{
		cout<<"thread :: "<<x<<" value : "<<i<<endl; 
	}
	m.unlock();
}


int main()
{

	thread t1(fun,1);
	thread t2(fun,2);

	t1.join();
	t2.join();

	return 0;
}