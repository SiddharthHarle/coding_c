#include <iostream>
#include <thread>
#include <semaphore>

using namespace std;

std::counting_semaphore<2> sem(2); // Max 2 threads can enter

void worker(int id) {
    sem.acquire(); // Wait for access
    std::cout << "Thread " << id << " entered.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    sem.release(); // Release access
}

int main() {
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    std::thread t3(worker, 3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}
