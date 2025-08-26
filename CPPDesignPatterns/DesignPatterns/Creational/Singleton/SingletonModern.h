//In C++11 there is a thread safe way to create a Singleton without using any mutex
//This can be achieved using the static keyword inside the function.


class Singleton
{
private:
	Singleton() {};//private constructor
	~Singleton() {};//private destructor
	Singleton(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;

public:
	static Singleton& GetInstance()
	{
		static Singleton instance;
		return instance;
	}
};