/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   ShrubberyCreationForm.hpp                               :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/07/31 18:40:57 by avaliull            #+#    #+#           */
/*   Updated: 2026/07/31 19:13:11 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm() = delete;
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other) = delete;
	~ShrubberyCreationForm();
	void	execute(const Bureaucrat& bureaucrat) const override;
	AForm*	newAForm(const std::string& target) const override;
private:
	const std::string	_target;
};
