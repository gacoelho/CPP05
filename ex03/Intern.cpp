#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Default Intern construtor called" << std::endl;
}

Intern::Intern(const Intern & copy)
{
    std::cout << "Copy Intern construtor called" << std::endl;
    *this = copy;
}

Intern::~Intern(void)
{
    std::cout << "Intern Destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern & copy)
{
  std::cout << "Intern assigment operator" << std::endl;
  if (this == &copy)
    return *this;
  return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    static const int n = 3;
    t_forms forms[n] = {
        { "shrubbery creation", new ShrubberyCreationForm(target) },
		{ "robotomy request", new RobotomyRequestForm(target) },
		{ "presidential pardon", new PresidentialPardonForm(target) }
    };
    AForm* ret = NULL;
    for (int i = 0; i < n; i++)
    {
        if (forms[i].name ==name)
            ret = forms[i].formClass;
        else    
            delete forms[i].formClass;
    }

    if (ret != NULL) 
        std::cout << "Intern creats form" << name << std::endl;
    else 
        std::cout << "Intern could not creat form" << name << std::endl;
    return ret;
}