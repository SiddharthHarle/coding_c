#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
using namespace std::chrono;

int oddsum=0;
int evensum=0;

int N=1000000000;

void evensumf()
{
	for(int i=0;i<=N;i+=2)
	{
		evensum+=i;
	}
	cout<<"evensum is : "<<evensum<<endl;;
}

void oddsumf()
{
	for(int i=1;i<=N;i+=2)
	{
		oddsum+=i;
	}
	cout<<"oddsum is :"<<oddsum<<endl;
}


int main(int argc, char **argv)
{
	thread t1(evensumf);
	thread t2(oddsumf);
	//t1.join();
	//t2.join();
	

	auto start=std::chrono::high_resolution_clock::now();
	//evensumf();
	//oddsumf();
	//thread t1(evensumf);
	//thread t2(oddsumf);
	t1.join();
	t2.join();
	auto end=std::chrono::high_resolution_clock::now();
	auto ms_int = std::chrono::duration_cast<std::chrono::seconds>(end - start);
	cout<<" Time Taken: "<<ms_int.count()<<endl;
	return 0;
}