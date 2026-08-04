#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	Bureaucrat	jared("Jared", 150);
	Bureaucrat	alina("Alina", 1);

	// copy test
//	Bureaucrat	copy(alina);
//	Bureaucrat	copy_assign("new_name", 50);
//	copy_assign = jared;
//	std::cout << copy;
//	std::cout << copy_assign;
//	std::cout << '\n';

	std::cout << CLR_YEL << "SHRUBBERY EXAMPLE:" << CLR_NON << '\n';
	ShrubberyCreationForm	home("home");
	std::cout << home;
	alina.executeForm(home);
	jared.signForm(home);
	alina.signForm(home);
	std::cout << home;
	jared.executeForm(home);
	alina.executeForm(home);
	std::cout << '\n';

	std::cout << CLR_YEL << "ROBOTOMY EXAMPLE:" << CLR_NON << '\n';
	RobotomyRequestForm		victim("Unwilling participant");
	std::cout << victim;
	jared.signForm(victim);
	alina.signForm(victim);
	std::cout << victim;
	jared.executeForm(victim);
	alina.executeForm(victim);
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
