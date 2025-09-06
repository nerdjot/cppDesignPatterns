// CPPDesignPatterns.cpp : Defines the entry point for the application.
//

#include "CPPDesignPatterns.h"
#include "DesignPatterns/Creational/Factory/FactoryClient.h"
//#include "DesignPatterns/Creational/Singleton/SingletonClient.h"
#include "DesignPatterns/Creational/Singleton/SingletonModernClient.h"
#include "DesignPatterns/Creational/Singleton/SingletonAsTemplateClient.h"
#include "DesignPatterns/Structural/Adapter/AdapterClient.h"
#include "DesignPatterns/Behavioral/PubSub/Client.h"

using namespace std;

int main()
{
	//Fatory::
	//clientCode(Database::MONGO_DB);

	//Singleton::
	//singletonClientCode();

	//SingletonModern::
	//singletonModernClientCode();

	//SingletonAsTemplate::
	//singletonAsTemplateClientCode();

	//Adapter::
	//clientCode();

	//Pubsub::
	pubsubClientCode();

	return 0;
}
