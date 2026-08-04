/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Intern.cpp                                              :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/08/01 19:13:02 by avaliull            #+#    #+#           */
/*   Updated: 2026/08/01 19:13:55 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

const std::string	Intern::_form_names[FORM_TYPES_COUNT]	{
	"ShrubberyCreationForm",
	"RobotomyRequestForm",
	"PresidentialPardonForm",
};

const AForm::newFormPtr	Intern::_new_form_ptrs[FORM_TYPES_COUNT] {
	&ShrubberyCreationForm::newShrubberyForm,
	&RobotomyRequestForm::newRobotomyForm,
	&PresidentialPardonForm::newPresidentialPardonForm,
};

/*	Canonical form stuff	*/
Intern::Intern() {
}

Intern::~Intern() {
}
/**/

AForm*	Intern::makeForm(
	const std::string& form_name,
	const std::string& form_target
) {
	for (int i = 0; i < FORM_TYPES_COUNT; i++) {
		if (_form_names[i] == form_name) {
			AForm*	new_form;
			try {
				new_form = _new_form_ptrs[i](form_target);
			}
			catch (const std::exception &e) {
				std::cout << CLR_RED << "Intern could not create form " << form_name
					<< " because " << e.what();
				return (nullptr);
			}
			std::cout << "Intern creates " << form_name << '\n';
			return (new_form);
		}
	}
	std::cout << CLR_RED << "Intern could not create form " << form_name
		<< " - form name does not exist" << CLR_NON << '\n';
	return (nullptr);
}
