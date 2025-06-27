/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Billion.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:44:09 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/27 16:19:43 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Billion.hpp"

Billion::Billion(): _index(0), _value(0){}
Billion::Billion(unsigned int value, int index): _index(index), _value(value){}
Billion::Billion(Billion const& copy): _index(copy._index), _value(copy._value){}
Billion& Billion::operator=(Billion const& copy){
    if(this != &copy)
    {
        _index = copy._index;
        _value = copy._value;
    }
    return (*this);
}
Billion::~Billion()
{
}

int Billion::getIndex(){
    return (_index);
}

unsigned int Billion::getValue()
{
    return (_value);
}

void Billion::setValue(unsigned int value)
{
    _value = value;
}