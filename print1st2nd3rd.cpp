#include<iostream>
#include<thread>
#include<mutex>
#include<thread>
#include<condition_variable>


using namespace std;

mutex mtx;
condition_variable cv;
int step=1;

void print1st()
{
	unique_lock lock(mtx);
	cout<<"first"<<endl;
	step=2;
	cv.notify_all();
}

void print2nd()
{

	unique_lock lock(mtx);
	cv.wait(lock,[]{return step==2;});
	cout<<"Second"<<endl;
	step=3;
	cv.notify_all();
}

void print3rd()
{

	unique_lock lock(mtx);
	cv.wait(lock,[]{return step==3;});
	cout<<"third"<<endl;
	
}


int main()
{
	thread t1(print1st);
	thread t2(print2nd);
	thread t3(print3rd);

	t1.join();
	t2.join();
	t3.join();
	return 0;
}