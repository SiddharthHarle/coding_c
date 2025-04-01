#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


using namespace std;

mutex mtx;
condition_variable cv;
bool zeroturn=true;
int n=10;
int count=1;

void printzero()
{
	for(int i=1; i<=n; i++)
	{
		unique_lock lock(mtx);
		cv.wait(lock,[]{return zeroturn;});
		cout<<" 0 ";

		zeroturn=false;
		cv.notify_all();

	}

}

void printodd()
{
	for(int i=1; i<=n; i+=2)
	{
		unique_lock lock(mtx);
		cv.wait(lock,[]{return !zeroturn && (count%2==1);});
		cout<<i;
		count++;
		zeroturn=true;
		cv.notify_all();
	}
	
}

void printeven()
{
	for(int i=2; i<=n; i+=2)
	{
		unique_lock lock(mtx);
		cv.wait(lock,[]{return !zeroturn && (count%2==0);});
		cout<<i;
		count++;
		zeroturn=true;
		cv.notify_all();
	}
}

int main()
{
	thread t1( printzero );
	thread t2( printodd );
	thread t3( printeven );

	t1.join();
	t2.join();
	t3.join();
	cout<<endl;
	
	return 0;
}