#include <iostream>
#include "SingletonModern.h"

void singletonModernClientCode()
{
	Singleton& singleton = Singleton::GetInstance();
	std::cout << &singleton << std::endl;

	Singleton& singleton2 = Singleton::GetInstance();
	std::cout << &singleton2 << std::endl;
}

