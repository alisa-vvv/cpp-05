/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   Intern.hpp                                              :+:    :+:       */
/*                                                          +:+               */
/*   By: avaliull <avaliull@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/08/01 19:08:25 by avaliull            #+#    #+#           */
/*   Updated: 2026/08/01 19:12:41 by avaliull            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <string>

#define FORM_TYPES_COUNT 3

class Intern {
public:
/*	Canonical form stuff	*/
	Intern();
	Intern(const Intern& other) = delete;
	Intern&	operator=(const Intern& other) = delete;
	~Intern();
/**/
	AForm*	makeForm(
		const std::string& form_name,
		const std::string& form_target
	);
private:
	static const std::string		_form_names[FORM_TYPES_COUNT];
	static const AForm::newFormPtr	_new_form_ptrs[FORM_TYPES_COUNT];
};
