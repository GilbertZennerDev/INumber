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

int INumber::getInt(size_t index)
{
    if (index < digits.size())
        return (digits[index] - '0');
    else
        return (0);
}

void INumber::handleAddOverflow(int *result, int *rest)
{
    *rest = 0;
    if (*result > 9)
    {
        *result -= 10;
        *rest += 1;
    }
}

void INumber::multiply(std::string newnbr)
{
    
}

void INumber::add(std::string newnbr)
{
    // I want to add a simple number to mine
    // keeping it simple, let us assume there is no overflow
}

void INumber::add(INumber& otherINumber)
{
    int result;
    int rest;
    size_t i;

    getNumSize(&i, otherINumber);
    printDebug("getNumSize", "");
    std::cout<<i<<'\n';
    rest = 0;
    while(i > 0)
    {
        result = getInt(i - 1) + otherINumber.getInt(i - 1) + rest;// - 2*'0';
        if (result > 9)
            handleAddOverflow(&result, &rest);
        else
        {
            result += rest;
            handleAddOverflow(&result, &rest);
        }
        digits[i - 1] = result + '0';
        --i;
    }
    if (rest > 0)
    {
        digits.push_front(rest + '0');
        rest = 0;
    }
}
