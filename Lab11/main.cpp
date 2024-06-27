#include "generator.hpp"
#include <iostream>

int main()
{
	JAVAcodeGenerator java;
	std::cout << java.generateCode();
	CPPcodeGenerator cpp;
	std::cout << cpp.generateCode();
	PHPcodeGenerator php;
	std::cout << php.generateCode();

	return 0;
}
