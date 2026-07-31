/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   ShrubberyCreationForm.cpp                               :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/07/31 18:52:11 by avaliull            #+#    #+#           */
/*   Updated: 2026/07/31 19:05:07 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
/*	Canonical form stuff	*/
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:	AForm(target + "_shrubbery", 145, 137),
		_target(target)
{
}
/**/
//ShrubberyCreationForm(const ShrubberyCreationForm& other);
ShrubberyCreationForm::~ShrubberyCreationForm() {}
