#include<iostream>
#include <thread>
#include<vector>

using namespace std;

void hellothread()
{
	cout<<"Hello Thread :: "<<this_thread::get_id()<<endl;
}
int main(int argc,char** argv)
{

	cout<<"Main Thread :: "<<this_thread::get_id()<<endl;
	int n=thread::hardware_concurrency();

	cout<<"Hardware threads:: "<<n<<endl;
	// thread t1(hellothread);
	// thread t2(hellothread);
	// t1.join();
	// t2.join();

	vector<thread> threads;
	
	for(int i=0;i<5;i++)
		threads.push_back(thread(hellothread));

	for(int i=0;i<5;i++)
		threads[i].join();
	return 0;
}