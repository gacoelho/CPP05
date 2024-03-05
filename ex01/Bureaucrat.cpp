#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("CARLOS"), _grade(15)
{
    std::cout << this->_grade << std::endl;
    std::cout << "Deafault constructor called" << std::endl;
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Constructor called" << std::endl;
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException(); 
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "Assignation operator called" << std::endl;
    if(this != &copy)
        _grade = copy.getGrade();
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
    if(this->_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if(this->_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too High, the best grade you may have is 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low, the worst grade you may have is 150");
}

std::ostream &operator <<(std::ostream &o, Bureaucrat const &c)
{
    o << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;
    return (o); 
}