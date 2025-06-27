/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:38:54 by akostian          #+#    #+#             */
/*   Updated: 2025/06/27 17:34:53 by akostian         ###   ########.fr       */
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

		Bureaucrat("IVAN", 54).executeForm(ShrubberyCreationForm("forms/form"));

		std::cout << "Not enough grade:" << "\n";
		Bureaucrat("_", 150).executeForm(ShrubberyCreationForm("1"));
	}
	{
		printTestN();

		for (short i = 0; i < 4; i++)
			Bureaucrat("123", 33).executeForm(RobotomyRequestForm("me"));

		Bureaucrat("Bad doctor", 130).executeForm(RobotomyRequestForm("me"));
	}
	{
		printTestN();

		Bureaucrat("Queen", 1).executeForm(PresidentialPardonForm("knight"));

		Bureaucrat("peasant", 130).executeForm(PresidentialPardonForm("me"));
	}
}
