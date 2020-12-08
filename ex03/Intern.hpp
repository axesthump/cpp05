//
// Created by casubmar on 05.12.2020.
//

#ifndef EX03_INTERN_HPP
#define EX03_INTERN_HPP
#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {

public:
	class BadFormException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	Intern();
	Intern(Intern const& src);
	Intern& operator=(Intern const& rhs);
	~Intern();

	Form* makeForm(std::string const& name, std::string const& target);
	static const std::string formNames[3];

private:
	Form* makeShrubberyCreationForm(std::string const& target);
	Form* makePresidentialPardonForm(std::string const& target);
	Form* makeRobotomyRequestForm(std::string const& target);
};


#endif //EX03_INTERN_HPP
