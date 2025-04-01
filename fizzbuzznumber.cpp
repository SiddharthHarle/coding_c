#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
int n=100;
static int count=2;

void printfizz()
{
	for(int i=1; i<=n; i++)
	{
		unique_lock lock(mtx);
		cv.wait(lock, []{return (count%3==0)&&(count%5!=0); });
		cout<<" fizz ,";

		++count;
		cv.notify_all();
	}

}


void printbuzz()
{
	for(int i=1; i<=n; i++)
	{
		unique_lock lock(mtx);
		cv.wait(lock, []{return (count%3!=0)&&(count%5==0);});
		cout<<" buzz ,";

		++count;
		cv.notify_all();
	}
	
}

void printfizzbuzz()
{
	for(int i=1; i<=n; i++)
	{	
		unique_lock lock(mtx);
		cv.wait(lock, []{return (count%3==0)&&(count%5==0);});
		cout<<" fizzbuzz , ";

		++count;

		cv.notify_all();
	}
}


void printnumber()
{
	for(int i=1; i<=n; i++)
	{
		unique_lock lock(mtx);
		cv.wait(lock, []{return (count%3!= 0)&&(count%5!= 0);});
		cout<<count<<",";
		 
		++count;
		cv.notify_all();
	}

	
}

int main(){
	
	
	thread t1(printfizz);
	thread t2(printbuzz);
	thread t3(printfizzbuzz);
	thread t4(printnumber);
	


	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}