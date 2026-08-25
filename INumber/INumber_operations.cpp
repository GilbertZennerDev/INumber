/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INumber_operations.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:49:12 by gzenner           #+#    #+#             */
/*   Updated: 2025/08/25 00:00:00 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INumber.hpp"
#include <cmath>
#include <algorithm>

INumber& INumber::operator+(INumber& copy)
{
    if (this == &copy)
    {
        INumber other(copy);
        return (*this + other);
    }

    if (_sign == copy._sign)
    {
        addMagnitude(copy);
    }
    else
    {
        int cmp = compareMagnitude(copy);
        if (cmp == 0)
        {
            std::fill(_int.begin(), _int.end(), 0);
            std::fill(_frac.begin(), _frac.end(), 0);
            _sign = true;
        }
        else if (cmp > 0)
        {
            // |this| > |copy|: subtract copy from this, keep this's sign
            subMagnitude(copy);
        }
        else
        {
            // |this| < |copy|: result = |copy| - |this|, take copy's sign
            INumber thisMagnitude(*this);
            std::fill(_int.begin(), _int.end(), 0);
            std::fill(_frac.begin(), _frac.end(), 0);
            addMagnitude(copy);
            subMagnitude(thisMagnitude);
            _sign = copy._sign;
        }
    }
    return (*this);
}

INumber& INumber::operator-(INumber& copy)
{
    INumber negated(copy);
    negated._sign = !negated._sign;
    return (*this + negated);
}

INumber& INumber::operator*(INumber& copy)
{
    bool resultSign = (_sign == copy._sign);
    INumber a(*this);
    INumber b(copy);

    std::vector<std::pair<int, unsigned int> > aLimbs;
    std::vector<std::pair<int, unsigned int> > bLimbs;

    for (size_t i = 0; i < a._int.size(); i++)
        if (a._int[i] != 0)
            aLimbs.push_back(std::make_pair((int)i, a._int[i]));
    for (size_t i = 0; i < a._frac.size(); i++)
        if (a._frac[i] != 0)
            aLimbs.push_back(std::make_pair(-(int)i - 1, a._frac[i]));

    for (size_t i = 0; i < b._int.size(); i++)
        if (b._int[i] != 0)
            bLimbs.push_back(std::make_pair((int)i, b._int[i]));
    for (size_t i = 0; i < b._frac.size(); i++)
        if (b._frac[i] != 0)
            bLimbs.push_back(std::make_pair(-(int)i - 1, b._frac[i]));

    std::fill(_int.begin(), _int.end(), 0);
    std::fill(_frac.begin(), _frac.end(), 0);

    for (size_t i = 0; i < aLimbs.size(); i++)
    {
        unsigned long long va = aLimbs[i].second;
        for (size_t j = 0; j < bLimbs.size(); j++)
        {
            unsigned long long vb = bLimbs[j].second;
            unsigned long long product = va * vb;
            int index = aLimbs[i].first + bLimbs[j].first;
            while (product > 0)
            {
                unsigned int part = (unsigned int)(product % (unsigned long long)BILLION);
                addValue(part, index);
                product /= (unsigned long long)BILLION;
                index++;
            }
        }
    }
    _sign = resultSign;
    return (*this);
}

double INumber::divideINumber(INumber& copy)
{
    // approximates the result by comparing the highest-order limbs of each number
    std::pair<int, unsigned int> l1 = highestLimb();
    std::pair<int, unsigned int> l2 = copy.highestLimb();

    if (l2.second == 0)
        return (0.0);

    double div = pow(1000.0 * 1000.0 * 1000.0, l1.first - l2.first)
        * ((double)l1.second / (double)l2.second);

    if (_sign != copy._sign)
        div = -div;
    return (div);
}

void INumber::multiplyScalar(int scalar)
{
    if (scalar < 0)
    {
        _sign = !_sign;
        scalar *= -1;
    }
    unsigned long long uscalar = (unsigned long long)scalar;
    INumber a(*this);
    std::fill(_int.begin(), _int.end(), 0);
    std::fill(_frac.begin(), _frac.end(), 0);

    for (size_t i = 0; i < a._int.size(); i++)
    {
        if (a._int[i] == 0)
            continue ;
        unsigned long long product = (unsigned long long)a._int[i] * uscalar;
        int index = (int)i;
        while (product > 0)
        {
            addValue((unsigned int)(product % (unsigned long long)BILLION), index);
            product /= (unsigned long long)BILLION;
            index++;
        }
    }
    for (size_t i = 0; i < a._frac.size(); i++)
    {
        if (a._frac[i] == 0)
            continue ;
        unsigned long long product = (unsigned long long)a._frac[i] * uscalar;
        int index = -(int)i - 1;
        while (product > 0)
        {
            addValue((unsigned int)(product % (unsigned long long)BILLION), index);
            product /= (unsigned long long)BILLION;
            index++;
        }
    }
}

void INumber::divideScalar(int scalar)
{
    if (scalar < 0)
    {
        _sign = !_sign;
        scalar *= -1;
    }
    unsigned long long remainder = 0;
    for (int i = (int)_int.size() - 1; i >= 0; i--)
    {
        unsigned long long current = remainder * (unsigned long long)BILLION + _int[i];
        _int[i] = (unsigned int)(current / (unsigned long long)scalar);
        remainder = current % (unsigned long long)scalar;
    }
    for (size_t i = 0; i < _frac.size(); i++)
    {
        unsigned long long current = remainder * (unsigned long long)BILLION + _frac[i];
        _frac[i] = (unsigned int)(current / (unsigned long long)scalar);
        remainder = current % (unsigned long long)scalar;
    }
}
