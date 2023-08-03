/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:27:19 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/03 16:05:53 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(Serializer const& substitue)
{
	(void)substitue;
	std::cout << "Serializer copie constructor called" << std::endl;
}

Serializer& Serializer::operator=(Serializer const& substitue)
{
	std::cout << "Serializer assignement operator called" << std::endl;
	if (this != &substitue)
	{

	}
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}