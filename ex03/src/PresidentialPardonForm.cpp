/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   PresidentialPardonForm.cpp                              :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/08/01 16:05:53 by avaliull            #+#    #+#           */
/*   Updated: 2026/08/01 16:08:25 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

/*	Canonical form stuff	*/
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	:	AForm(target + "_pardon", 25, 5),
		_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	:	AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade())
{
}

PresidentialPardonForm::~PresidentialPardonForm() {}
/**/

void	PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const {
	confirmCanExecute(bureaucrat);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}

AForm*	PresidentialPardonForm::newAForm(const std::string& target) const {
	return (new PresidentialPardonForm(target));
}
