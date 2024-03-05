#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string const name);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
        ~RobotomyRequestForm(void);
        void execute(Bureaucrat const & executor) const;
};
std::ostream &operator <<(std::ostream &o, RobotomyRequestForm const &c);

#endif