/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:02:20 by cdutel            #+#    #+#             */
/*   Updated: 2025/01/23 18:49:06 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <stdexcept>

class	A;
class	B;
class	C;

class	Base
{
	public:
		virtual	~Base();
};


Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
