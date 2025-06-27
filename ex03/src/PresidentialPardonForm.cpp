/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:42:16 by akostian          #+#    #+#             */
/*   Updated: 2025/06/28 00:34:15 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", PresidentialPardonForm::kSignGrade, PresidentialPardonForm::kExecGrade, "Target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", PresidentialPardonForm::kSignGrade, PresidentialPardonForm::kExecGrade, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other)
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}


void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->GetSigned())
		throw AForm::FormNotSignedExeption();
	if (executor.GetGrade() > this->GetExecGrade())
		throw AForm::GradeTooLowException();

	if (COLORED)
		std::cout << CYN << this->GetTarget() << CRESET << " has been pardoned by Zaphod Beeblebrox" CRESET << "\n";
	else
		std::cout << this->GetTarget() << "has been pardoned by Zaphod Beeblebrox" << "\n";
}
