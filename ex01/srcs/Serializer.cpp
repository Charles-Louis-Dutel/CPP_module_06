/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:34:54 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/23 15:42:36 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer(void)
{
}

Serializer::Serializer(Serializer const &copy)
{
	*this = copy;
}

Serializer::~Serializer(void)
{
}


/*Operator overload*/
Serializer	&Serializer::operator=(Serializer const &inst)
{
	if (this != &inst)
	{
	}
	return (*this);
}


/*Public member functions*/
uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	p = reinterpret_cast<uintptr_t>(ptr);

	return (p);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*ptr = reinterpret_cast<Data *>(raw);

	return (ptr);
}
