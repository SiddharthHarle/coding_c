#include<iostream>
#include<semaphore>
#include<thread>

using namespace std;

binary_semaphore zerop(1);
binary_semaphore oddp(0);
binary_semaphore evenp(0);
int n=10;

void printzero()
{
	for(int i=1;i<=n;i++)
	{
	zerop.acquire();
	cout<<" 0 ";
	
	if(i%2==1)
		oddp.release();
	else
		evenp.release();

	}
}

void printodd()
{
	for(int i=1;i<=n;i+=2)
	{
	oddp.acquire();
	cout<<i;
	
	zerop.release();

	}
}

void printeven()
{
	for(int i=2;i<=n;i+=2)
	{
	evenp.acquire();
	cout<<i;
	
	zerop.release();

	}
}

int main()
{
	thread t1(printzero);
	thread t2(printodd);
	thread t3(printeven);

	t1.join();
	t2.join();
	t3.join();
	cout<<endl;
	return 0;
}