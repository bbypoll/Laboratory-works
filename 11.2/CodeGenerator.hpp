#pragma once
#include <iostream>
#include <string>
#include <vector>

class Languages 
{
protected:
    std::string m_extension;
public:
    Languages() 
    {
        std::cout << "Base class: CONSTRUCTOR" << std::endl;
    };
    virtual ~Languages() 
    {
        std::cout << "Base class: DESTRUCTOR" << std::endl;
    };

    virtual std::string someRelatedThing() = 0;

};


class C_PLUS_PLUS : public Languages 
{
private:
public:
    C_PLUS_PLUS() : Languages() 
    {

        std::cout << "C_PLUS_PLUS constructor" << std::endl;
        m_extension = "cpp";
    };
    virtual ~C_PLUS_PLUS() 
    {
        std::cout << "C_PLUS_PLUS class: destructor" << std::endl;
    };
    std::string someRelatedThing() override
    {
        std::cout << "C_PLUS_PLUS class: someRelatedThing function" << std::endl;
        std::string code = "c++_code." + m_extension;
        return code;
    }
};

class Java : public Languages 
{
private:
public:
    Java() : Languages() 
    {

        std::cout << "Java constructor" << std::endl;
        m_extension = "java";
    };
    virtual ~Java() 
    {
        std::cout << "Java class: destructor" << std::endl;
    };
    std::string someRelatedThing() override
    {
        std::cout << "Java class: someRelatedThing function" << std::endl;
        std::string code = "java_code." + m_extension;
        return code;
    }
};

class PHP : public Languages 
{
private:
public:
    PHP() : Languages() 
    {

        std::cout << "PHP constructor" << std::endl;
        m_extension = "php";
    };
    virtual ~PHP() 
    {
        std::cout << "PHP class: destructor" << std::endl;
    };
    std::string someRelatedThing() override 
    {
        std::cout << "PHP class: someRelatedThing function" << std::endl;
        std::string code = "php_code." + m_extension;
        return code;
    }
};

std::string generateCode(std::string& inputLanguage) 
{
    std::unique_ptr<Languages> lang;
    if (inputLanguage == "C++") 
    {
        lang = std::make_unique<C_PLUS_PLUS>(C_PLUS_PLUS());
        return lang->someRelatedThing();
    }
    else if (inputLanguage == "Java") 
    {
        lang = std::make_unique<Java>(Java());
        return lang->someRelatedThing();
    }
    else if (inputLanguage == "PHP") 
    {
        lang = std::make_unique<PHP>(PHP());
        return lang->someRelatedThing();
    }
    else 
    {
        throw std::logic_error("WRONG");
    };

}
