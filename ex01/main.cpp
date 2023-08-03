/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:24:39 by lgirault          #+#    #+#             */
/*   Updated: 2023/08/03 16:33:01 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data* ptr = new Data();
	std::cout << ptr << std::endl;
	uintptr_t s = Serializer::serialize(ptr);
	std::cout << s << std::endl;
	std::cout << Serializer::deserialize(s) << std::endl;
}