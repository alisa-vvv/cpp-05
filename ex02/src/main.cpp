#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	Bureaucrat	jared("Jared", 149);
	Bureaucrat	alina("Alina", 2);

	ShrubberyCreationForm	home("home");
	std::cout << home;
	alina.signForm(home);
}
