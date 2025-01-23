/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:13:18 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/23 18:49:36 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/AClass.hpp"
#include "../includes/BClass.hpp"
#include "../includes/CClass.hpp"

Base::~Base(void)
{
}


/*Non member functions*/
Base	*generate(void)
{
	Base	*base;
	srand (time(NULL));
	int	rand_num = rand() % 100 + 1;

	if (rand_num <= 33)
	{
		A	*a = new A;
		base = dynamic_cast<Base *>(a);
	}
	else if (rand_num > 33 && rand_num <= 66)
	{
		B	*b = new B;
		base = dynamic_cast<Base *>(b);
	}
	else
	{
		C	*c = new C;
		base = dynamic_cast<Base *>(c);
	}
	return (base);
}

void	identify(Base *p)
{
	Base	*test = NULL;

	test = dynamic_cast<A *>(p);
	if (test)
		std::cout << "A" << std::endl;
	test = dynamic_cast<B *>(p);
	if (test)
		std::cout << "B" << std::endl;
	test = dynamic_cast<C *>(p);
	if (test)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		Base	&test = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)test;
	}
	catch (...)
	{
	}
	try
	{
		Base	&test1 = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)test1;
	}
	catch (...)
	{
	}
	try
	{
		Base	&test2 = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)test2;
	}
	catch (...)
	{
	}
}
