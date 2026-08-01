/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   RobotomyRequestForm.cpp                                 :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/08/01 15:35:57 by avaliull            #+#    #+#           */
/*   Updated: 2026/08/01 16:25:38 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <random>
#include <chrono>
#include <thread>

/*	Canonical form stuff	*/
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:	AForm(target + "_robotomy", 72, 45),
		_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	:	AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade())
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}
/**/

void	RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {
	confirmCanExecute(bureaucrat);

	std::random_device	random_seed;
	std::mt19937		generate(random_seed());
	std::uniform_int_distribution<>	delay_distr(500, 1500);
	std::uniform_int_distribution<>	count_distr(1, 5);
	std::uniform_int_distribution<>	fifty_fifty(0, 1);

	int	drill_count = count_distr(generate);
	std::cout << "starting robotomy...\n";
	for (int i = 0; i < drill_count; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(delay_distr(generate)));
		std::cout << "drrrrrrrr...\n";
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(delay_distr(generate)));
	std::cout << _target + ": "
		+ (fifty_fifty(generate) ? "robotomized successfully" : "robotomy failed")
		+ '\n';
}
