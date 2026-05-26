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

/*
* Form constructors
*/
Form::Form(std::string name, int sign_grade, int exec_grade) 
	:	GradeTooLowException	(LOWEST_GRADE),
		GradeTooHighException	(HIGHEST_GRADE),
		_name					(name),
		_is_signed				(false),
		_sign_grade				(sign_grade),
		_exec_grade				(exec_grade)
{
	if (sign_grade < HIGHEST_GRADE || exec_grade < HIGHEST_GRADE)
		throw(GradeTooHighException);
	if (sign_grade > LOWEST_GRADE || exec_grade > LOWEST_GRADE)
		throw(GradeTooLowException);
}

Form::Form(const Form& other)
	:	GradeTooLowException	(other.GradeTooLowException),
		GradeTooHighException	(other.GradeTooHighException),
		_name					(other._name),
		_is_signed				(other._is_signed),
		_sign_grade				(other._sign_grade),
		_exec_grade				(other._exec_grade)
{}

Form::~Form() {}
/*
*/

/*
* Form overloads
*/
Form&	Form::operator=(const Form& other) {
	if (this != &other)
		*this = other;
	return (*this);
}
/*
*/

/*
* Form methods
*/
const std::string&	Form::getName() const {
	return (_name);
}
int	Form::getSignGrade() const {
	return (_sign_grade);
}
int	Form::getExecGrade() const {
	return (_exec_grade);
}
void	Form::beSigned(Bureaucrat signer) {
	if (signer.getGrade() > this->getSignGrade()) {
		throw(GradeTooLowException);
	}
	_is_signed = true;
}
/*
*/
