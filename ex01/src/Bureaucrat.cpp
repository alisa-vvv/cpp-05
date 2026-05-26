/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Bureaucrat.cpp                                          :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/05/05 16:23:22 by avaliull            #+#    #+#           */
/*   Updated: 2026/05/26 15:42:40 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

/*
 * Bureaucrat constructors
*/
Bureaucrat::Bureaucrat(std::string name, int grade)
	:	GradeTooLowException(LOWEST_GRADE),
		GradeTooHighException(HIGHEST_GRADE),
		_name(name)
{
	if (grade < HIGHEST_GRADE)
		throw(GradeTooHighException);
	if (grade > LOWEST_GRADE)
		throw(GradeTooLowException);
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:	GradeTooLowException(LOWEST_GRADE),
		GradeTooHighException(HIGHEST_GRADE),
		_name(other._name),
		_grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}
/*
 */

/*
 * Bureaucrat overloads
 */
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		*this = other;
	}
	return (*this);
}
std::ostream& operator<<(
	std::ostream& stream,
	const Bureaucrat& bureaucrat
) {
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade(); 	
	return (stream);
}
/*
 */

/*
 * Bureaucrat methods
 */
const std::string&	Bureaucrat::getName() const {
	return (_name);
}
int	Bureaucrat::getGrade() const {
	return (_grade);
}
void	Bureaucrat::incrementGrade() {
	if (_grade == HIGHEST_GRADE)
		throw(GradeTooHighException);
	_grade--;
}
void	Bureaucrat::decrementGrade() {
	if (_grade == LOWEST_GRADE) {
		throw(GradeTooLowException);
	}
	_grade++;
}
/*
 */

/*
 * GradeException constructors
*/
GradeException::GradeException(int grade_limit)
	:	_grade_limit(grade_limit) {}

GradeException::GradeException(const GradeException& other)
	:	_grade_limit(other._grade_limit) {
}

GradeException&	GradeException::operator=(const GradeException& other) {
	if (this != &other) {
		*this = other;
	}
	return (*this);
}


GradeException::~GradeException() {}

const char*	GradeException::what() const noexcept {
	if (_grade_limit == LOWEST_GRADE)
		return ("Grade too low! Can't increment further.");
	if (_grade_limit == HIGHEST_GRADE)
		return ("Grade too high! Can't increment further.");
	return ("Unclear grade exception!\n");
}
/*
 */
