/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INumber_operations.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:49:12 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/20 15:54:42 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INumber.hpp"

void INumber::addINumber(INumber& copy)
{
    /*
    need to implement check for billion* is NULL
    */
    unsigned int value;
    std::map<int, Billion*>::iterator it;
    for(it = _billions.begin(); it != _billions.end(); it++)
    {
        value = getValue(it->first) + copy.getValue(it->first);
        _billions[it->first]->setValue(value);
        std::cout << "[debug adding]:" << _billions[it->first]->getValue() << "\n";
    }
}