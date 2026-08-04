#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main() {
	Bureaucrat	jared("Jared", 150);
	Bureaucrat	alina("Alina", 1);

	// copy/assign test
//	Bureaucrat	copy(alina);
//	Bureaucrat	copy_assign("new_name", 50);
//	copy_assign = jared;
//	std::cout << copy;
//	std::cout << copy_assign;
//	std::cout << '\n';

	Intern		unpayed;

	std::cout << CLR_YEL << "FAKE FORM NAME EXAMPLE" << CLR_NON << '\n';
	AForm*	fake_norm = unpayed.makeForm("fake_form_name", "fake_norm");
	std::cout << fake_norm << '\n';
	std::cout << '\n';

	std::cout << CLR_YEL << "SHRUBBERY EXAMPLE:" << CLR_NON << '\n';
	AForm*	home = unpayed.makeForm("ShrubberyCreationForm", "home");
	std::cout << *home;
	alina.executeForm(*home);
	jared.signForm(*home);
	alina.signForm(*home);
	std::cout << *home;
	jared.executeForm(*home);
	alina.executeForm(*home);
	delete home;
	std::cout << '\n';

	std::cout << CLR_YEL << "ROBOTOMY EXAMPLE:" << CLR_NON << '\n';
	AForm*	victim = unpayed.makeForm("RobotomyRequestForm", "Unwilling participant");
	std::cout << *victim;
	alina.executeForm(*victim);
	jared.signForm(*victim);
	alina.signForm(*victim);
	std::cout << *victim;
	jared.executeForm(*victim);
	alina.executeForm(*victim);
	delete victim;
	std::cout << '\n';

	std::cout << CLR_YEL << "PRESIDENTIAL PARDON EXAMPLE:" << CLR_NON << '\n';
	AForm*	war_criminal = unpayed.makeForm("PresidentialPardonForm", "War criminal");
	std::cout << *war_criminal;
	alina.executeForm(*war_criminal);
	jared.signForm(*war_criminal);
	alina.signForm(*war_criminal);
	std::cout << *victim;
	jared.executeForm(*war_criminal);
	alina.executeForm(*war_criminal);
	std::cout << *war_criminal;
	delete war_criminal;
	std::cout << '\n';
}
