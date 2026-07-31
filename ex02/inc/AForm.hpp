/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   AAForm.hpp                                                :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/07/30 17:08:45 by avaliull            #+#    #+#           */
/*   Updated: 2026/07/31 18:17:05 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <string>

class	FormException : std::exception {
public:
	FormException(const std::string& msg);
	const char*	what() const noexcept;
private:
	std::string	_msg;
};

class AForm {
public:
/*	Canonical form stuff	*/
	AForm() = delete;
	AForm(
		const std::string& name,
		unsigned int sign_grade,
		unsigned int execute_grade
	);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other) = delete;
	virtual ~AForm() = 0;
/**/
/*	Setters and getters	*/
	virtual const std::string&	getName() const = 0;
	virtual const unsigned int&	getSignGrade() const = 0;
	virtual const unsigned int&	getExecuteGrade() const = 0;
	virtual const bool&			isSigned() const = 0;
/**/
	virtual void	beSigned(const Bureaucrat& bureaucrat) = 0;
private:
	const std::string	_name;
	const unsigned int	_sign_grade;
	const unsigned int	_execute_grade;
	bool				_is_signed = false;

	static const int	_highest_grade = 1;
	static const int	_lowest_grade = 150;

	static const FormException	GradeTooHighException;
	static const FormException	GradeTooLowException;
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);
