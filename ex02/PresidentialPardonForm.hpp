#ifndef PRESIDENTIALPARDON_HPP
# define PRESIDENTIALPARDON_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string const name);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);
        ~PresidentialPardonForm(void);
        void execute(Bureaucrat const & executor) const;
};
std::ostream &operator <<(std::ostream &o, PresidentialPardonForm const &c);

#endif