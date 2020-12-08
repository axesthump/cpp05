//
// Created by casubmar on 04.12.2020.
//

#ifndef EX02_PRESIDENTIALPARDONFORM_HPP
#define EX02_PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"

class PresidentialPardonForm: public Form {

public:
	PresidentialPardonForm(std::string const& target);
	PresidentialPardonForm(PresidentialPardonForm const& src);
	PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);
	virtual ~PresidentialPardonForm();

	virtual void execute(Bureaucrat const & executor) const throw(std::exception);

private:
	PresidentialPardonForm();

};



#endif //EX02_PRESIDENTIALPARDONFORM_HPP
