#include <string>
#include <iostream>

class DBInstance
{
public:
	virtual bool addItemToTable(const std::string& tableName_) = 0;
	virtual ~DBInstance() {
		std::cout << "Destorying DB Instance" << std::endl;
	}
};

class MongoDBInstance : public DBInstance
{
public:
	MongoDBInstance() {
		std::cout << "Creating Mongo DB Instance" << std::endl;
	}
	~MongoDBInstance() {
		std::cout << "Destroying Mongo DB Instance" << std::endl;
	}
	bool addItemToTable(const std::string& tableName_) override
	{
		std::cout << "added item to Mongo DB" << std::endl;
		return true;
	}
};

class MySqlDBInstance : public DBInstance
{
public:
	MySqlDBInstance() {
		std::cout << "Creating MySql DB Instance" << std::endl;
	}
	~MySqlDBInstance() {
		std::cout << "Destroying MySql DB Instance" << std::endl;
	}
	bool addItemToTable(const std::string& tableName_) override
	{
		std::cout << "added item to MySQL DB" << std::endl;
		return true;
	}
};