#pragma once

class PHPcodeGenerator : public CodeGenerator
{
public:

	PHPcodeGenerator() : CodeGenerator()
	{

	}
	virtual~PHPcodeGenerator()
	{

	}

	std::string someCodeRelatedThing() override
	{
		return "PHP code thing (--)\n";
	}

private:
	Lang e_language;
};
