//
// Created by casubmar on 04.12.2020.
//

#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class ShrubberyCreationForm;

class Form {

public:
	class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FileNoSignedException: public std::exception {
		virtual const char* what() const throw();
	};


	Form();
	Form(std::string const& name, int gradeToSign, int gradeToExecute, std::string const& target) throw(GradeTooLowException, GradeTooHighException);
	Form(Form const& form);
	Form& operator=(Form const& form);
	virtual ~Form();

	std::string const& getName() const;
	int	getGradeToSign() const;
	int getGradeToExecute() const;
	bool checkIsSigned() const;
	std::string const& getTarget() const;

	void beSigned(Bureaucrat const& bureaucrat) throw(GradeTooLowException, std::exception);
	virtual void execute(Bureaucrat const & executor) const throw(std::exception);

private:
	std::string const _name;
	int const _gradeToSign;
	int const _gradeToExecute;
	bool _isSigned;
	std::string const _target;

};

std::ostream& operator<<(std::ostream& o, Form const& form);


#endif //EX01_FORM_HPP
