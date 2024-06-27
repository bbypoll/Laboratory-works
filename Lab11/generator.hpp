#pragma once
#include <iostream>
#include "CPP.hpp"
#include "PHP.hpp"
#include "JAVA.hpp"


enum Lang      //перечисление enum, в данном случае языки 
{
	JAVA = 0, C_PLUS_PLUS = 1, PHP = 2
};

class CodeGenerator
{
public:
	CodeGenerator()
	{
		

	}
	virtual ~CodeGenerator()
	{

	}

	std::string generateCode()
	{
		return someCodeRelatedThing();
	}

protected:
	virtual std::string someCodeRelatedThing() = 0;
	

protected:
	Lang e_language;
};