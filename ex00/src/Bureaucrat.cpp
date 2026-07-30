/* ************************************************************************** */ /*                                                                            */
/*                                                            ::::::::        */
/*   Bureaucrat.cpp                                          :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/05/05 16:23:22 by avaliull            #+#    #+#           */
/*   Updated: 2026/05/05 18:35:15 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

/*	Exceptions	*/
const GradeException	Bureaucrat::GradeTooHighException = [] {
	const GradeException	GradeTooHighException("Grade too high\n");
	return (GradeTooHighException);
}();
const GradeException	Bureaucrat::GradeTooLowException = [] {
	const GradeException	GradeTooLowException("Grade too low\n");
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
{
	*this = other;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		*this = other;
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
		throw(GradeTooHighException);
	}
	_grade++;
}
/**/

/*	Exceptions	*/
GradeException::GradeException(const std::string& msg)
	:	_msg(msg)
{}

const char*	GradeException::what() const noexcept {
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
