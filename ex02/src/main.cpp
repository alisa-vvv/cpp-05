#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	Bureaucrat	jared("Jared", 150);
	Bureaucrat	alina("Alina", 1);

	std::cout << CLR_YEL << "SHRUBBERY EXAMPLE:" << CLR_NON << '\n';
	ShrubberyCreationForm	home("home");
	std::cout << home;
	alina.executeForm(home);
	jared.signForm(home);
	alina.signForm(home);
	jared.executeForm(home);
	alina.executeForm(home);
	std::cout << home;
	std::cout << '\n';

	std::cout << CLR_YEL << "ROBOTOMY EXAMPLE:" << CLR_NON << '\n';
	RobotomyRequestForm		this_joke_is_too_dark("Unwilling participant");
	std::cout << this_joke_is_too_dark;
	jared.signForm(this_joke_is_too_dark);
	alina.signForm(this_joke_is_too_dark);
	jared.executeForm(this_joke_is_too_dark);
	alina.executeForm(this_joke_is_too_dark);
	std::cout << this_joke_is_too_dark;
	std::cout << '\n';

	std::cout << CLR_YEL << "PRESIDENTIAL PARDON EXAMPLE:" << CLR_NON << '\n';
	PresidentialPardonForm	pardon_example("pardon_example");
	std::cout << pardon_example;
	jared.signForm(pardon_example);
	alina.signForm(pardon_example);
	jared.executeForm(pardon_example);
	alina.executeForm(pardon_example);
	std::cout << pardon_example;
	std::cout << '\n';
}
