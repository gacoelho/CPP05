#ifndef PRESIDENTIALPARDON_HPP
# define PRESIDENTIALPARDON_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string const name,int const grade_r, int const grade_x);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);
        ~PresidentialPardonForm(void);
        void execute(Bureaucrat const & executor) const;
};
std::ostream &operator <<(std::ostream &o, AForm const &c);

#endif