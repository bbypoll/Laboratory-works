#pragma once

class CPPcodeGenerator : public CodeGenerator
{
public:

	CPPcodeGenerator() : CodeGenerator()
	{

	}
	virtual~CPPcodeGenerator()
	{

	}

	std::string someCodeRelatedThing() override
	{
		return "CPP code thing (^-^)\n";
	}

private:
	Lang e_language;
};