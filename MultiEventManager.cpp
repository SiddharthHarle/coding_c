#include<iostream>
#include<vector>
#include<functional>
#include<string>
#include<unordered_map>

using namespace std;


class Eventmanager{

private:
	typedef void (*funptr)(string);
	std::vector <funptr> callbacks;
	unordered_map <std::string,std::vector<funptr>> EventListeners;

public: 
	void registerCB(std::string eventType,funptr fp)
	{
		EventListeners[eventType].push_back(fp);
	}

	void triggerEvent(std::string eventType)
	{

		cout<<"Event triggered :: "<<eventType<<endl;
		for(auto &cb : EventListeners[eventType])
		{
			cb(eventType);
			//cout<<eventType;
		}
	}
};

// Listener functions
void onLogin(std::string event) {
    std::cout << "[Login Handler] Received event: " << event << std::endl;
}

void onLogin1(std::string event) {
    std::cout << "[Login Handler] Received event: " << event << std::endl;
}

void onLogout(std::string event) {
    std::cout << "[Logout Handler] Received event: " << event << std::endl;
}

void onLogout1(std::string event) {
    std::cout << "[Logout Handler] Received event: " << event << std::endl;
}
int main()
{
	Eventmanager evm;
	 
    // Register multiple callbacks for different events
    evm.registerCB("UserLoggedIn", onLogin);
    evm.registerCB("UserLoggedIn", onLogin1);
    evm.registerCB("UserLoggedOut", onLogout);
    evm.registerCB("UserLoggedOut", onLogout1);

	 evm.triggerEvent("UserLoggedIn");
	 evm.triggerEvent("UserLoggedOut");
	return 0;
}
