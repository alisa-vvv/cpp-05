/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   AForm.hpp                                               :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/07/30 17:08:45 by avaliull            #+#    #+#           */
/*   Updated: 2026/07/31 19:46:47 by avaliull            ########   odam.nl   */
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
	virtual ~AForm();
/**/
/*	Setters and getters	*/
	const std::string&	getName() const;
	const unsigned int&	getSignGrade() const;
	const unsigned int&	getExecuteGrade() const;
	const bool&			isSigned() const;
/**/
	void			beSigned(const Bureaucrat& bureaucrat);
	virtual void	execute(const Bureaucrat& bureaucrat) const = 0;

	/*	For Factory	*/
	typedef AForm*	(*newFormPtr)(const std::string& target);
	/**/

protected:
	static const FormException	GradeTooHighException;
	static const FormException	GradeTooLowException;
	static const FormException	FormNotSignedException;
	void	confirmCanExecute(const Bureaucrat& bureaucrat) const;

private:
	const std::string	_name;
	const unsigned int	_sign_grade;
	const unsigned int	_execute_grade;
	bool				_is_signed = false;

	static const int	_highest_grade = 1;
	static const int	_lowest_grade = 150;
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);
