//
// Created by casubmar on 04.12.2020.
//

#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:
	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};


	Form();
	Form(std::string const& name, int gradeToSign, int gradeToExecute) throw(GradeTooLowException, GradeTooHighException);
	Form(Form const& form);
	Form& operator=(Form const& form);
	~Form();

	std::string const& getName() const;
	int	getGradeToSign() const;
	int getGradeToExecute() const;
	bool checkIsSigned() const;

	void beSigned(Bureaucrat const& bureaucrat) throw(GradeTooLowException, std::exception);

private:
	std::string const _name;
	int const _gradeToSign;
	int const _gradeToExecute;
	bool _isSigned;

};

std::ostream& operator<<(std::ostream& o, Form const& form);


#endif //EX01_FORM_HPP
