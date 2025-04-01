#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
int n=10;
bool oddprinted=false;

void printodd()
{
	for(int i=1;i<n;i+=2)
	{
		unique_lock lock(mtx);
		cv.wait(lock, []{return !oddprinted; });
		cout<<"odd  :: "<<i<<endl;
		oddprinted=true;
		cv.notify_all();
	}

}

void printeven()
{
	for(int i=2;i<n;i+=2)
	{
		unique_lock lock(mtx);
		cv.wait(lock, []{return oddprinted; });
		cout<<"even :: "<<i<<endl;
		oddprinted=false;
		cv.notify_all();
		
	}
	
}

int main(int argc, char**argv)
{
	thread t1(printodd);
	thread t2(printeven);

	t1.join();
	t2.join();
	return 0;
}