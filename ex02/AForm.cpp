#include "AForm.hpp"

AForm::AForm(void) : _name("worst form"), _sign(false), _grade_r(100), _grade_x(100)
{
    std::cout << "Deafault construtor called" << std::endl;
    if (this->_grade_r < 1 || this->_grade_x < 1)
        throw AForm::GradeTooHighException();
    else if (this->_grade_r > 150 || this->_grade_x > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(std::string const name,int const grade_r, int const grade_x) : _name(name), _sign(false), _grade_r(grade_r), _grade_x(grade_x)
{
    std::cout << "Construtor called" << std::endl;
    if (this->_grade_r < 1 || this->_grade_x < 1)
        throw AForm::GradeTooHighException();
    else if (this->_grade_r > 150 || this->_grade_x > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &copy) : _name(copy.getName()), _sign(copy.getSigned()), _grade_r(copy.getGradeRequire()), _grade_x(copy.getGradeExecute())
{
    std::cout << "Copy constructor called" << std::endl;
}

AForm &operator=(AForm const &copy)
{
    if(this != &copy)
        _sign = copy.getSigned();
    return *this;
}

AForm::~AForm(void)
{
    std::cout << "Destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _sign;
}

int AForm::getGradeRequire() const
{
    return _grade_r;
}

int AForm::getGradeExecute() const
{
    return _grade_x;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > _grade_r)
        throw AForm::GradeTooLowException();
    _sign = true;
}
const char* AForm::GradeTooHighException::what() const throw()
{
    return ("F:Grade too High, the best grade you may have is 1");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("F:Grade too low, the worst grade you may have is 150");
}

std::ostream  &operator<<( std::ostream& o, const AForm& rhs ) {
    o << "Form name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeRequire() << std::endl
      << "Grade to execute: " << rhs.getGradeExecute();
    return o;
}