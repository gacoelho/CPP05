#include "Bureaucrat.hpp"

int main( void )
{

    try {
        Bureaucrat bureaucrat("ash",11);
        Form form("formName", 2, 100);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat bureaucrat("dash",1);
        Form form("formName", 1, 100);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}