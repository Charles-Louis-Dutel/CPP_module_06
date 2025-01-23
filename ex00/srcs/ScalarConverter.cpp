/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:05:11 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/23 14:49:11 by cdutel           ###   ########.fr       */
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

static void	printChar(char c, int impossible)
{
	if (impossible == 1)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	if ((c >= 0 && c < 32) || c == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (c >= 32 && c <= 126)
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

static void	printInt(int i, int impossible)
{
	if (impossible == 1)
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	std::cout << "int: " << i << std::endl;
}

static void	printFloat(float f, int prec)
{
	std::cout << "float: " << std::fixed << std::setprecision(prec) << f << "f" << std::endl;
}

static void	printDouble(double d, int prec)
{
	std::cout << "double: " << std::fixed <<  std::setprecision(prec) << d << std::endl;
}

static void	convertFromChar(std::string const to_convert)
{
	char	c;

	c = to_convert[0];
	printChar(c, 0);
	printInt(static_cast<int>(c), 0);
	printFloat(static_cast<float>(c), 1);
	printDouble(static_cast<double>(c), 1);
}

static void	convertFromInt(std::string const to_convert)
{
	std::istringstream	iss(to_convert);
	double				i;

	iss >> i;
	if (i >= 0 && i <= 127)
		printChar(static_cast<char>(i), 0);
	else
		printChar(static_cast<char>(i), 1);
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
		printInt(static_cast<int>(i), 1);
	else
		printInt(static_cast<int>(i), 0);
	printFloat(static_cast<float>(i), 1);
	printDouble(static_cast<double>(i), 1);
}

static void	convertFromFloat(std::string const to_convert)
{
	std::istringstream	iss(to_convert);
	int					prec;
	double				f;

	iss >> f;
	if (f >= 0 && f <= 127)
		printChar(static_cast<char>(f), 0);
	else
		printChar(static_cast<char>(f), 1);
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		printInt(static_cast<int>(f), 1);
	else
		printInt(static_cast<int>(f), 0);
	if (to_convert.find(".") < to_convert.length())
		prec = to_convert.length() - to_convert.find(".") - 2;
	else
		prec = 1;
	printFloat(static_cast<float>(f), prec);
	printDouble(static_cast<double>(f), prec);
}

static void	convertFromDouble(std::string const to_convert)
{
	std::istringstream	iss(to_convert);
	double				d;

	iss >> d;
	if (d >= 0 && d <= 127)
		printChar(static_cast<char>(d), 0);
	else
		printChar(static_cast<char>(d), 1);
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		printInt(static_cast<int>(d), 1);
	else
		printInt(static_cast<int>(d), 0);
	printFloat(static_cast<float>(d), to_convert.length() - to_convert.find(".") - 1);
	printDouble(static_cast<double>(d), to_convert.length() - to_convert.find(".") - 1);
}

static std::string	find_type(std::string const to_convert)
{
	if (to_convert[0] == '\0')
		return ("IMPOSSIBLE");
	if (to_convert.compare("+inff") == 0 || to_convert.compare("+inf") == 0
	|| to_convert.compare("-inff") == 0 || to_convert.compare("-inf") == 0
	|| to_convert.compare("nanf") == 0 || to_convert.compare("nan") == 0)
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

static void	handle_nan_iff(std::string to_convert)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (to_convert == "nan" || to_convert == "+inf" || to_convert == "-inf")
		std::cout << "float: " << to_convert << "f" << std::endl;
	else
		std::cout << "float: " << to_convert << std::endl;
	if (to_convert == "nanf" || to_convert == "+inff" || to_convert == "-inff")
		std::cout << "double: " << to_convert.erase(to_convert.length() - 1, to_convert.length())<< std::endl;
	else
		std::cout << "double: " << to_convert << std::endl;
}

/*Public member functions*/
void	ScalarConverter::convert(std::string const to_convert)
{
	std::string	type_of_string;
	std::string	type[5] = {"CHAR", "INT", "DOUBLE", "FLOAT", "NAN_OR_INF"};
	int			i;

	type_of_string = find_type(to_convert);
	std::cout << type_of_string << std::endl;

	for (i = 0; i < 5; i++)
	{
		if (type[i] == type_of_string)
			break;
	}
	switch (i)
	{
		case 0:
			convertFromChar(to_convert);
			break;
		case 1:
			convertFromInt(to_convert);
			break;
		case 2:
			convertFromDouble(to_convert);
			break;
		case 3:
			convertFromFloat(to_convert);
			break;
		case 4:
			handle_nan_iff(to_convert);
			break;
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
	}
}
