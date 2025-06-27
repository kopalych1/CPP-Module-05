/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:42:05 by akostian          #+#    #+#             */
/*   Updated: 2025/06/28 00:02:50 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "colors.h"
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	name_;
		bool				signed_;
		const int			sign_grade_;
		const int			exec_grade_;

		const std::string	target_;
	
	public:
		AForm();
		AForm(std::string name, int sign_grade, int exec_grade, std::string target);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual	~AForm() = 0;

		void	beSigned(const Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;

		friend std::ostream&	operator<<(std::ostream& os, const AForm& form);

		std::string	GetName() const;
		bool		GetSigned() const;
		int			GetSignGrade() const;
		int			GetExecGrade() const;
		std::string	GetTarget() const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() {
					return COLORED ? BLU "Grade" CRESET " is " RED "too high" CRESET :
					"Grade is too high";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw(){
					return COLORED ? BLU "Grade" CRESET " is " RED "too low" CRESET :
					"Grade is too low";
				}
		};
		class FormNotSignedExeption : public std::exception {
			public:
				const char *what() const throw(){
					return COLORED ? "Form is " RED "not signed" CRESET :
					"Form is not signed";
				}
		};
};

#endif // AFORM_HPP