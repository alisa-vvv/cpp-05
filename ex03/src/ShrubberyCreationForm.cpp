/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   ShrubberyCreationForm.cpp                               :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/07/31 18:52:11 by avaliull            #+#    #+#           */
/*   Updated: 2026/08/01 16:21:28 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

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
	this->confirmCanExecute(bureaucrat);
	std::ofstream	plantation(this->getName());
	int	tree_count = (this->getExecuteGrade() - bureaucrat.getGrade()) % 10;
	do {
		plantation << "          &&& &&  & &&\n\
      && &\\/&\\|& ()|/ @, &&\n\
      &\\/(/&/&||/& /_/)_&/_&\n\
   &() &\\/&|()|/&\\/ \'%\" & ()\n\
  &_\\_&&_\\ |& |&&/&__%_/_& &&\n\
&&   && & &| &| /& & % ()& /&&\n\
 ()&_---()&\\&\\|&&-&&--%---()~\n\
     &&     \\|||\n\
             |||\n\
             |||\n\
             |||\n\
       , -=-~  .-^- _\n\
ejm97         `";
		tree_count--;
	} while (tree_count > 0);
}

AForm*	ShrubberyCreationForm::newAForm(const std::string& target) const {
	return (new ShrubberyCreationForm(target));
}
