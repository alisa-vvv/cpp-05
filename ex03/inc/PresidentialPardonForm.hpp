/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   PresidentialPardonForm.hpp                              :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/08/01 16:05:12 by avaliull            #+#    #+#           */
/*   Updated: 2026/08/01 16:06:21 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm() = delete;
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other) = delete;
	~PresidentialPardonForm();
	void	execute(const Bureaucrat& bureaucrat) const;
private:
	const std::string	_target;
};
