/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:14:01 by akostian          #+#    #+#             */
/*   Updated: 2025/06/24 23:58:07 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : 
	name_("Default Form"),
	signed_(false),
	sign_grade_(Bureaucrat::maxGrade),
	exec_grade_(Bureaucrat::maxGrade)
{
}

Form::Form(std::string name, int sign_grade, int exec_grade) : 
	name_(name),
	signed_(false)
{
	if ((sign_grade > Bureaucrat::maxGrade) || (exec_grade > Bureaucrat::maxGrade))
		throw Form::GradeTooHighException();
	if ((sign_grade < Bureaucrat::minGrade) || (exec_grade < Bureaucrat::minGrade))
		throw Form::GradeTooLowException();
	this->sign_grade_ = sign_grade;
	this->exec_grade_ = exec_grade;
}

Form::Form(const Form& other) :
	name_(other.name_),
	signed_(other.signed_),
	sign_grade_(other.sign_grade_),
	exec_grade_(other.exec_grade_)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other) {
		this->signed_ = other.signed_;
		this->sign_grade_ = other.sign_grade_;
		this->exec_grade_ = other.exec_grade_;
	}
	return *this;
}

Form::~Form()
{
}


void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.GetGrade() > this->sign_grade_)
		throw Form::GradeTooLowException();
	this->signed_ = true;
}


std::ostream&	operator<<(std::ostream& os, const Form& form)
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


std::string Form::GetName() const
{
	return this->name_;
}

bool Form::GetSigned() const
{
	return this->signed_;
}

int Form::GetSignGrade() const
{
	return this->sign_grade_;
}

int Form::GetExecGrade() const
{
	return this->exec_grade_;
}
