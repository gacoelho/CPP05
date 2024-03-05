#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Form.hpp"

class Form;
class Bureaucrat
{
    private:
        std::string const _name;
        int               _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(Bureaucrat const &bureaucrat);
        Bureaucrat &operator=(Bureaucrat const &bureaucrat);
        ~Bureaucrat(void);

        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        void signForm(Form& form);
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator <<(std::ostream &o, Bureaucrat const &c);

#endif