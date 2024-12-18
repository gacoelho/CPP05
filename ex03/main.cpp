#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <iostream>

int main() {
	std::cout << "\n========== BUREAUCRAT ==========\n" << std::endl;

	Bureaucrat *bob = new Bureaucrat("Bob", 2);
	try {
		std::cout << "1: " << *bob << std::endl;
		bob->incrementGrade();
		std::cout << "2: " << *bob << std::endl;
		bob->incrementGrade();
		std::cout << "3: " << *bob << std::endl;
		bob->incrementGrade();
		std::cout << "4: " << *bob << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete bob;

	std::cout << std::endl;

	Bureaucrat *jim = new Bureaucrat("Jim", 10);
	try {
		std::cout << "1: " << *jim << std::endl;
		jim->incrementGrade();
		std::cout << "2: " << *jim << std::endl;
		jim->incrementGrade();
		std::cout << "3: " << *jim << std::endl;
		jim->incrementGrade();
		std::cout << "4: " << *jim << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete jim;

	std::cout << std::endl;

	Bureaucrat *luffy = new Bureaucrat("Luffy", 145);
	try {
		std::cout << "1: " << *luffy << std::endl;
		luffy->decrementGrade();
		std::cout << "2: " << *luffy << std::endl;
		luffy->decrementGrade();
		std::cout << "3: " << *luffy << std::endl;
		luffy->decrementGrade();
		std::cout << "4: " << *luffy << std::endl;
		luffy->decrementGrade();
		std::cout << "5: " << *luffy << std::endl;
		luffy->decrementGrade();
		std::cout << "6: " << *luffy << std::endl;
		luffy->decrementGrade();
		std::cout << "7: " << *luffy << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete luffy;

	std::cout << std::endl;

	try {
		Bureaucrat yuno("Yuno", 151);
		std::cout << "HELLO WORLD!!!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat yuno("Yuno", -1);
		std::cout << "HELLO WORLD!!!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== FORM ==========\n" << std::endl;

	std::cout << "CREATE BUREAUCRATS:" << std::endl;
	Bureaucrat* b150 = new Bureaucrat("b150", 150);
	Bureaucrat* b140 = new Bureaucrat("b140", 140);
	Bureaucrat* b100 = new Bureaucrat("b100", 100);
	Bureaucrat* b1 = new Bureaucrat("b1", 1);

	std::cout << std::endl;

	std::cout << "PRINT BUREAUCRATS:" << std::endl;
	std::cout << *b150 << std::endl;
	std::cout << *b140 << std::endl;
	std::cout << *b100 << std::endl;
	std::cout << *b1 << std::endl;

	std::cout << std::endl;

	std::cout << "CREATE INTERN:" << std::endl;
	Intern* intern = new Intern();
	std::cout << std::endl;

	std::cout << "INTERN CREATES FORMS:" << std::endl;
	//ShrubberyCreationForm *garden = new ShrubberyCreationForm("garden");
	AForm *garden = intern->makeForm("shrubbery creation", "garden");
	std::cout << std::endl;

	//RobotomyRequestForm *neighbor = new RobotomyRequestForm("neighbor");
	AForm *neighbor = intern->makeForm("robotomy request", "neighbor");
	std::cout << std::endl;

	//PresidentialPardonForm *rick = new PresidentialPardonForm("rick");
	AForm *rick = intern->makeForm("presidential pardon", "rick");
	std::cout << std::endl;

	AForm *budgets = intern->makeForm("budgets", "morty");
	std::cout << std::endl;

	std::cout << "DELETE INTERN:" << std::endl;
	delete intern;

	std::cout << std::endl;

	std::cout << "FORMS MEMEORY ADDRESS:" << std::endl;
	std::cout << "shrubbery creation: " << garden << std::endl;
	std::cout << "robotomy request: " << neighbor << std::endl;
	std::cout << "presidential pardon: " << rick << std::endl;
	std::cout << "budgets (not exists so intern doesn't create it): " << budgets << std::endl;

	std::cout << std::endl;

	std::cout << "PRINT FORMS:" << std::endl;
	std::cout << *garden << std::endl;
	std::cout << *neighbor << std::endl;
	std::cout << *rick << std::endl;

	std::cout << std::endl;

	std::cout << "TEST SHRUBBERY CREATION:" << std::endl;
	// ShrubberyCreationForm
	try { // try to execute before sign
		b100->executeForm(*garden);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try { // try to sign with low level
		b150->signForm(*garden);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try { // sign
		b140->signForm(*garden);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *garden << std::endl; // display update info
	try { // try to execute with low level
		b140->executeForm(*garden);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try { // execute
		b100->executeForm(*garden);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "TEST ROBOTOMY REQUEST:" << std::endl;
	// RobotomyRequestForm (execute main multiple times to check randomizer is working)
	try { // sign
		b1->signForm(*neighbor);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try { // execute
		b1->executeForm(*neighbor);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "TEST PRESIDENTIAL PARDON:" << std::endl;
	// PresidentialPardonForm
	try { // sign
		b1->signForm(*rick);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try { // execute
		b1->executeForm(*rick);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "DELETE FORMS:" << std::endl;
	delete garden;
	delete neighbor;
	delete rick;

	std::cout << std::endl;

	std::cout << "DELETE BUREAUCRATS:" << std::endl;
	delete b150;
	delete b140;
	delete b100;
	delete b1;

	return 0;
}