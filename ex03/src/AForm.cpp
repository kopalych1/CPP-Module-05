/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:14:01 by akostian          #+#    #+#             */
/*   Updated: 2025/06/27 16:41:55 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm() :
	name_("Default Form"),
	signed_(false),
	sign_grade_(0),
	exec_grade_(0),
	target_("Default-Target")
{
}

AForm::AForm(std::string name, int sign_grade, int exec_grade, std::string target) :
	name_(name),
	signed_(false),
	sign_grade_(sign_grade),
	exec_grade_(exec_grade),
	target_(target)
{
	if ((sign_grade > Bureaucrat::maxGrade) || (exec_grade > Bureaucrat::maxGrade))
		throw AForm::GradeTooHighException();
	if ((sign_grade < Bureaucrat::minGrade) || (exec_grade < Bureaucrat::minGrade))
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) :
	name_(other.name_),
	signed_(other.signed_),
	sign_grade_(other.sign_grade_),
	exec_grade_(other.exec_grade_),
	target_(other.target_)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other) {
		this->signed_ = other.signed_;
	}
	return *this;
}

AForm::~AForm()
{
}


void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.GetGrade() > this->sign_grade_)
		throw AForm::GradeTooLowException();
	this->signed_ = true;
}


std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	if (COLORED)
		os << "Form: " << GRN << form.GetName() << CRESET
			<< "\tSign grade: " << BLU << form.GetSignGrade() << CRESET
			<< "\tExec grade: " << BLU << form.GetSignGrade() << CRESET
			<< ",\t" << (form.signed_ ? GRN "Signed" CRESET : YEL "Not Signed" CRESET);
	else
		os << "Form: " << form.GetName()
			<< "\tSign grade: " << form.GetSignGrade()
			<< "\tExec grade: " << form.GetSignGrade()
			<< ",\t" << (form.signed_ ? "Signed" : "Not Signed");
	return os;
}


std::string AForm::GetName() const
{
	return this->name_;
}

bool AForm::GetSigned() const
{
	return this->signed_;
}

int AForm::GetSignGrade() const
{
	return this->sign_grade_;
}

int AForm::GetExecGrade() const
{
	return this->exec_grade_;
}

std::string	AForm::GetTarget() const
{
	return this->target_;
}
