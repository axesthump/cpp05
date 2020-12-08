#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	{
		try {
			Bureaucrat sam("Sam", 150);
			Form* form = new ShrubberyCreationForm("home");
			sam.signForm(*form);
			sam.executeForm(*form);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=========================\n";
	{
		try {
			Bureaucrat sam("Sam", 145);
			Form* form = new ShrubberyCreationForm("home");
			sam.signForm(*form);
			sam.executeForm(*form);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=========================\n";
	{
		try {
			Bureaucrat sam("Sam", 135);
			Form* form = new ShrubberyCreationForm("home");
			sam.signForm(*form);
			sam.executeForm(*form);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=========================\n";
	{
		try {
			Bureaucrat sam("Sam", 135);
			Form* form = new RobotomyRequestForm("home");
			sam.signForm(*form);
			sam.executeForm(*form);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=========================\n";
	{
		try {
			Bureaucrat sam("Sam", 30);
			Form* form = new RobotomyRequestForm("home");
			sam.signForm(*form);
			sam.executeForm(*form);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=========================\n";
	{
		try {
			Bureaucrat sam("Sam", 30);
			Form* form = new PresidentialPardonForm("Steve");
			sam.signForm(*form);
			sam.executeForm(*form);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=========================\n";
	{
		try {
			Bureaucrat sam("Sam", 1);
			Form* form = new PresidentialPardonForm("Steve");
			sam.signForm(*form);
			sam.executeForm(*form);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
