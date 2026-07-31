/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   ShrubberyCreationForm.cpp                               :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/07/31 18:52:11 by avaliull            #+#    #+#           */
/*   Updated: 2026/07/31 19:15:38 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*	Canonical form stuff	*/
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:	AForm(target + "_shrubbery", 145, 137),
		_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:	AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
/**/

void	ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
	if (!this->isSigned()) { // make an exception here i guess
		return ;
	}
	if (bureaucrat.getGrade() > this->getExecuteGrade()) {
		throw (GradeTooLowException);
	}
}
