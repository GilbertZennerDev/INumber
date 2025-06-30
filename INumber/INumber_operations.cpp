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
#include <cmath>

INumber& INumber::operator+(INumber& copy)
{
    if (this != &copy)
    {
        unsigned int value;
        std::map<int, Billion*>::iterator it;
        for(it = _billions.begin(); it != _billions.end(); it++)
        {
            unsigned int overflow;

            Billion* b = copy.getBillion(it->first);
            if (!b)
            {
                value = getValue(it->first);
            }
            else
            {
                value = getValue(it->first) + copy.getValue(it->first);
            }
            if (value >= 1000*1000*1000)
            {
                value -= 1000*1000*1000;
                overflow = 1;
            }
            else
            {
                overflow = 0;
            }
            _billions[it->first]->setValue(value);
            if (overflow)
            {
                addValue(1, it->first + 1);
            }
                //_billions[it->first + 1]->setValue(_billions[it->first + 1]->getValue() + 1);
            if (value != 0)
            {
                std::cout << "[debug adding]:" << _billions[it->first]->getValue() << "\n";
            }
        }
    }
    return (*this);
}

INumber& INumber::operator-(INumber& copy)
{
    if (this != &copy)
    {
        unsigned int thisBillionValue;
        unsigned int otherBillionValue;

        std::map<int, Billion*>::iterator it;
        for(it = _billions.begin(); it != _billions.end(); it++)
        {
            otherBillionValue = copy._billions[it->first]->getValue();
            thisBillionValue = it->second->getValue();
            if (otherBillionValue > thisBillionValue)
            {
                otherBillionValue -= thisBillionValue;
                _billions[it->first + 1]->setValue(_billions[it->first + 1]->getValue() - 1);
                _billions[it->first]->setValue(1000*1000*1000 - otherBillionValue);
            }
            else
            {
                _billions[it->first]->setValue(thisBillionValue - otherBillionValue);
            }
        }
    }
    return (*this);
}

INumber& INumber::operator*(INumber& copy)
{
    // currently only outputputting BS
    _sign *= copy._sign;
    std::map<int, Billion*>::iterator it;
    for (it = _billions.begin(); it != _billions.end(); it++)
        it->second->setValue(it->second->getValue() * copy.getValue(it->first));
    return (*this);
}

double INumber::divideINumber(INumber& copy)
{
    // need to approx the result by dividing the highest index billion by the highest index billion
    _sign *= copy._sign;
    
    std::map<int, Billion*>::iterator it1;
    it1 = _billions.begin();
    std::cout << "[debug]" << it1->second->getValue() << "\n";

    std::map<int, Billion*>::iterator it2;
    it2 = copy._billions.begin();
    std::cout << "[debug]" << it2->second->getValue() << "\n";

    double div = (double) pow(1000*1000*1000, abs(it1->first - it2->first)) * it1->second->getValue() / (it2->second->getValue());
    int indexdiff = it2->first - it1->first;

    // 1 / .1 = index 0 / index -1 -> 1 / 1 000 000 000 : div by 10 Billion, 
    
    return (div);
}

void INumber::multiplyScalar(int scalar)
{
    unsigned int value;
    unsigned int overflow;

    if (scalar < 0)
    {
        _sign = !_sign;
        scalar *= -1;    
    }
    overflow = 0;
    std::map<int, Billion*>::iterator it;
    for (it = _billions.begin(); it != _billions.end(); it++)
    {
        value = it->second->getValue() * scalar + overflow;
        //std::cout << "[debug value1]" << value << "\n";
        overflow = 0;
        if (value >= 1000*1000*1000)
        {
            overflow = value / (BILLION);
            //std::cout << "[debug overflow]" << overflow << "\n";
            value %= (BILLION);
            //std::cout << "[debug value3]" << value << "\n";
        }
        //std::cout << "[debug value2]" << value << "\n";
        it->second->setValue(value);
    }
}

void INumber::divideScalar(int scalar)
{
    if (scalar < 0)
    {
        _sign = !_sign;
        scalar *= -1;
    }
    std::map<int, Billion*>::iterator it;
    for (it = _billions.begin(); it != _billions.end(); it++)
    {
        it->second->setValue((unsigned int) it->second->getValue() / scalar);
    }
}
