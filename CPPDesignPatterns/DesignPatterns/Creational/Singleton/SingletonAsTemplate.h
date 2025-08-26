//You can have multiple singletons they all look simialr you templatize a Singleton Base
//Make each Derive from it, this is a bit different.
//THis is also called a  CRTP (Curiously Repeating Template Pattern)
#include <iostream>


template <typename T>
class SingletonAsTemplate
{
protected:
	SingletonAsTemplate() {};	//Protected constructor, so derived class can call it
	~SingletonAsTemplate() {};	//Protected deconstructor
	
	SingletonAsTemplate(const SingletonAsTemplate&) = delete;
	SingletonAsTemplate(SingletonAsTemplate&&) = delete;

public:
	static T& GetInstance()
	{
		static T instance;//will call derived class's constructor
		return instance;
	}
};

class Logger : SingletonAsTemplate<Logger>
{
	friend class SingletonAsTemplate<Logger>;//make base class friend, because Base class calls, derive constructor, which is also private
private:
	Logger() {};
public:
	void logDebug(const char* message_)
	{
		std::cout << "DEBUG:: " << message_ << std::endl;
	}
	void logError(const char* message_)
	{
		std::cout << "ERROR:: " << message_ << std::endl;
	}
};

class Parser : SingletonAsTemplate<Parser>
{
	friend class SingletonAsTemplate<Parser>;//make base class friend, because Base class calls, derive constructor, which is also private
private:
	Parser() {};
public:
	void parse(const char* message_)
	{
		std::cout << "Parsed output:: " << message_ << std::endl;
	}
};

