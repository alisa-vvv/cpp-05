#include <iostream>
#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat	bureaucrat_bad("John", LOWEST_GRADE - 10);
	Bureaucrat	bureaucrat_good("Jane", HIGHEST_GRADE + 10);

	while (1) {
		try {
			std::cout << CLR_YEL << "Before decrement: " << CLR_NON;
			std::cout << bureaucrat_bad << '\n';
			bureaucrat_bad.decrementGrade();
			std::cout << CLR_YEL << "After decrement: " << CLR_NON;
			std::cout << bureaucrat_bad << '\n';
		}
		catch (GradeException &caught_exception) {
			std::cout << CLR_RED;
			std::cout << "Caught excpetion: ";
			std::cout << CLR_YEL << caught_exception.what() << CLR_NON;
			std::cout << " on decrementing " << CLR_YEL;
			std::cout << bureaucrat_bad.getName() << CLR_NON << "'s grade";
			std::cout << '\n';
			break ;
		}
	}
	std::cout << '\n';
	while (1) {
		try {
			std::cout << CLR_YEL << "Before increment: " << CLR_NON;
			std::cout << bureaucrat_good << '\n';
			bureaucrat_good.incrementGrade();
			std::cout << CLR_YEL << "After increment: " << CLR_NON;
			std::cout << bureaucrat_good << '\n';
		}
		catch (GradeException &caught_exception) {
			std::cout << CLR_RED;
			std::cout << "Caught excpetion: ";
			std::cout << CLR_YEL << caught_exception.what() << CLR_NON;
			std::cout << " on incrementing " << CLR_YEL;
			std::cout << bureaucrat_good.getName() << CLR_NON << "'s grade";
			std::cout << '\n';
			break ;
		}
	}
}
