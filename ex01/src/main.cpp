#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	Bureaucrat	jared("Jared", 149);
	Bureaucrat	alina("Alina", 2);
	Form		form("lol", 123, 123);

	try {
		Form	form2("lol", 11, 14);
	}
	catch (const FormException& e) {
		std::cout << e.what();
	}
	Form	valid_form("naam", 12, 13);
	std::cout << valid_form;
	Form	copied_form(valid_form);
	std::cout << valid_form;
}
