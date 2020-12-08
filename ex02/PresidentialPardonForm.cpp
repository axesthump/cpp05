//
// Created by casubmar on 04.12.2020.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form() {}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target): Form("Presidential", 25, 5, target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute(), src.getTarget()) {}
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
	if (this != &rhs) {
		Form::operator=(rhs);
	}
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const throw(std::exception) {
	Form::execute(executor);
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox\n";
}