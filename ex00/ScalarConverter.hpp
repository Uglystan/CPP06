/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:16:56 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/03 15:14:15 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cfloat>
#define FLOAT 1
#define INT 2
#define DOUBLE 3
#define CHAR 4
#define SPECIALNAN 5

class	ScalarConverter
{
	public :
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& substitue);
		~ScalarConverter(void);
		ScalarConverter&	operator=(ScalarConverter const& substitue);
		static void	convert(std::string arg);
		static	int	intType(std::string arg);
		static	int	charType(std::string arg);
		static	int	floatType(std::string arg);
		static	int	doubleType(std::string arg);
		static	int	nanType(std::string arg);
		static	int	parse(std::string arg);
};

#endif