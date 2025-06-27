/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:42:18 by akostian          #+#    #+#             */
/*   Updated: 2025/06/28 00:34:02 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", ShrubberyCreationForm::kSignGrade, ShrubberyCreationForm::kExecGrade, "Target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", ShrubberyCreationForm::kSignGrade, ShrubberyCreationForm::kExecGrade, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->GetSigned())
		throw AForm::FormNotSignedExeption();
	if (executor.GetGrade() > this->GetExecGrade())
		throw AForm::GradeTooLowException();

	std::ofstream	outfile((this->GetTarget() + "_shrubbery").c_str());
	if (!outfile)
		throw OpenFileException();

	outfile <<
		"       /\\\n"
		"      /**\\\n"
		"     /****\\\n"
		"    /******\\\n"
		"   /********\\\n"
		"  /**********\\\n"
		" /************\\\n"
		"/**************\\\n"
		"       ||\n"
		"       ||\n"
		"\n"
	;

	outfile <<
		"       &&& &&  & &&\n"
		"   && &\\/&\\|& ()|/ @, &&\n"
		"   &\\/(/&/&||/& /_/)_&/_&\n"
		"&() &\\/&|()|/&\\/ '%\" & ()\n"
		"&_\\/&_/&&&|&& |&&/&__%_/_& &&\n"
		"&&   && & &| &| /& & % ()& /&&\n"
		"   ()&_---()&\\&\\|&&-&&--%---()~\n"
		"       &&     \\|||\n"
		"               |||\n"
		"               |||\n"
		"               |||\n"
		"         , -=-~  .-^- _\n"
	;
	outfile.close();
}
