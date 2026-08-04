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

const AForm::AForm_method_ptr	Intern::_constr_ptrs[FORM_TYPES_COUNT] {
	(AForm::AForm_method_ptr) &ShrubberyCreationForm::newAForm,
	(AForm::AForm_method_ptr) &RobotomyRequestForm::newAForm,
	(AForm::AForm_method_ptr) &PresidentialPardonForm::newAForm,
};

/*	Canonical form stuff	*/
Intern::Intern() {
}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern&	Intern::operator=(const Intern& other) {
	if (this != &other)
		*this = other;
	return (*this);
}

Intern::~Intern() {
}
/**/

static AForm*	createNewForm(
	const std::string& form_name,
	const std::string& form_target
) {
	if (form_name == "ShrubberyCreationForm")
		return (new ShrubberyCreationForm(form_target));
	if (form_name == "RobotomyRequestForm")
		return (new RobotomyRequestForm(form_target));
	if (form_name == "PresidentialPardonForm")
		return (new PresidentialPardonForm(form_target));
	return (nullptr);
}

AForm*	Intern::makeForm(
	const std::string& form_name,
	const std::string& form_target
) {
	AForm*	new_form = createNewForm(form_name, form_target);
	if (new_form == nullptr) {
		std::cout << CLR_RED << "Intern could not create form " << form_name
			<< " - form name does not exist" << CLR_NON << '\n';
	}
	else
		std::cout << "Intern creates " << form_name << '\n';
	return (new_form);
}
