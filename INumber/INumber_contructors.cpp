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

#include <stdio.h>
#include <stdlib.h>

INumber::INumber(): _sign(true)
{
    for(int i = -1000; i < 1000; i++)
    {
        //_billions[i] = NULL;
    }
}

INumber::INumber(int nb)
{
    _sign = (nb >= 0);
    if (!_sign)
        nb *= -1;
    //for(int i = -1000; i < 1000; i++)
    addBillion(static_cast<unsigned int>(nb), 0);
}

INumber::INumber(int nb, int lower_limit, int upper_limit)
{
    int tmp;

    _sign = (nb >= 0);
    if (!_sign)
        nb *= -1;
    if (lower_limit > upper_limit)
    {
        tmp = lower_limit;
        lower_limit = upper_limit;
        upper_limit = tmp;
    }
    if (lower_limit == upper_limit)
        upper_limit++;
    for(int i = lower_limit; i < upper_limit; i++)
        addBillion(static_cast<unsigned int>(nb), i);
}

INumber::INumber(double nb)
{
    _sign = (nb >= 0);
    if (!_sign)
        nb *= -1;
    std::cout << "[debug double]:" << (unsigned int)nb << " and " << nb - (unsigned int)nb << "\n";
    addBillion((unsigned int)nb, 0);
    addBillion((nb - (unsigned int)nb)*1000*1000*1000, -1);
}

INumber::INumber(INumber const& copy)
{
    std::map<int, Billion*>::const_iterator it;
    for(it = copy._billions.begin(); it != copy._billions.end(); it++)
    {
        if (it->second->getValue() != 0)
        {
            this->_billions[it->first] = new Billion(it->second->getValue(), it->first);
        }
    }
}

INumber& INumber::operator=(INumber const& copy)
{
    if (this != &copy)
    {
        std::map<int, Billion*>::const_iterator it;
        for(it = _billions.begin(); it != _billions.end(); it++)
        {
            delete (it->second);
        }
        for(it = copy._billions.begin(); it != copy._billions.end(); it++)
        {
            this->_billions[it->first] = new Billion(it->second->getValue(), it->second->getIndex());   
        }
    }
    return (*this);
}

INumber::~INumber()
{
    std::map<int, Billion*>::iterator it;
    for(it = _billions.begin(); it != _billions.end(); it++)
    {
        delete (it->second);
    }
}

INumber::INumber(std::string filename, unsigned int linenumber)
{
    std::ifstream file(filename);
    std::string number;
    int comma;
    int comma2;

    while(getline(file, number))
    {
        if (linenumber == 0)
            break;
        --linenumber;
    }
    _sign = (number[0] != '-');
    comma = number.find_first_of(".,");
    comma2 = number.find_last_of(".,");
    if (comma != comma2)
    {
        std::cout << "Error: More than 1 comma.\n";
        return ;
    }
    if (comma != std::string::npos)
    {
        std::string beforecomma = number.substr(0, comma);
        std::string aftercomma = number.substr(comma + 1);
        addBillion(atol(beforecomma.c_str()), 0);
        addBillion(atol(aftercomma.c_str()), -1);
    }
    else
    {
        addBillion(atol(number.c_str()), 0);
    }
    file.close();
}

INumber::INumber(std::string filename)
{
    std::ifstream file(filename);
    std::string line;
    std::string number;
    std::string beforecomma;
    std::string aftercomma;
    int index;
    int comma;

    while(getline(file, line))
        number += line;
    comma = number.find_first_of(".,");
    if (comma != number.find_last_of(".,"))
    {
        std::cout << "Error: More than 1 comma.\n";
        return ;
    }
    index = 0;
    if (comma != std::string::npos)
    {
        // comma
        beforecomma = number.substr(0, comma);
        aftercomma = number.substr(comma + 1);
        while(beforecomma.size() >= 9)
        {
            addBillion(atol(beforecomma.substr(beforecomma.size() - 9).c_str()), index++);
            beforecomma.erase(beforecomma.size() - 9);
        }
        addBillion(atol(beforecomma.c_str()), index++);
        index = -1;
        while(aftercomma.size() > 9)
        {
            addBillion(atol(aftercomma.substr(0, 9).c_str()), index--);
            aftercomma.erase(0, 9);
        }
        addBillion(atol(aftercomma.c_str()), index--);
    }
    else
    {
        // no comma
        while(number.size() >= 9)
        {
            addBillion(atol(number.substr(number.size() - 9).c_str()), index++);
            number.erase(number.size() - 9);
        }
        addBillion(atol(number.c_str()), index++);
    }
    
    file.close();
}