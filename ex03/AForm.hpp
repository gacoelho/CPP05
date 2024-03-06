#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
    private:
        std::string const _name;
        bool              _sign;
        const int        _grade_r;
        const int        _grade_x;
    public:
        AForm(void);
        AForm(std::string const name,int const grade_r, int const grade_x);
        AForm(AForm const &copy);
        AForm &operator=(AForm const &copy);
        virtual ~AForm(void);

        std::string getName() const;
        bool getSigned() const;
        int getGradeRequire() const;
        int getGradeExecute() const;

        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & exec) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};
std::ostream &operator <<(std::ostream &o, AForm const &c);

#endif