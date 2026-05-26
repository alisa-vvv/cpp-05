/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Form.hpp                                                :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/05/26 15:37:44 by avaliull            #+#    #+#           */
/*   Updated: 2026/05/26 15:42:18 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"

#ifndef HIGHEST_GRADE
# define	HIGHEST_GRADE 1
#endif
#ifndef LOWEST_GRADE
# define	LOWEST_GRADE 150
#endif

class	Form {
public:
	Form(std::string name, int sign_grade, int exec_grade);
	Form(const Form& other);
	Form&	operator=(const Form& other);
	~Form();

	GradeException	GradeTooLowException;
	GradeException	GradeTooHighException;

protected:
private:
	const std::string	_name = "unnamed_form";
	bool				_is_signed = "false";
	const int			_sign_grade = LOWEST_GRADE;
	const int			_exec_grade = LOWEST_GRADE;
};
