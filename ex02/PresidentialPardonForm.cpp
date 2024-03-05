#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon", 25, 5)
{
    std::cout << "Deafault Presidential PardonForm construtor called" << std::endl;
    this->_target = "Kenndy";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5)
{
    std::cout << "Deafault Presidential PardonForm construtor called" << std::endl;
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy)
{
    std::cout << "Copy Presidential PardonForm construtor called" << std::endl;
    *this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    std::cout << "Presidential Pardon Form is assigned" << std::endl;
    this->_target = copy._target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & exec) const
{
    if (this->getSigned() == false)
        throw AForm::FormNotSignedException();
    else if (exec.getGrade() > this->getGradeExecute())
        throw AForm::GradeTooLowException();
    else
        std::cout << this->_target << " has being pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream &operator <<(std::ostream &o, PresidentialPardonForm const &c)
{
    o << c.getName() << ", Presidential Pardon Form: " << c.getName() 
      << ", Grade to sign: " << c.getGradeRequire() 
      << ", Grade to exec:" << c.getGradeExecute()
      << ", Singed: " << c.getSigned() << std::endl;
    return (o); 
}