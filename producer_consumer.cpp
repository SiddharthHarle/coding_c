#include <iostream>
#include <queue>
#include <thread>
#include <vector>
#include <semaphore>  // C++20 for semaphores
#include <chrono>
#include <random>

using namespace std;

int BUFFER_SIZE = 5;
std::queue<int> buffer;

// Semaphores
std::binary_semaphore buffer_mutex(1); // Acts as a mutex
std::counting_semaphore<5> empty_slots(5); // Controls empty slots
std::counting_semaphore<0> full_slots(0); // Controls full slots


void producer(int id) {
	do{
		empty_slots.acquire();
		buffer_mutex.acquire();
        int item = id;
        buffer.push(id*id);
        cout<<"produced :: "<<endl;
        //buffer_mutex.release();
		full_slots.release();
	}while(1);
}

void consumer() {
	do{
		empty_slots.acquire();
		//buffer_mutex.acquire();
        buffer.pop();
        cout<<"consumed :: "<<endl;
        //buffer_mutex.release();
		empty_slots.release();
	  }while(1);

}

int main(){
	int num_producers = 3;
    int num_consumers = 3;

    thread t1(producer, 1); 
    thread t2(producer, 1); 
    thread t3(producer, 1); 
    thread t4(consumer); 
    thread t5(consumer); 
    thread t6(consumer); 
    t1.join();
    t2.join();
    t3.join();
    t4.join(); 
    t5.join(); 
    t6.join(); 
    return 0; 

	
}