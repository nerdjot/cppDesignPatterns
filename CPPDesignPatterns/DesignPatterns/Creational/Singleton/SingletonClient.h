#include "Singleton.h"
#include <iostream>

Singleton* Singleton::instance;
void singletonClientCode()
{
	Singleton* s_ptr1 = Singleton::GetInstance();
	std::cout << s_ptr1 << std::endl;
	Singleton* s_ptr2 = Singleton::GetInstance();
	std::cout << s_ptr2 << std::endl;

	//delete s_ptr1; //Inaccessible error, as expected
	s_ptr1->RemoveInstance();
	std::cout << s_ptr2 << std::endl;
}