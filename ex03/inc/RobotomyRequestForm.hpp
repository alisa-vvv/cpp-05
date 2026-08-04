/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   RobotomyRequestForm.hpp                                 :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/08/01 15:38:22 by avaliull            #+#    #+#           */
/*   Updated: 2026/08/01 15:38:39 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm() = delete;
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other) = delete;
	~RobotomyRequestForm();
	void	execute(const Bureaucrat& bureaucrat) const override;
	AForm*	newAForm(const std::string& target) const override;
private:
	const std::string	_target;
};
