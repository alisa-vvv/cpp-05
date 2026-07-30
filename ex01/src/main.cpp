#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	Bureaucrat	jared("Jared", 149);
	Bureaucrat	alina("Alina", 2);
	Form		form("lol", 123, 123);

	try {
		Form	form2("lol", 0, 123);
	}
	catch (const GradeException& e) {
		std::cout << e.what();
	}
}
