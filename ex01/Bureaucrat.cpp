//
// Created by casubmar on 04.12.2020.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("std"), _grade(50) {}
Bureaucrat::Bureaucrat(const std::string &name,
					   int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException):
		_name(name), _grade(grade){
	if (this->_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (this->_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat): _name(bureaucrat.getName()), _grade(bureaucrat.getGrade()) {}
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	if (this != &bureaucrat) {
		this->_grade = bureaucrat.getGrade();
	}
	return *this;
}

const std::string & Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::upGrade() throw(Bureaucrat::GradeTooHighException) {
	if (this->_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		this->_grade -= 1;
	}
}

void Bureaucrat::downGrade() throw(Bureaucrat::GradeTooLowException) {
	if (this->_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		this->_grade += 1;
	}
}

void Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << *this << " signs " << form << std::endl;
	} catch (Form::GradeTooLowException& e) {
		std::cout << *this << " cannot sign " << form
				  << " because grade is too low" << std::endl;
	} catch (std::exception& e) {
		std::cout << *this << " cannot sign " << form
				  << " because form is already signed" << std::endl;
	}
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "The grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return "The grade is too low";
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& bureaucrat) {
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return o;
}