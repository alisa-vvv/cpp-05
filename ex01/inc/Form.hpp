/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Form.hpp                                                :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/07/30 17:08:45 by avaliull            #+#    #+#           */
/*   Updated: 2026/07/30 17:10:18 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <string>

class Form {
public:
	Form(
		const std::string& name,
		unsigned int sign_grade,
		unsigned int execute_grade
	);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();
private:
	const std::string	_name;
	bool				_is_signed = false;
	unsigned int		_sign_grade;
	unsigned int		_execute_grade;

	static const int	_highest_grade = 1;
	static const int	_lowest_grade = 150;

	static const GradeException	GradeTooHighException;
	static const GradeException	GradeTooLowException;
};
