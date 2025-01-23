/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:41:03 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/23 15:55:42 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Serializer.hpp"

int main(void)
{
	Data		*p = new Data;
	Data		*data_ptr;
	uintptr_t	uint_ptr;

	p->data_test = "Bonjour ceci est un test";
	p->int_test = 15;
	std::cout << p->data_test << std::endl;
	std::cout << p->int_test << std::endl;

	uint_ptr = Serializer::serialize(p);
	data_ptr = Serializer::deserialize(uint_ptr);

	std::cout << data_ptr->data_test << std::endl;
	std::cout << data_ptr->int_test << std::endl;

	delete p;
	return (0);
}

