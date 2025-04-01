#include<iostream>
#include<thread>
#include<vector>
#include<shared_mutex>
#include<mutex>
#include<chrono>


using namespace std;

std::shared_mutex rw_mtx;
int shared_data=0;


void reader(int id)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	std::shared_lock lock(rw_mtx); // Shared lock for reading
	cout<<this_thread::get_id()<<":--> "<<id<<"-> Reads:: "<<shared_data<<endl;
	//cout<<id<<"-> Reads:: "<<shared_data<<endl;
	


}

void writer(int id)
{	
	std::this_thread::sleep_for(std::chrono::milliseconds(3));
	unique_lock lock(rw_mtx);
	//shared_data++;
	cout<<this_thread::get_id()<<"--> "<<id<<"-> Writes:: "<<++shared_data<<endl;
	//cout<<id<<"-> Writes:: "<<++shared_data<<endl;
 
	
}


int main(int argc,char** argv)
{

	vector<thread> threads;

	
	for(int i=0;i<5;i++)
	{
	threads.emplace_back(writer,i);
	
	}
	//threads.emplace_back(writer,2);

	for(int i=0;i<5;i++)
	{
		threads.emplace_back(reader,i);
	}

	for(auto &t:threads){
		cout<<"threads: "<<&t<<endl ;
		t.join();
	}
cout<<"Written:: "<<shared_data<<endl;
	return 0;
}