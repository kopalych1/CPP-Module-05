/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:38:54 by akostian          #+#    #+#             */
/*   Updated: 2025/06/28 00:40:08 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

static void	printTestN(void)
{
	static short	n = 0;

	std::cout << "\n" << ">========= Test " << n++ << " =========<" << "\n" << "\n";
}



int main()
{
	/* {

		// Random number generator tests:
	
		bool	fifty_fifty_gen(void)
		{
			return ((std::rand() % 2) + 1) == 1;
		}

		printTestN();

		const int	N = 10 * 1000 * 1000;

		int	wins = 0;
		for (size_t i = 0; i < N; i++)
		{
			if (fifty_fifty_gen())
				wins++;
		}
		std::cout << wins << "\n";
		std::cout << N - wins << "\n";
		std::cout << (double)wins / N * 100 << " %" << "\n";
	} */
	{
		printTestN();

		ShrubberyCreationForm	form;

		std::cout << "Not signed: " << "\n";
		Bureaucrat("_", 1).executeForm(form);
	}
	{
		printTestN();

		ShrubberyCreationForm	form("forms/garden");
		Bureaucrat("_", 1).signForm(form);

		std::cout << "Grade too low:" << "\n";
		Bureaucrat("_", 150).executeForm(form);

		Bureaucrat("_", 1).executeForm(form);
	}
	{
		printTestN();

		RobotomyRequestForm	form("me");
		Bureaucrat("_", 1).signForm(form);

		for (short i = 0; i < 4; i++)
			Bureaucrat("123", 33).executeForm(form);

		Bureaucrat("Bad doctor", 130).executeForm(form);
	}
	{
		printTestN();

		PresidentialPardonForm	form1("knight");
		PresidentialPardonForm	form2("me");

		Bureaucrat("_", 26).signForm(form1);
		Bureaucrat("_", 1).signForm(form1);
		Bureaucrat("_", 1).signForm(form2);

		Bureaucrat("Queen", 1).executeForm(form1);
		Bureaucrat("peasant", 130).executeForm(form2);
	}
}
