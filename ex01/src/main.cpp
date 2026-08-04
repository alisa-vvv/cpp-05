#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	Bureaucrat	jared("Jared", 149);
	Bureaucrat	alina("Alina", 2);
	
	// copy test
//	Bureaucrat	copy(alina);
//	Bureaucrat	copy_assign("new_name", 50);
//	copy_assign = jared;
//	std::cout << copy;
//	std::cout << copy_assign;
//	std::cout << '\n';

	Form		form("easy_form", 123, 123);

	try {
		Form	form2("easy_form", 11, 14);
	}
	catch (const FormException& e) {
		std::cout << e.what();
	}

	Form	hard_form("hard_form", 12, 13);
	std::cout << hard_form;

	Form	copied_form(hard_form);

	jared.signForm(hard_form);
	std::cout << hard_form;
	alina.signForm(hard_form);
	std::cout << hard_form;

	//std::cout << copied_form; // this shows that the copy is deep
}
