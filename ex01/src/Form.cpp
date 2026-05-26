/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Form.cpp                                                :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/05/26 15:37:35 by avaliull            #+#    #+#           */
/*   Updated: 2026/05/26 15:37:36 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() {
}

Form(const Form& other);
Form&	operator=(const Form& other);
~Form();

const char*	GradeException::what() const noexcept {
	if (_grade_limit == LOWEST_GRADE)
		return ("Grade too low! Can't increment further.");
	if (_grade_limit == HIGHEST_GRADE)
		return ("Grade too high! Can't increment further.");
	return ("Unclear grade exception!\n");
}
