#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	{
		try {
			Bureaucrat bureaucrat("Sam", 0);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "============================================\n";
	{
		try {
			Bureaucrat bureaucrat("Sam", 1);
			std::cout << bureaucrat << std::endl;
			bureaucrat.upGrade();
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "============================================\n";
	{
		try {
			Bureaucrat bureaucrat("Sam", 151);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "============================================\n";
	{
		try {
			Bureaucrat bureaucrat("Sam", 150);
			std::cout << bureaucrat << std::endl;
			bureaucrat.downGrade();
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "============================================\n";
	{
		try {
			Bureaucrat bureaucrat("Sam", 50);
			for (int i = 0; i < 20; ++i) {
				bureaucrat.downGrade();
				std::cout << bureaucrat << std::endl;
			}
			for (int i = 0; i < 20; ++i) {
				bureaucrat.upGrade();
				std::cout << bureaucrat << std::endl;
			}
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
