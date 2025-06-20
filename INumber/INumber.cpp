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

void INumber::getNumSize(size_t *num_size, INumber& otherINumber)
{
    *num_size = (digits.size() >= otherINumber.digits.size() ? digits.size() : otherINumber.digits.size());
}

void INumber::setFilled(std::deque<char>& newfilled)
{
    filled = newfilled;
}

std::deque<char>& INumber::getDigits()
{
    return (digits);
}

void INumber::FillWith0(INumber& target, size_t num_size)
{
    target.setFilled(target.getDigits());
    // need to fill our own with 0s
    while(num_size > target.getSize())
    {
        target.push_front_filled('0');
        --num_size;
    }
}

void INumber::MakeFilled(INumber& otherINumber, size_t num_size)
{
    size_t  i;

    if (num_size > digits.size())
    {
        FillWith0(*this, num_size);
    }
    else
    {
        FillWith0(otherINumber, num_size);
    }
    // the rest is filled with the content of digits and other.digits repectively
}

void INumber::printDigits()
{
    size_t i;

    i = 0;
    if (!sign)
    {
        std::cout << '-' ;
        i = 1;
    }
    if (digits[i] == '0')
        ++i;
    while(i < digits.size())
    {
        if (i == comma_pos)
        {
            std::cout << '.';
        }
        else
        {
            if (i == 0 && digits[i] == 0)
            {
                continue;   
            }
            std::cout << digits[i];
        }
        ++i;
    }
    std::cout << "\n";
}

void INumber::push_back(char nbr)
{
    digits.push_back(nbr);
}

void INumber::push_front(char nbr)
{
    digits.push_front(nbr);
}

void INumber::push_back_filled(char nbr)
{
    filled.push_back(nbr);
}

void INumber::push_front_filled(char nbr)
{
    filled.push_front(nbr);
}

void INumber::pushInput(size_t limit, bool back)
{
    for(size_t i=0; i < limit; ++i)
    {
        if (back)
            push_back((i % 9 + 1) + '0');
        else
            push_front((i % 9 + 1) + '0');
    }
}

void INumber::printDebug(std::string prefix, std::string msg)
{
    std::cout<<"[debug "<<prefix <<"]" << msg << "\n";
}

size_t INumber::getSize()
{
    return (digits.size());
}