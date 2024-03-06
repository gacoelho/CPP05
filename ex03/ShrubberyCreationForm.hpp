#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string const name);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);
        ~ShrubberyCreationForm(void);
        void execute(Bureaucrat const & executor) const;
        std::string getTarget() const;
};
std::ostream &operator <<(std::ostream &o, ShrubberyCreationForm const &c);

#endif