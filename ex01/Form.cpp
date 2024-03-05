#include "Form.hpp"

Form::Form(void) : _name("worst form"), _sign(false), _grade_r(100), _grade_x(100)
{
    std::cout << "Deafault construtor called" << std::endl;
    if (this->_grade_r < 1 || this->_grade_x < 1)
        throw Form::GradeTooHighException();
    else if (this->_grade_r > 150 || this->_grade_x > 150)
        throw Form::GradeTooLowException();
}

Form::Form(std::string const name,int const grade_r, int const grade_x) : _name(name), _sign(false), _grade_r(grade_r), _grade_x(grade_x)
{
    std::cout << "Construtor called" << std::endl;
    if (this->_grade_r < 1 || this->_grade_x < 1)
        throw Form::GradeTooHighException();
    else if (this->_grade_r > 150 || this->_grade_x > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &copy) : _name(copy.getName()), _sign(copy.getSigned()), _grade_r(copy.getGradeRequire()), _grade_x(copy.getGradeExecute())
{
    std::cout << "Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &copy)
{
    if(this != &copy)
        _sign = copy.getSigned();
    return *this;
}

Form::~Form(void)
{
    std::cout << "Destructor called" << std::endl;
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _sign;
}

int Form::getGradeRequire() const
{
    return _grade_r;
}

int Form::getGradeExecute() const
{
    return _grade_x;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > _grade_r)
        throw Form::GradeTooLowException();
    _sign = true;
}
const char* Form::GradeTooHighException::what() const throw()
{
    return ("F:Grade too High, the best grade you may have is 1");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("F:Grade too low, the worst grade you may have is 150");
}

std::ostream  &operator<<( std::ostream& o, const Form& rhs ) {
    o << "Form name: " << rhs.getName() << std::endl
      << "Grade to sign: " << rhs.getGradeRequire() << std::endl
      << "Grade to execute: " << rhs.getGradeExecute();
    return o;
}