#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	{
		try {
			Bureaucrat sam("sam", 50);
			Form form("SB-13", 151, 1);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=================\n";
	{
		try {
			Bureaucrat sam("sam", 50);
			Form form("SB-13", 150, 0);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=================\n";
	{
		try {
			Bureaucrat sam("sam", 50);
			Form form("SB-13", 49, 1);
			sam.signForm(form);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=================\n";
	{
		try {
			Bureaucrat sam("sam", 50);
			Form form("SB-13", 50, 1);
			sam.signForm(form);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "=================\n";
	{
		try {
			Bureaucrat sam("sam", 50);
			Form form("SB-13", 50, 1);
			sam.signForm(form);
			sam.signForm(form);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
