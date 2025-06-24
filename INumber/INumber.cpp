/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INumber.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:19:20 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/20 15:55:13 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INumber.hpp"
#include <exception>

void INumber::addBillion(unsigned int value, int index)
{
    if (_billions[index] != NULL)
    {
        throw std::exception();
        return ;
    }
    _billions[index] = new Billion(value, index);
}

unsigned int INumber::getValue(int index)
{
    return (_billions[index]->getValue());
}

void INumber::setValue(unsigned int newvalue, int index)
{
    _billions[index]->setValue(newvalue);
}