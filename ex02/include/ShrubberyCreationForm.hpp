/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:42:02 by akostian          #+#    #+#             */
/*   Updated: 2025/06/27 16:48:20 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
	public:

		static const int	kSignGrade = 145;
		static const int	kExecGrade = 137;

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void	execute(Bureaucrat const &executor) const;

		class OpenFileException : public std::exception {
			public:
				const char *what() const throw() {
					return "Unable to open the target file";
				}
		};
};

#endif // SHRUBBERYCREATIONFORM_HPP