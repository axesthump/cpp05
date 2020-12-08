//
// Created by casubmar on 04.12.2020.
//

#include "Form.hpp"

Form::Form(): _name("stdForm"), _gradeToExecute(50), _gradeToSign(50), _isSigned(false), _target("") {}

Form::Form(const Form &form): _name(form.getName()), _gradeToSign(form.getGradeToSign()),
							  _gradeToExecute(form.getGradeToExecute()), _isSigned(form.checkIsSigned()) {}

Form & Form::operator=(const Form &form) {
	if (this != &form) {
		this->_isSigned = form.checkIsSigned();
	}
	return *this;
}

Form::Form(const std::string &name, int gradeToSign,
		   int gradeToExecute, std::string const& target = "") throw(Form::GradeTooLowException, Form::GradeTooHighException):
		_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false), _target(target) {
	if (this->_gradeToExecute < 1 || this->_gradeToSign < 1) {
		throw GradeTooHighException();
	} else if (this->_gradeToExecute > 150 || this->getGradeToSign() > 150) {
		throw GradeTooLowException();
	}
}

Form::~Form() {}

const std::string & Form::getName() const { return this->_name; }
int Form::getGradeToSign() const { return this->_gradeToSign; }
int Form::getGradeToExecute() const { return this->_gradeToExecute; }
bool Form::checkIsSigned() const { return this->_isSigned; }
const std::string & Form::getTarget() const { return this->_target; }

void Form::beSigned(const Bureaucrat &bureaucrat) throw(Form::GradeTooLowException, std::exception) {
	if (checkIsSigned()) {
		throw std::exception();
	}
	else if (bureaucrat.getGrade() <= this->_gradeToSign) {
		this->_isSigned = true;
	} else {
		throw GradeTooLowException();
	}
}

void Form::execute(const Bureaucrat &executor) const throw(std::exception) {
	if (!this->_isSigned) {
		throw Form::FileNoSignedException();
	}
	else if (this->_gradeToExecute < executor.getGrade()) {
		throw Form::GradeTooLowException();
	}
}

const char * Form::GradeTooLowException::what() const throw() {
	return "*form* this grade to low";
}

const char * Form::GradeTooHighException::what() const throw() {
	return "*form* this grade to high";
}

const char * Form::FileNoSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& o, Form const& form) {
	o << form.getName();
	return o;
}