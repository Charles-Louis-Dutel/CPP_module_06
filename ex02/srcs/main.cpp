/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:41:03 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/23 17:53:47 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Base.hpp"
#include "../includes/AClass.hpp"
#include "../includes/BClass.hpp"
#include "../includes/CClass.hpp"

int main(void)
{
	Base	*base_test;

	base_test = generate();
	identify(base_test);
	identify(*base_test);
	delete base_test;

	return (0);
}

