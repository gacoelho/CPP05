#ifndef INTERN_HPP_
# define INTERN_HPP_

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>

class Intern
{
    private:
        typedef struct s_forms
        {   
            std::string name;
            AForm *formClass;
        } t_forms;

    public:
            Intern(void);
            Intern(const Intern & copy);
            ~Intern(void);
            Intern& operator=(const Intern & other) ;
            AForm* makeForm(std::string name, std::string target);
};

#endif