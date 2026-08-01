#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {
	Bureaucrat	jared("Jared", 150);
	Bureaucrat	alina("Alina", 1);

	Intern		unpayed;

	std::cout << CLR_YEL << "SHRUBBERY EXAMPLE:" << CLR_NON << '\n';
	AForm*	home = unpayed.makeForm("ShrubberyCreationForm", "home");
	std::cout << *home;
	alina.executeForm(*home);
	jared.signForm(*home);
	alina.signForm(*home);
	jared.executeForm(*home);
	alina.executeForm(*home);
	std::cout << *home;
	delete home;
	std::cout << '\n';

	std::cout << CLR_YEL << "ROBOTOMY EXAMPLE:" << CLR_NON << '\n';
	AForm*	victim = unpayed.makeForm("RobotomyRequestForm", "Unwilling participant");
	std::cout << *victim;
	jared.signForm(*victim);
	alina.signForm(*victim);
	jared.executeForm(*victim);
	alina.executeForm(*victim);
	std::cout << *victim;
	delete victim;
	std::cout << '\n';

	std::cout << CLR_YEL << "PRESIDENTIAL PARDON EXAMPLE:" << CLR_NON << '\n';
	AForm*	war_criminal = unpayed.makeForm("PresidentialPardonForm", "War criminal");
	std::cout << *war_criminal;
	jared.signForm(*war_criminal);
	alina.signForm(*war_criminal);
	jared.executeForm(*war_criminal);
	alina.executeForm(*war_criminal);
	std::cout << *war_criminal;
	delete war_criminal;
	std::cout << '\n';
}
