//
// Created by casubmar on 04.12.2020.
//

#ifndef EX02_SHRUBBERYCREATIONFORM_HPP
#define EX02_SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm: public Form {

public:
	class CantCreateFile: public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class CantWriteInFile: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);
	virtual ~ShrubberyCreationForm();

	virtual void execute(Bureaucrat const & executor) const throw(std::exception);

	static const std::string trees;

private:
	ShrubberyCreationForm();

};


#endif //EX02_SHRUBBERYCREATIONFORM_HPP
