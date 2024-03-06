#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shubbery Creation", 145, 137)
{
    std::cout << "Deafault Shubbery CreationForm construtor called" << std::endl;
    this->_target = "Kenndy";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shubbery Creation", 145, 137)
{
    std::cout << "Deafault Shubbery Creation Form construtor called" << std::endl;
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy)
{
    std::cout << "Copy Shubbery Creation Form construtor called" << std::endl;
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
   std::cout << "Destructor called:" << std::endl; 
}
std::string ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    std::cout << "Shubbery Creation Form is assigned" << std::endl;
    this->_target = copy._target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & exec) const
{
    (void)exec;
    if (this->getSigned() == false)
        throw AForm::FormNotSignedException();
    else if (exec.getGrade() > this->getGradeExecute())
        throw AForm::GradeTooLowException();
    std::ofstream file;
    file.open((getTarget() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);
    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "~     \\ /  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      /  \\" << std::endl << std::endl;
    file.close();
}

std::ostream &operator <<(std::ostream &o, ShrubberyCreationForm const &c)
{
    o << c.getName() << ", Shubbery Creation Form: " << c.getName() 
      << ", Grade to sign: " << c.getGradeRequire() 
      << ", Grade to exec:" << c.getGradeExecute()
      << ", Singed: " << c.getSigned() << std::endl;
    return (o); 
}