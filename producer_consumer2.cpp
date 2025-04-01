#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>
#include<deque>

using namespace std;

mutex mtx;
condition_variable cv_producer,cv_consumer;
deque<int> buffer;
bool done = false;

int max_buffer_size=50;
int val=50;

void producer()
{
	while(val){
		std::unique_lock<mutex> lock(mtx);
		cv_producer.wait(lock, [] { return buffer.size()<max_buffer_size;});
		buffer.push_back(val);
		cout<<"produced :: "<<val<<endl;
		val--;
		lock.unlock();
		cv_consumer.notify_one();
	}

	// {   // Notify consumer that production is done
    //     std::unique_lock<std::mutex> lock(mtx);
    //     done = true;
    // 	cv_consumer.notify_all();
        
    // }

	std::this_thread::sleep_for(std::chrono::milliseconds(100));

}


void consumer()
{
	while(true){
		std::unique_lock<mutex> lock(mtx);
		cv_consumer.wait(lock, []() {return !buffer.empty()||done;});
		if (buffer.empty() && done) break;
		int val=buffer.back();
		buffer.pop_back();
		cout<<"consumed :: "<<val<<endl;
		lock.unlock();
		cv_producer.notify_one();
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

}


int main()
{
	thread t1(producer);
	thread t2(consumer);
	//thread t3(producer);
	//thread t4(consumer);

	t1.join();
	t2.join();
	//t3.join();
	//t4.join();

	return 0;
}