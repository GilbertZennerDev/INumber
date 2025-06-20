/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INumber_Contructors.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:47:14 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/20 15:48:05 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INumber.hpp"

INumber::INumber()
{
    sign = true;
    comma_pos = -1;
}

INumber::INumber(std::string nbr)
{
    size_t i;
    
    comma_pos = -1;
    sign = nbr[0] == '-';
    i = 1;
    while(i < nbr.size())
    {
        if (nbr[i] == '.')
        {
            comma_pos = i;
        }
        else
        {
            digits.push_back(nbr[i]);
        }
        ++i;
    }
}

INumber::INumber(INumber const& copy)
{
    this->digits = copy.digits;
}

INumber& INumber::operator=(INumber const& copy)
{
    if (this != &copy)
    {
        this->digits = copy.digits;
    }
    return *this;
}

INumber::~INumber()
{
    digits.clear();
}

