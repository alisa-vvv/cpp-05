/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Bureaucrat.hpp                                          :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/03/27 19:19:12 by avaliull            #+#    #+#           */
/*   Updated: 2026/07/31 19:51:37 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

# ifndef CLR_NON
#  define	CLR_NON "\033[0m"
#  define	CLR_YEL "\033[93m"
#  define	CLR_CYA "\033[96m"
#  define	CLR_RED "\033[31m"
#  define	CLR_GRN "\033[92m"
#  define	CLR_MAG "\033[95m"
# endif // CLR_NON and other CLR defines

class AForm;

class	BureaucratException {
public:
	BureaucratException(const std::string& msg);
	const char*	what() const noexcept;
private:
	std::string	_msg;
};

class	Bureaucrat {
public:
/*	Canonical form stuff	*/
	Bureaucrat() = delete;
	Bureaucrat(const std::string& name, unsigned int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat&	operator=(const Bureaucrat& other);
	~Bureaucrat();
/**/
/*	Setters and getters	*/
	const std::string&	getName() const;
	const unsigned int&	getGrade() const;
/**/
/*	Changing grade	*/
	void	incrementGrade();
	void	decrementGrade();
/**/
	static const BureaucratException	GradeTooHighException;
	static const BureaucratException	GradeTooLowException;

	void	signForm(AForm& form) const;
	void	executeForm(AForm const & form) const;

private:
	const std::string	_name;
	unsigned int		_grade;
	static const int	_highest_grade = 1;
	static const int	_lowest_grade = 150;
};

std::ostream&	operator<<(
	std::ostream& os,
	const Bureaucrat& bureaucrat
);
