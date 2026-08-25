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
#include <cctype>

bool IsValidNumber(std::string nb)
{
    std::string::iterator it;
    for(it = nb.begin(); it != nb.end(); it++)
    {
        if (!isdigit(*it) && *it != '.' && *it != ',' && !(it == nb.begin() && *it == '-'))
        {
            return (false);
        }
    }
    return (true);
}

INumber::INumber(): _sign(true)
{
}

INumber::INumber(int nb)
{
    _sign = (nb >= 0);
    if (!_sign)
        nb *= -1;
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
    addBillion((unsigned int)nb, 0);
    addBillion((unsigned int)((nb - (unsigned int)nb) * (1000.0 * 1000.0 * 1000.0) + 0.5), -1);
}

INumber::INumber(INumber const& copy): _sign(copy._sign), _int(copy._int), _frac(copy._frac)
{
}

INumber& INumber::operator=(INumber const& copy)
{
    if (this != &copy)
    {
        _sign = copy._sign;
        _int = copy._int;
        _frac = copy._frac;
    }
    return (*this);
}

INumber::~INumber()
{
}

INumber::INumber(std::string filename, unsigned int linenumber)
{
    std::ifstream file(filename);
    std::string number;
    int comma;
    int comma2;

    while(getline(file, number))
    {
        if (!IsValidNumber(number))
        {
            printMsg("[input error]", "[bad number in file]");
            return ;
        }
        if (linenumber == 0)
            break;
        --linenumber;
    }
    _sign = (number.empty() || number[0] != '-');
    if (!_sign)
        number.erase(0, 1);
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
        while (aftercomma.size() < 9)
            aftercomma += "0";
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
    {
        number += line;
        if (!IsValidNumber(line))
        {
            printMsg("[input error]", "[bad number in file]");
            return ;
        }
    }
    _sign = (number.empty() || number[0] != '-');
    if (!_sign)
        number.erase(0, 1);
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
        if (!beforecomma.empty())
            addBillion(atol(beforecomma.c_str()), index++);
        index = -1;
        while(aftercomma.size() > 9)
        {
            addBillion(atol(aftercomma.substr(0, 9).c_str()), index--);
            aftercomma.erase(0, 9);
        }
        while (aftercomma.size() < 9)
            aftercomma += "0";
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
        if (!number.empty())
            addBillion(atol(number.c_str()), index++);
    }
    
    file.close();
}