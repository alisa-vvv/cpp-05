/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Form.cpp                                                :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/07/30 17:10:32 by avaliull            #+#    #+#           */
/*   Updated: 2026/07/30 17:11:05 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*	Exceptions	*/
const GradeException	Form::GradeTooHighException = [] {
	const GradeException	GradeTooHighException("Grade too high\n");
	return (GradeTooHighException);
}();
const GradeException	Form::GradeTooLowException = [] {
	const GradeException	GradeTooLowException("Grade too low\n");
	return (GradeTooLowException);
}();
/**/

/*	Canonical form stuff	*/
Form::Form(
	const std::string& name,
	unsigned int sign_grade,
	unsigned int execute_grade
)
	:	_name(name)
{
	if (sign_grade < _highest_grade) {
		throw(GradeTooHighException);
	}
	else if (sign_grade > _lowest_grade) {
		throw(GradeTooLowException);
	}
	_sign_grade = sign_grade;
	if (execute_grade < _highest_grade) {
		throw(GradeTooHighException);
	}
	else if (execute_grade > _lowest_grade) {
		throw(GradeTooLowException);
	}
	_execute_grade = execute_grade;
}

Form::Form(const Form& other) {
	*this = other;
}

Form&	Form::operator=(const Form& other) {
	if (this != &other)
		*this = other;
	return (*this);
}

Form::~Form() {}
