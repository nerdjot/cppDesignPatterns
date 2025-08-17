#include "FactoryClient.h"

void clientCode(Database dbName_)
{
	DBConnector dbConnector;
	DBInstance* dbInstance = dbConnector.createDBInstance(Database::MONGO_DB);
	dbInstance->addItemToTable("nameTable");

	DBInstance* dbInstance2 = dbConnector.createDBInstance(Database::MYSQL_DB);
	dbInstance->addItemToTable("nameTable");
}