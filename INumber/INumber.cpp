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
    try
    {
        if (_billions[index] != NULL && _billions[index]->getValue() != 0)
        {
            throw ("Billion already set.\n");
        }
        _billions[index] = new Billion(value, index);
    }
    catch (char const *msg)
    {
        std::cout << msg;
    }
    
}

void INumber::overwriteBillion(unsigned int value, int index)
{
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

void INumber::addValue(unsigned int addvalue, int index)
{
    // the purpose is to add a new value to the current billion
    unsigned int overflow;
    unsigned int sum;

    // ERROR CHECKING
    
    if (addvalue == 0)
        return ;
    if (getBillion(index) == NULL)
        addBillion(0, index);

    overflow = 0;
    sum = getValue(index) + addvalue;
    if (sum >= BILLION)
    {
        overflow = sum / (BILLION);
        sum %= (HUNDREDMILLIONS);
    }
    setValue(sum, index);
    if (overflow)
    {
        addValue(overflow, index + 1);
    }
}

Billion* INumber::getBillion(int index)
{
    return (_billions[index]);
}

void INumber::printBillions()
{
    if (_sign)
    {
        std::cout << "positive\n";
    }
    else
    {
        std::cout << "negative\n";
    }
    std::map<int, Billion*>::iterator it;
    for(it = _billions.begin(); it != _billions.end(); it++)
    {
        if (it->second->getValue() != 0)
        {
            std::cout << "index: " << it->first << " with value: " << it->second->getValue() << "\n";
        }
    }
}

void INumber::printBillion(int index)
{
    Billion *b = _billions[index];
    if (b)
        std::cout << "index: " << index << " with value: " << getValue(index) << "\n";
    else
        printMsg("out of range", "bad billion index");
}

void INumber::printMsg(std::string prefix, std::string msg)
{
    std::cout << "[debug: " << prefix << " ]: ." << msg << ".\n";
}

void INumber::printBillionsSize()
{
    std::cout << "Size of Billions: " << _billions.size() << "\n";
}