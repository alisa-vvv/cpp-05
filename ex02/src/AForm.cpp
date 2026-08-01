/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   AForm.cpp                                               :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/07/30 17:10:32 by avaliull            #+#    #+#           */
/*   Updated: 2026/08/01 16:24:46 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

/*	Exceptions	*/
FormException::FormException(const std::string& msg)
	:	_msg(msg)
{}

const char*	FormException::what() const noexcept {
	return (_msg.c_str());
}
const FormException	AForm::GradeTooHighException = [] {
	const FormException	GradeTooHighException("Grade too high\n");
	return (GradeTooHighException);
}();
const FormException	AForm::GradeTooLowException = [] {
	const FormException	GradeTooLowException("Grade too low\n");
	return (GradeTooLowException);
}();
const FormException	AForm::FormNotSignedException = [] {
	const FormException	GradeTooLowException("Form not signed\n");
	return (GradeTooLowException);
}();
/**/

/*	Canonical form stuff	*/
AForm::AForm(
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

AForm::AForm(const AForm& other)
	:	_name(other.getName()),
		_sign_grade(other.getSignGrade()),
		_execute_grade(other.getExecuteGrade()),
		_is_signed(other.isSigned())
{
}

AForm::~AForm() {}
/**/

/*	Setters and getters	*/
const std::string&	AForm::getName() const {
	return (_name);
}

const unsigned int&	AForm::getSignGrade() const {
	return (_sign_grade);
}

const unsigned int&	AForm::getExecuteGrade() const {
	return (_execute_grade);
}

const bool&	AForm::isSigned() const {
	return (_is_signed);
}
/**/

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (this->_is_signed) {
		throw AForm::FormNotSignedException;
	}
	if (bureaucrat.getGrade() > this->getSignGrade()) {
		throw AForm::GradeTooLowException;
	}
	this->_is_signed = true;
	std::cout << bureaucrat.getName() << " signed " << this->getName() << '\n';
}

std::ostream&	operator<<(std::ostream& os, const AForm& form) {
	os << "Form:\t" << form.getName() << "\n";
	os << "\tSign grade: " << form.getSignGrade() << '\n';
	os << "\tExecute grade: " << form.getExecuteGrade() << '\n';
	os << '\t' << ((form.isSigned()) ? "Signed" : "Not signed") << '\n';
	return (os);
}

void	AForm::confirmCanExecute(const Bureaucrat& bureaucrat) const {
	if (!this->isSigned()) {
		throw (FormNotSignedException);
	}
	if (bureaucrat.getGrade() > this->getExecuteGrade()) {
		throw (GradeTooLowException);
	}
}
