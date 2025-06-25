/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:27:10 by akostian          #+#    #+#             */
/*   Updated: 2025/06/25 14:31:48 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# define COLORED 1

// Regular Black text
# define BLK "\033[0;30m"
// Regular Red text
# define RED "\033[0;31m"
// Regular Green text
# define GRN "\033[0;32m"
// Regular Yellow text
# define YEL "\033[0;33m"
// Regular Blue text
# define BLU "\033[0;34m"
// Regular Magenta text
# define MAG "\033[0;35m"
// Regular Cyan text
# define CYN "\033[0;36m"
// Regular White text
# define WHT "\033[0;37m"

// Color reset
# define CRESET "\033[0m"

# include <iostream>
# include "Form.hpp"

class Form;

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

		void	signForm(Form &form);

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