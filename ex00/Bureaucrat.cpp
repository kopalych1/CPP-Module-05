/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:26:41 by akostian          #+#    #+#             */
/*   Updated: 2025/06/16 14:14:05 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Default Bureaucrat"), grade_(this->maxGrade)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name)
{
	if (grade > this->maxGrade)
		throw Bureaucrat::GradeTooHighException();
	if (grade < this->minGrade)
		throw Bureaucrat::GradeTooLowException();
	this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_), grade_(other.grade_)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other) {
		this->grade_ = other.grade_;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

void	Bureaucrat::incrementGrade(unsigned int value)
{
	if (grade_ - value < this->minGrade)
		throw Bureaucrat::GradeTooHighException();
	grade_ -= value;
}

void	Bureaucrat::incrementGrade(void)
{
	this->incrementGrade(1);
}

void	Bureaucrat::decrementGrade(unsigned int value)
{
	if (grade_ + value > this->maxGrade)
		throw Bureaucrat::GradeTooLowException();
	grade_ += value;
}

void	Bureaucrat::decrementGrade(void)
{
	this->decrementGrade(1);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	if (COLORED)
		os << GRN << bureaucrat.GetName() << CRESET << ", bureaucrat grade " << BLU << bureaucrat.GetGrade() << CRESET;
	else
		os << bureaucrat.GetName() << ", bureaucrat grade " << bureaucrat.GetGrade();
	return os;
}

std::string	Bureaucrat::GetName() const
{
	return this->name_;
}

int	Bureaucrat::GetGrade() const
{
	return this->grade_;
}
