#pragma once

class JAVAcodeGenerator : public CodeGenerator
{
public:

	JAVAcodeGenerator() : CodeGenerator()
	{

	}
	virtual~JAVAcodeGenerator()
	{

	}

private:
	std::string someCodeRelatedThing() override
	{
		return "JAVA code thing (:0)\n";
	}

private:
	Lang e_language;
};