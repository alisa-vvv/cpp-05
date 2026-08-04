#include <iostream>
#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat	jared("Jared", 149);
	Bureaucrat	alina("Alina", 2);

	// copy test
	Bureaucrat	copy(alina);
	Bureaucrat	copy_assign("new_name", 50);
	copy_assign = jared;
	std::cout << copy;
	std::cout << copy_assign;
	std::cout << '\n';

	std::cout << CLR_YEL << "Initial state:" << CLR_NON << '\n';
	std::cout << jared;
	std::cout << alina;
	std::cout << '\n';

	std::cout << CLR_YEL << "Incrementing alina:" << CLR_NON << '\n';
	alina.incrementGrade();
	std::cout << alina;
	try  {
		alina.incrementGrade();
	}
	catch (GradeException& e) {
		std::cout << e.what();
	}
	std::cout << alina;
	std::cout << '\n';

	std::cout << CLR_YEL << "Decrementing jared:" << CLR_NON << '\n';
	jared.decrementGrade();
	std::cout << jared;
	try  {
		jared.decrementGrade();
	}
	catch (GradeException& e) {
		std::cout << e.what();
	}
	std::cout << jared;
	std::cout << '\n';

	std::cout << CLR_YEL << "Bad initialiaztion:" << CLR_NON << '\n';
	try {
		Bureaucrat	cheater_pumpkin_eater("Cheater - pumpkin eater", 0);
	}
	catch (GradeException& e) {
		std::cout << e.what();
	}
	try {
		Bureaucrat	liar_pants_on_fire("Liar - pants on fire", 151);
	}
	catch (GradeException& e) {
		std::cout << e.what();
	}
}
