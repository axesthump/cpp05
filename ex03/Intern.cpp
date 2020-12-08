//
// Created by casubmar on 05.12.2020.
//

#include "Intern.hpp"

const std::string Intern::formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &src) {
	*this = src;
}
Intern & Intern::operator=(const Intern &rhs) {
	(void)rhs;
	return *this;
}

Form * Intern::makePresidentialPardonForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

Form * Intern::makeRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

Form * Intern::makeShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

Form * Intern::makeForm(const std::string &name, std::string const &target) {
	Form * (Intern:: *forms[3])(std::string const&) = {
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm,
		&Intern::makeShrubberyCreationForm
	};
	for (int i = 0; i < 3; ++i) {
		if (name == Intern::formNames[i]) {
			std::cout << "Intern creates " << Intern::formNames[i] << " Form" << std::endl;
			return (this->*forms[i])(target);
		}
	}
	throw Intern::BadFormException();
	return 0;
}

const char * Intern::BadFormException::what() const throw() {
	return "Form is unknown";
}