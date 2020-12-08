#include <iostream>
#include "Form.hpp"
#include "Intern.hpp"

int main() {
	{
		try {
			Intern i;
			i.makeForm("some", "home");
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=====================================\n";
	{
		try {
			Intern i;
			Form* f = i.makeForm("robotomy request", "home");
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=====================================\n";
	{
		try {
			Intern i;
			Form* f = i.makeForm("shrubbery creation", "home");
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=====================================\n";
	{
		try {
			Intern i;
			Form* f = i.makeForm("presidential pardon", "home");
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
