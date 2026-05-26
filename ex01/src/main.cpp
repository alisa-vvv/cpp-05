#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	Form	newForm("name", HIGHEST_GRADE, HIGHEST_GRADE);
	Bureaucrat	unskilled_bureaucrat("bad", LOWEST_GRADE + 10);
	newForm.beSigned(unskilled_bureaucrat);
}
