//
// Created by casubmar on 04.12.2020.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form() {}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target): Form("Robot", 72, 45, target) { std::srand(time(NULL));}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute(), src.getTarget()) { std::srand(time(NULL));}
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
	if (this != &rhs) {
		Form::operator=(rhs);
	}
	return (*this);
}

const char * RobotomyRequestForm::RobotomizedFailed::what() const throw() {
	return "bzzz bzz robotomized failed";
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const throw(std::exception) {
	Form::execute(executor);
	if ((rand() % 2) % 2 == 0) {
		std::cout << "bzzz bzzz " << getTarget() << " has been robotomized successfully" << std::endl;
	} else {
		throw RobotomyRequestForm::RobotomizedFailed();
	}
}