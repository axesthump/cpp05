//
// Created by casubmar on 04.12.2020.
//

#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::trees =
		"      /\\      \n"
		"     /\\*\\     \n"
		"    /\\O\\*\\    \n"
		"   /*/\\/\\/\\   \n"
		"  /\\O\\/\\*\\/\\  \n"
		" /\\*\\/\\*\\/\\/\\ \n"
		"/\\O\\/\\/*/\\/O/\\\n"
		"      ||      \n"
		"      ||      \n"
		"      ||      ";

ShrubberyCreationForm::ShrubberyCreationForm(): Form() {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): Form("Shrubbery", 145, 137, target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): Form(src.getName(), src.getGradeToSign(), src.getGradeToExecute(), src.getTarget()) {}
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
	if (this != &rhs) {
		Form::operator=(rhs);
	}
	return (*this);
}

const char * ShrubberyCreationForm::CantCreateFile::what() const throw() {
	return "Cant create file";
}

const char * ShrubberyCreationForm::CantWriteInFile::what() const throw() {
	return "Cant write file";
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const throw(std::exception) {
	Form::execute(executor);
	std::string fileName = this->getTarget() + "_shrubbery";
	std::ofstream f(fileName.c_str());
	if (!f.is_open()) {
		throw ShrubberyCreationForm::CantCreateFile();
	}
	f << ShrubberyCreationForm::trees;
	if (f.bad()) {
		f.close();
		throw ShrubberyCreationForm::CantWriteInFile();
	}
	f << "\n";
	f.close();
}