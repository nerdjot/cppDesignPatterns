#pragma once
#include "SingletonAsTemplate.h"

void singletonAsTemplateClientCode()
{
	Logger& logger = SingletonAsTemplate<Logger>::GetInstance();
	logger.logError("bad gateway!");
	
	Parser& parser = SingletonAsTemplate<Parser>::GetInstance();
	parser.parse("ohh man error happened");
}
