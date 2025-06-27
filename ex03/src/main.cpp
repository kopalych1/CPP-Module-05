/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:38:54 by akostian          #+#    #+#             */
/*   Updated: 2025/06/28 00:49:47 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

static void	printTestN(void)
{
	static short	n = 0;

	std::cout << "\n" << ">========= Test " << n++ << " =========<" << "\n" << "\n";
}

int main()
{
	{
		printTestN();
		Intern		intern;

		AForm* form1 = intern.makeForm("shrubbery creation", "forms/Garden");
		AForm* form2 = intern.makeForm("robotomy request", "Bender");
		AForm* form3 = intern.makeForm("presidential pardon", "Alice");
		AForm* form4 = intern.makeForm("useless form", "Nobody");

		std::cout << form4 << "\n";

		Bureaucrat("Bob", 1).executeForm(*form1);
		Bureaucrat("Bob", 1).executeForm(*form2);
		Bureaucrat("Bob", 1).executeForm(*form3);
		
		Bureaucrat("Bob", 1).signForm(*form1);
		Bureaucrat("Bob", 1).signForm(*form2);
		Bureaucrat("Bob", 1).signForm(*form3);

		Bureaucrat("Bob", 1).executeForm(*form1);
		Bureaucrat("Bob", 1).executeForm(*form2);
		Bureaucrat("Bob", 1).executeForm(*form3);

		delete form1;
		delete form2;
		delete form3;
		delete form4;
	}
}
