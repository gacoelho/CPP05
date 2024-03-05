#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        std::string const _name;
        bool              _sign;
        const int        _grade_r;
        const int        _grade_x;
    public:
        Form(void);
        Form(std::string const name,int const grade_r, int const grade_x);
        Form(Form const &copy);
        Form &operator=(Form const &copy);
        ~Form(void);

        std::string getName() const;
        bool getSigned() const;
        int getGradeRequire() const;
        int getGradeExecute() const;
        void beSigned(const Bureaucrat& bureaucrat);
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};
std::ostream &operator <<(std::ostream &o, Form const &c);

#endif