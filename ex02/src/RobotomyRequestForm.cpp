/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:42:17 by akostian          #+#    #+#             */
/*   Updated: 2025/06/28 00:34:12 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", RobotomyRequestForm::kSignGrade, RobotomyRequestForm::kExecGrade, "Target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", RobotomyRequestForm::kSignGrade, RobotomyRequestForm::kExecGrade, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}


static bool	fifty_fifty_gen(void)
{
	return ((std::rand() % 2) + 1) == 1;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->GetSigned())
		throw AForm::FormNotSignedExeption();
	if (executor.GetGrade() > this->GetExecGrade())
		throw AForm::GradeTooLowException();

	if (COLORED)
		std::cout << YEL "Makes some drilling noises..." CRESET << "\n";
	else
		std::cout << "Makes some drilling noises..." << "\n";

	if (fifty_fifty_gen())
	{
		if (COLORED)
			std::cout << CYN << this->GetTarget() << CRESET << " has been robotomized " GRN "successfully" CRESET << "\n";
		else
			std::cout << this->GetTarget() << " has been robotomized successfully" << "\n";
	}
	else
	{
		if (COLORED)
			std::cout << "the robotomy " RED "failed" CRESET << "\n";
		else
			std::cout << "the robotomy failed" << "\n";
	}
}
