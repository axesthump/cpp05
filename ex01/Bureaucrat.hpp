//
// Created by casubmar on 04.12.2020.
//

#ifndef EX00_BUREAUCRAT_HPP
#define EX00_BUREAUCRAT_HPP

#include "iostream"
#include "Form.hpp"

class Form;

class Bureaucrat {

public:
	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};

	Bureaucrat();
	Bureaucrat(Bureaucrat const& bureaucrat);
	Bureaucrat& operator=(Bureaucrat const& bureaucrat);
	virtual ~Bureaucrat();

	Bureaucrat(std::string const& name, int grade) throw(GradeTooHighException, GradeTooLowException);
	std::string const& getName() const;
	int getGrade() const;
	void upGrade() throw(GradeTooHighException);
	void downGrade() throw(GradeTooLowException);

	void signForm(Form& form) const;

private:
	std::string const	_name;
	int 				_grade;

};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& bureaucrat);


#endif //EX00_BUREAUCRAT_HPP
