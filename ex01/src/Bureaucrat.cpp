/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Bureaucrat.cpp                                          :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/07/31 17:35:07 by avaliull            #+#    #+#           */
/*   Updated: 2026/07/31 18:20:36 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

/*	Exceptions	*/
const BureaucratException	Bureaucrat::GradeTooHighException = [] {
	const BureaucratException	GradeTooHighException("Grade too high\n");
	return (GradeTooHighException);
}();
const BureaucratException	Bureaucrat::GradeTooLowException = [] {
	const BureaucratException	GradeTooLowException("Grade too low\n");
	return (GradeTooLowException);
}();
/**/

/*	Canonical form stuff	*/
Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade)
	:	_name(name)
{
	if (grade < _highest_grade) {
		throw(GradeTooHighException);
	}
	else if (grade > _lowest_grade) {
		throw(GradeTooLowException);
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:	_name(other._name)
{
	this->_grade = other._grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}
/**/

/*	Setters and getters	*/
const unsigned int&	Bureaucrat::getGrade() const {
	return (_grade);
}

const std::string&	Bureaucrat::getName() const {
	return (_name);
}
/**/

/*	Changing grade	*/
void	Bureaucrat::incrementGrade() {
	if (_grade == _highest_grade) {
		throw(GradeTooHighException);
	}
	_grade--;
}
void	Bureaucrat::decrementGrade() {
	if (_grade == _lowest_grade) {
		throw(GradeTooLowException);
	}
	_grade++;
}
/**/

/*	Exceptions	*/
BureaucratException::BureaucratException(const std::string& msg)
	:	_msg(msg)
{}

const char*	BureaucratException::what() const noexcept {
	return (_msg.c_str());
}
/**/

/*	ostream overload	*/
std::ostream&	operator<<(
	std::ostream& os,
	const Bureaucrat& bureaucrat
) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << '\n';
	return (os);
}
/**/

void	Bureaucrat::signForm(Form& form) const {
	if (form.isSigned()) {
		std::cout << this->getName() << " couldn't sign " << form.getName();
		std::cout << " because it's already signed\n";
		return ;
	}
	try {
		form.beSigned(*this);
	}
	catch (const FormException& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName();
		std::cout << " because " << e.what();
	}
}
