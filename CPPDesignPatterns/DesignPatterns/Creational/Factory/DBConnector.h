#include <string>
#include "DBInstance.h"

enum Database
{
	MONGO_DB,
	MYSQL_DB
};

class DBConnector
{
public:
	 DBInstance* createDBInstance(Database dbName_)
	 {
		 if (dbName_ == Database::MONGO_DB)
			return new MongoDBInstance();
		 else if (dbName_ == Database::MYSQL_DB)
			 return new MySqlDBInstance();
		 return nullptr;
	 }
};