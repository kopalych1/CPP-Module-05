/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:31:39 by akostian          #+#    #+#             */
/*   Updated: 2025/06/16 14:23:20 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void	printException(const std::exception& e)
{
	if (COLORED)
		std::cout << YEL "Exception triggered" CRESET ": " << e.what() << '\n';
	else
		std::cout << "Exception triggered: " << e.what() << '\n';
}

int	main()
{
	{
		std::cout << "---- Test 1 ----" << "\n";
		Bureaucrat	bob = Bureaucrat("bob", 34);
		std::cout << bob << "\n";

		Bureaucrat	a(bob);
		Bureaucrat	b("b", 123);

		std::cout << b << "\n";
		b = a;

		std::cout << a << "\n";
		std::cout << b << "\n";

		try
		{
			Bureaucrat("0_0", 256);
		}
		catch(const std::exception& e)
		{
			printException(e);
		}
	}
	{
		std::cout << "---- Test 2 ----" << "\n";
		Bureaucrat	carl = Bureaucrat("Carl", 5);

		for (int i = 0; i < 10; i++)
		{
			std::cout << "current grade: " << carl.GetGrade() << "\n";
			try
			{
				carl.incrementGrade();
			}
			catch(const std::exception& e)
			{
				printException(e);
			}
		}
		carl.decrementGrade(145);
		for (int i = 0; i < 10; i++)
		{
			std::cout << "current grade: " << carl.GetGrade() << "\n";
			try
			{
				carl.decrementGrade();
			}
			catch(const std::exception& e)
			{
				printException(e);
			}
		}
	}
}
