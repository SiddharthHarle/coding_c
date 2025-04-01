#include<iostream>
#include<vector>
#include<mutex>
#include<functional>
#include <string>
#include<thread>


using namespace std;

class EventManager{

private:
		vector<function<void(string&)>> callbacks;
		mutex mtx;
public:
		void registerCB(function<void(string&)> cb)
		{
			lock_guard lock(mtx);
			callbacks.push_back(cb);
		}

		void triggerEvent(string eventName)
		{
			lock_guard lock(mtx);
			for(auto &cb:callbacks){
				cb(eventName);
			}

		}
};

void listener(string& event) {
    std::cout << "Listener received: " << event << std::endl;
}

int main(int argc,char** argv)
{
	EventManager evm;

	  // Register callbacks
	evm.registerCB(listener);
	evm.registerCB([](string& event) {
        std::cout << "Lambda received event: " << event << std::endl;
    });

	    // Simulate concurrent event triggering
    std::thread t1([&]() { evm.triggerEvent("Thread Event 1"); });
    std::thread t2([&]() { evm.triggerEvent("Thread Event 2"); });

    t1.join();
    t2.join();


	return 0;
}