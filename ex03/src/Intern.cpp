/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:40:44 by akostian          #+#    #+#             */
/*   Updated: 2025/06/28 00:50:57 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other) {
		(void)other;
	}
	return *this;
}

Intern::~Intern()
{
}

static AForm	*makeShrubberyCreationForm(const std::string &target) { return new ShrubberyCreationForm(target); }
static AForm	*makeRobotomyRequestForm(const std::string &target) { return new RobotomyRequestForm(target); }
static AForm	*makePresidentialPardonForm(const std::string &target) { return new PresidentialPardonForm(target); }

struct FormPair {
	std::string	name;
	AForm		*(*create)(const std::string&);
};

static const FormPair formTypes[] = {
	{"shrubbery creation", makeShrubberyCreationForm},
	{"robotomy request", makeRobotomyRequestForm},
	{"presidential pardon", makePresidentialPardonForm}
};

AForm	*Intern::makeForm(std::string name, std::string target) const
{
	for (size_t  i = 0; i < sizeof(formTypes) / sizeof(FormPair); i++)
	{
		if (formTypes[i].name != name)
			continue;

		if (COLORED)
			std::cout << "Intern creates " << CYN << formTypes[i].name << CRESET << "\n";
		else
			std::cout << "Intern creates " << formTypes[i].name << "\n";
		return formTypes[i].create(target);
	}

	if (COLORED)
		std::cout << "Form name " << RED << name << CRESET << " does not exist" << "\n";
	else
		std::cout << "Form name " << name << " does not exist" << "\n";
	return NULL;
}
