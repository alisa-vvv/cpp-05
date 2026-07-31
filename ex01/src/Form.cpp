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
#include <iostream>

/*	Exceptions	*/
FormException::FormException(const std::string& msg)
	:	_msg(msg)
{}

const char*	FormException::what() const noexcept {
	return (_msg.c_str());
}
const FormException	Form::GradeTooHighException = [] {
	const FormException	GradeTooHighException("Grade too high\n");
	return (GradeTooHighException);
}();
const FormException	Form::GradeTooLowException = [] {
	const FormException	GradeTooLowException("Grade too low\n");
	return (GradeTooLowException);
}();
/**/

/*	Canonical form stuff	*/
Form::Form(
	const std::string& name,
	const unsigned int sign_grade,
	const unsigned int execute_grade
)
	:	_name(name),
		_sign_grade(sign_grade),
		_execute_grade(execute_grade)
{
	if (sign_grade < _highest_grade) {
		throw(GradeTooHighException);
	}
	else if (sign_grade > _lowest_grade) {
		throw(GradeTooLowException);
	}
	if (execute_grade < _highest_grade) {
		throw(GradeTooHighException);
	}
	else if (execute_grade > _lowest_grade) {
		throw(GradeTooLowException);
	}
}

Form::Form(const Form& other)
	:	_name(other.getName()),
		_sign_grade(other.getSignGrade()),
		_execute_grade(other.getExecuteGrade())
{
}

Form::~Form() {}
/**/

/*	Setters and getters	*/
const std::string&	Form::getName() const {
	return (_name);
}

const unsigned int&	Form::getSignGrade() const {
	return (_sign_grade);
}

const unsigned int&	Form::getExecuteGrade() const {
	return (_execute_grade);
}

const bool&	Form::isSigned() const {
	return (_is_signed);
}
/**/

std::ostream&	operator<<(std::ostream& os, const Form& form) {
	(void) form;
	os << "Form: " << form.getName() << "\n";
	os << "\tSign grade: " << form.getSignGrade() << '\n';
	os << "\tExecute grade: " << form.getExecuteGrade() << '\n';
	os << '\t' << ((form.isSigned()) ? "Signed" : "Not signed") << '\n';
	return (os);
}
