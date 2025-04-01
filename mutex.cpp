#include<iostream>
#include<thread>
#include<mutex>

using namespace std;


mutex m;

void sharedResource()
{

	m.lock();
	cout<<"Inside shared Resource this_thread: "<<this_thread::get_id()<<endl;
	m.unlock();
}


int main()
{
	thread t1(sharedResource);
	thread t2(sharedResource);
	t1.join();
	t2.join();

	return 0;
}