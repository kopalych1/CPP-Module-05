/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:27:10 by akostian          #+#    #+#             */
/*   Updated: 2025/06/26 14:49:10 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include "colors.h"

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	name_;
		int					grade_;

	public:
		static const int	minGrade = 1;
		static const int	maxGrade = 150;

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		void	incrementGrade(void);
		void	incrementGrade(unsigned int value);
		void	decrementGrade(void);
		void	decrementGrade(unsigned int value);

		void	signForm(AForm &form) const;
		void	executeForm(AForm const &form) const;

		friend std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

		std::string	GetName() const;
		int			GetGrade() const;

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

#endif // BUREAUCRAT_HPP