/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:05:11 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/22 13:13:30 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter(void)
{
}


/*Operator overload*/
ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &inst)
{
	if (this != &inst)
	{
	}
	return (*this);
}


/*Functions*/
static int	check_validity(std::string to_convert)
{
	int	dot = 0;
	int	f = 0;
	int	i = 0;

	while (to_convert[i] && (to_convert[i] == '+' || to_convert[i] == '-'))
		i++;
	if (i > 1 || !(to_convert[i] >= '0' && to_convert[i] <= '9'))
		return (1);
	while (to_convert[i])
	{
		if (to_convert[i] == '+' || to_convert[i] == '-')
			return (1);
		if (to_convert[i] == '.')
		{
			dot++;
			if (dot > 1 || to_convert[i + 1] == '\0')
				return (1);
		}
		if (to_convert[i] == 'f')
		{
			f++;
			if (to_convert[i - 1] == '.' || f > 1 || to_convert[i + 1] != '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

static std::string	find_type(std::string const to_convert)
{
	if (to_convert[0] == '\0')
		return ("IMPOSSIBLE");
	if (to_convert.compare("+inff") == 0 || to_convert.compare("+inf") == 0
	|| to_convert.compare("-inff") == 0 || to_convert.compare("-inf") == 0
	|| to_convert.compare("nanf") == 0)
		return ("NAN_OR_INF");
	else if (to_convert.length() == 1 && !isdigit(to_convert[0]))
		return ("CHAR");
	else if (to_convert.find_first_not_of("+-0123456789") > to_convert.length() && check_validity(to_convert) == 0)
		return ("INT");
	else if (to_convert.find_first_not_of("+-0123456789.") > to_convert.length() && check_validity(to_convert) == 0)
		return ("DOUBLE");
	else if (to_convert.find_first_not_of("+-0123456789.f") > to_convert.length() && check_validity(to_convert) == 0)
		return ("FLOAT");
	return ("IMPOSSIBLE");
}

/*Public member functions*/
void	ScalarConverter::convert(std::string const to_convert)
{
	std::string	type_of_string;

	type_of_string = find_type(to_convert);
	std::cout << type_of_string << std::endl;
}
