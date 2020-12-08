//
// Created by casubmar on 04.12.2020.
//

#ifndef EX02_RobotomyRequestForm_HPP
#define EX02_RobotomyRequestForm_HPP
#include "Form.hpp"
#include <cstdlib>
#include <time.h>

class RobotomyRequestForm: public Form {

public:
	class RobotomizedFailed: public std::exception {
	public:
		virtual const char* what() const throw();
	};

	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm(RobotomyRequestForm const& src);
	RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);
	virtual ~RobotomyRequestForm();

	virtual void execute(Bureaucrat const & executor) const throw(std::exception);

private:
	RobotomyRequestForm();

};


#endif //EX02_RobotomyRequestForm_HPP
