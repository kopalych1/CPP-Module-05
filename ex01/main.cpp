/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:44:06 by akostian          #+#    #+#             */
/*   Updated: 2025/06/25 14:32:27 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

static void printError()
{
	if (COLORED)
		std::cout << RED "Error" CRESET << "\n";
	else
		std::cout << "Error" << "\n";
}

static void	printTestN(void)
{
	static short	n = 0;

	std::cout << "\n" << ">========= Test " << n++ << " =========<" << "\n" << "\n";
}

int main()
{
	{
		printTestN();

		std::cout << "Incorrect form constructors:" << "\n";

		try { Form("Form", 255, 22); return (printError(), 1); }
		catch (const std::exception& e) { std::cerr << e.what() << '\n'; }
		try { Form("Form", 255, 255); return (printError(), 1); }
		catch (const std::exception& e) { std::cerr << e.what() << '\n'; }
		try { Form("Form", 22, 255); return (printError(), 1); }
		catch (const std::exception& e) { std::cerr << e.what() << '\n'; }
		try { Form("Form", -42, 22); return (printError(), 1); }
		catch (const std::exception& e) { std::cerr << e.what() << '\n'; }
		try { Form("Form", -42, -42); return (printError(), 1); }
		catch (const std::exception& e) { std::cerr << e.what() << '\n'; }
		try { Form("Form", 22, -42); return (printError(), 1); }
		catch (const std::exception& e) { std::cerr << e.what() << '\n'; }
	}
	{
		printTestN();

		std::cout << "beSigned():" << "\n";

		Form		form("Form", 5, 33);
		Bureaucrat	bc("BC", 3);

		form.beSigned(bc);

		try { Form("Form", 1, 42).beSigned(Bureaucrat("BC", 2)); return (printError(), 1); }
		catch (const std::exception& e) { std::cerr << e.what() << '\n'; }
		try { Form("Form", 4, 42).beSigned(Bureaucrat("BC", 87)); return (printError(), 1); }
		catch (const std::exception& e) { std::cerr << e.what() << '\n'; }

		Form("Form", 42, 42).beSigned(Bureaucrat("BC", 1));
		Form("Form", 42, 42).beSigned(Bureaucrat("BC", 42));
	}
	{
		printTestN();

		std::cout << "SignForm():" << "\n";
		
		Form	form("Form1", 2, 42);
		Bureaucrat("Educated Bob", 1).signForm(form);
		try
		{
			Form	form("Form1", 2, 42);
			Bureaucrat("Stupid Bob", 4).signForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
