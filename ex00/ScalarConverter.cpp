/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:21:56 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/03 15:15:40 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const& substitue)
{
	(void)substitue;
	std::cout << "ScalarConver copie constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& substitue)
{
	if (this != &substitue)
	{

	}
	return (*this);
}

int	ScalarConverter::parse(std::string arg)
{
	int type = 0;
	size_t i = 0;

	if (arg == "nanf" || arg == "nan")
		type = SPECIALNAN;
	else if (arg.size() == 1 && (arg[0] < '0' || arg[0] > '9'))
		type = CHAR;
	else
	{
		while (i < arg.size())
		{
			if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '.' && arg[i] != 'f' && arg[i] != '-')
			{
				std::cout << "Input invalid" << std::endl;
				return (0);
			}
			if (arg[i] == '.' && (i == arg.size() - 1 || i == 0 || arg[i + 1] == 'f' || std::string::npos != arg.find('.', i + 1)))
			{
				std::cout << "Input invalid" << std::endl;
				return (0);
			}
			if (arg[i] == 'f' && (i != arg.size() - 1 || (arg[i - 1] < '0' || arg[i - 1] > '9')))
			{
				std::cout << "Input invalid" << std::endl;
				return (0);
			}
			if (arg[i] == '-' && i != 0)
			{
				std::cout << "Input invalid" << std::endl;
				return (0);
			}
			i++;
		}
		if (arg.find('f') != std::string::npos)
			type = FLOAT;
		if (arg.find('.') != std::string::npos && arg.find('f') == std::string::npos)
			type = DOUBLE;
		if (arg.find('f') == std::string::npos && arg.find('.') == std::string::npos)
			type = INT;
	}
	return (type);
}

int	ScalarConverter::intType(std::string arg)
{
	long Lnbr = atol(arg.c_str());
	if (Lnbr > 2147483647 || Lnbr < -2147483648)
	{
		std::cout << "Overflow" << std::endl;
		return (0);
	}
	int nbr = atoi(arg.c_str());
	if ((static_cast<char>(nbr) < 32 || static_cast<char>(nbr) > 126) && nbr <= 127)
		std::cout << "char : " << "Non displayable" << std::endl;
	else if (nbr > 127.0f)
		std::cout << "char : " << "Inpossible" << std::endl;
	else
		std::cout << "char : " << static_cast<char>(nbr) << std::endl;
	std::cout << "int : " << nbr << std::endl;
	std::cout << "float : " << std::fixed << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double : " << std::fixed << static_cast<double>(nbr) << std::endl;
	return (1);
}

int	ScalarConverter::floatType(std::string arg)
{
	if (atof(arg.c_str()) > FLT_MAX)
	{
		std::cout << "Overflow" << std::endl;
		return (0);
	}
	float nbr = atof(arg.c_str());
	if ((static_cast<char>(nbr) < 32 || static_cast<char>(nbr) > 126) && nbr <= 127.0f)
		std::cout << "char : " << "Non displayable" << std::endl;
	else if (nbr > 127.0f)
		std::cout << "char : " << "Inpossible" << std::endl;
	else
		std::cout << "char : " << static_cast<char>(nbr) << std::endl;
	if (nbr > 2147483647.0f || nbr < -2147483648.0f)
		std::cout << "int : " << "Impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(nbr) << std::endl;
	std::cout << "float : " << std::fixed << nbr << "f" << std::endl;
	std::cout << "double : " << std::fixed << static_cast<double>(nbr) << std::endl;
	return (1);
}

int	ScalarConverter::doubleType(std::string arg)
{
	if (atof(arg.c_str()) > DBL_MAX)
	{
		std::cout << "Overflow" << std::endl;
		return (0);
	}
	double nbr = atof(arg.c_str());
	if ((static_cast<char>(nbr) < 32 || static_cast<char>(nbr) > 126) && nbr <= 127.0)
		std::cout << "char : " << "Non displayable" << std::endl;
	else if (nbr > 127.0)
		std::cout << "char : " << "Inpossible" << std::endl;
	else
		std::cout << "char : " << static_cast<char>(nbr) << std::endl;
	if (nbr > 2147483647.0f || nbr < -2147483648.0f)
		std::cout << "int : " << "Impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(nbr) << std::endl;
	std::cout << "float : " << std::fixed << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double : " << std::fixed << nbr << std::endl;
	return (1);
}

int	ScalarConverter::charType(std::string arg)
{
	char nbr = arg[0];
	std::cout << "char : " << nbr << std::endl;
	std::cout << "int : " << static_cast<int>(nbr) << std::endl;
	std::cout << "float : " << std::fixed << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double : " << std::fixed << static_cast<double>(nbr) << std::endl;
	return (1);
}

int	ScalarConverter::nanType(std::string arg)
{
	(void)arg;
	std::cout << "char : Impossible" << std::endl;
	std::cout << "int : Impossible" << std::endl;
	std::cout << "float : nanf" << std::fixed << std::endl;
	std::cout << "double : nan" << std::fixed << std::endl;
	return (1);
}

void	ScalarConverter::convert(std::string arg)
{
	
	int type = parse(arg);

	int	(*tab_ptr_ft[5])(std::string) = {&floatType, &intType, &doubleType, &charType, &nanType};
	
	switch (type)
	{
		case 1:
			tab_ptr_ft[0](arg);
			break;
		case 2:
			tab_ptr_ft[1](arg);
			break;
		case 3:
			tab_ptr_ft[2](arg);
			break;
		case 4:
			tab_ptr_ft[3](arg);
			break;
		case 5:
			tab_ptr_ft[4](arg);
			break;
		default:
			break;
	}
}