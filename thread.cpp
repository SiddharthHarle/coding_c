#include<iostream>
#include<thread>


using namespace std;


void print()
{
	cout<<"Welcome to concurrent world"<<endl;
}

int main(int argc, char **argv)
{
	thread t(print);
	t.join();

	return 0;
}