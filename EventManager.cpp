#include<iostream>
#include<vector>
#include<functional>
#include<string>

using namespace std;


class Eventmanager{

private:
	typedef void (*funptr)(int, int);
	vector<funptr> callbacks;

public: 
	void registerCB(funptr fp)
	{

		callbacks.push_back(fp);
	}

	void triggerEvent(int a, int b)
	{

		cout<<"Event "<<" triggered"<<endl;
		for(auto &cb:callbacks)
		{
			cb(a,b);
		}
	}
};

void sum(int a,int b)
{
	cout<<"Operation is ::sum "<<a+b<<endl;
}

void multiply(int a,int b)
{
	cout<<"Operation is :: Multiply "<<a*b<<endl;
}

int main()
{
	Eventmanager evm;
	 
	evm.registerCB(sum);
	evm.registerCB(multiply);

	evm.triggerEvent(5,10);
	return 0;
}
