/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Bureaucrat.hpp                                          :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/03/27 19:19:12 by avaliull            #+#    #+#           */
/*   Updated: 2026/05/05 18:32:40 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP_
# define BUREAUCRAT_HPP_

# ifndef CLR_NON
#  define	CLR_NON "\033[0m"
#  define	CLR_YEL "\033[93m"
#  define	CLR_CYA "\033[96m"
#  define	CLR_RED "\033[31m"
#  define	CLR_GRN "\033[92m"
#  define	CLR_MAG "\033[95m"
# endif // CLR_NON and other CLR defines

#include <string>

#ifndef HIGHEST_GRADE
# define	HIGHEST_GRADE 1
#endif
#ifndef LOWEST_GRADE
# define	LOWEST_GRADE 150
#endif

class	GradeException : public std::exception {
public:
	GradeException(int grade_limit);
	GradeException(const GradeException& other);
	GradeException&	operator=(const GradeException& other);
	~GradeException();

	const char*	what() const noexcept override;
protected:
private:
	int	_grade_limit;
};

class	Bureaucrat {
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat&	operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string&	getName() const;
	int	getGrade() const;
	void	incrementGrade();
	void	decrementGrade();

	GradeException	GradeTooLowException;
	GradeException	GradeTooHighException;
protected:
private:
	const std::string	_name = "default_name";
	int					_grade = LOWEST_GRADE;

};

std::ostream& operator<<(
	std::ostream& stream,
	const Bureaucrat& bureaucrat
);

#endif //BUREAUCRAT_HPP_
