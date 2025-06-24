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

INumber::INumber(): _sign(true){}

INumber::INumber(INumber const& copy)
{
    this->_billions = copy._billions;
}

INumber& INumber::operator=(INumber const& copy)
{
    if (this != &copy)
    {
        //delete this->billions;
        //this->billions = new 
        this->_billions = copy._billions;
    }
    return *this;
}

INumber::~INumber()
{
    std::map<int, Billion*>::iterator it;
    for(it = _billions.begin(); it != _billions.end(); it++)
    {
        //delete (it->second);
    }
    _billions.clear();
}

