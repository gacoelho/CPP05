#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request", 72, 45)
{
    std::cout << "Deafault Robotomy Request Form construtor called" << std::endl;
    this->_target = "Kenndy";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45)
{
    std::cout << "Deafault Robotomy Request Form construtor called" << std::endl;
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy)
{
    std::cout << "Copy Robotomy Request Form construtor called" << std::endl;
    *this = copy;
} 

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << "Presidential Pardon Form is assigned" << std::endl;
    this->_target = copy._target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & exec) const
{
    if (this->getSigned() == false)
        throw AForm::FormNotSignedException();
    else if (exec.getGrade() > this->getGradeExecute())
        throw AForm::GradeTooLowException();
    else
    {
        srand(time(0));
        if (rand() % 2 == 0)
            std::cout << this->_target << " has been robotomized" << std::endl;
        else
            std::cout << this->_target << " could not be robotomized" << std::endl;
    }   
}

std::ostream &operator <<(std::ostream &o, RobotomyRequestForm const &c)
{
    o << c.getName() << ", Robotomy Request Form: " << c.getName() 
      << ", Grade to sign: " << c.getGradeRequire() 
      << ", Grade to exec:" << c.getGradeExecute()
      << ", Singed: " << c.getSigned() << std::endl;
    return (o); 
}