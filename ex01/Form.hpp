/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:12:28 by akostian          #+#    #+#             */
/*   Updated: 2025/06/24 15:20:05 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	name_;
		bool				signed_;
		int					sign_grade_;
		int					exec_grade_;
	
	public:
		Form();
		Form(std::string name, int sign_grade, int exec_grade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		void	beSigned(const Bureaucrat &bureaucrat);

		friend std::ostream&	operator<<(std::ostream& os, const Form& form);

		std::string	GetName() const;
		bool		GetSigned() const;
		int			GetSignGrade() const;
		int			GetExecGrade() const;

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
};

#endif // FORM_HPP