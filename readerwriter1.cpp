#include<iostream>
#include<shared_mutex>
#include<thread>
#include <condition_variable>
#include<vector>

using namespace std;

shared_mutex rwmtx;
int shared_data=0;




void reader()
{
	shared_lock<shared_mutex> lock(rwmtx);
	cout<<"read happed :: "<<shared_data;

}

void writer()
{	unique_lock<shared_mutex> lock(rwmtx);
	cout<<"write happed :: "<<++shared_data;	
}


int main()
{
	vector<std::thread> threads;

	for(int i=0;i<=5;i++)
	{
		threads.emplace_back(reader);
	}

	for(int i=0;i<=5;i++)
	{
		threads.emplace_back(writer);
	}

		for(auto &t:threads){
		cout<<"threads: "<<&t<<endl ;
		t.join();
	}
	return 0;

}