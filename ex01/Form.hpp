#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <exception>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
    private:
        std::string const _name;
        bool              _sign;
        int const         _grade;
        int const         _grade_r;
    public:
        Form(void);
        Form(std::string const name,int const grade, int const grade_r);
        Form(Form const &copy);
        Form &operator=(Form const &copy);
        ~Form(void);

        std::string Form::getName() const;
        bool Form::getSign() const;
        int Form::getGrade() const;
        int Form::getRequiredGrade() const;
        void Form::beSigned(Bureaucrat const &bureaucrat) const;
};
std::ostream &operator <<(std::ostream &o, Form const &c);


#endif