#include <iostream>

//This is old way to create a singleton it is not thread safe
//To make it thread safe we have to make sure that only one thread is able to call new/delete at once!
//Can be achieved by adding a mutex and locking before new or delete.

class Singleton
{
private:
	static Singleton* instance;
	Singleton() {		//private constructor
		std::cout << "Instance created!" << std::endl;
	}; 
	Singleton(const Singleton& other) {};//private copy constructor, not calling as good as delete
	~Singleton() {//private destructor
		std::cout << "Instance destroyed!" << std::endl;
	}; 
public:
	static Singleton* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new Singleton();//calling private constructor.
		}
		return instance;
	}

	static void RemoveInstance()
	{
		if (instance == nullptr)
			return;
		delete instance; //this will call the private destructor
	}
};