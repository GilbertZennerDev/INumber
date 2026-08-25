/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INumber.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:19:20 by gzenner           #+#    #+#             */
/*   Updated: 2025/08/25 00:00:00 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INumber.hpp"
#include <sstream>
#include <cstdio>

// value at "index" is stored in _int[index] for index >= 0,
// or _frac[-index - 1] for index < 0.

unsigned int INumber::getValue(int index) const
{
    if (index >= 0)
    {
        if ((size_t)index < _int.size())
            return (_int[index]);
        return (0);
    }
    size_t pos = (size_t)(-index - 1);
    if (pos < _frac.size())
        return (_frac[pos]);
    return (0);
}

void INumber::setValue(unsigned int newvalue, int index)
{
    if (index >= 0)
    {
        if ((size_t)index >= _int.size())
            _int.resize(index + 1, 0);
        _int[index] = newvalue;
    }
    else
    {
        size_t pos = (size_t)(-index - 1);
        if (pos >= _frac.size())
            _frac.resize(pos + 1, 0);
        _frac[pos] = newvalue;
    }
}

bool INumber::getSign() const
{
    return (_sign);
}

void INumber::setSign(bool sign)
{
    _sign = sign;
}

void INumber::addBillion(unsigned int value, int index)
{
    try
    {
        if (getValue(index) != 0)
            throw ("Billion already set.\n");
        setValue(value, index);
    }
    catch (char const *msg)
    {
        std::cout << msg;
    }
}

void INumber::overwriteBillion(unsigned int value, int index)
{
    setValue(value, index);
}

void INumber::addValue(unsigned int addvalue, int index)
{
    if (addvalue == 0)
        return ;
    unsigned long long sum = (unsigned long long)getValue(index) + addvalue;
    setValue((unsigned int)(sum % (unsigned long long)BILLION), index);
    unsigned long long overflow = sum / (unsigned long long)BILLION;
    if (overflow)
        addValue((unsigned int)overflow, index + 1);
}

void INumber::subValue(unsigned int subvalue, int index)
{
    if (subvalue == 0)
        return ;
    unsigned int current = getValue(index);
    if (current < subvalue)
    {
        subValue(1, index + 1);
        setValue((unsigned int)((unsigned long long)current + (unsigned long long)BILLION - subvalue), index);
    }
    else
    {
        setValue(current - subvalue, index);
    }
}

void INumber::addMagnitude(INumber& src)
{
    for (size_t i = 0; i < src._int.size(); i++)
        if (src._int[i] != 0)
            addValue(src._int[i], (int)i);
    for (size_t i = 0; i < src._frac.size(); i++)
        if (src._frac[i] != 0)
            addValue(src._frac[i], -(int)i - 1);
}

void INumber::subMagnitude(INumber& src)
{
    for (size_t i = 0; i < src._int.size(); i++)
        if (src._int[i] != 0)
            subValue(src._int[i], (int)i);
    for (size_t i = 0; i < src._frac.size(); i++)
        if (src._frac[i] != 0)
            subValue(src._frac[i], -(int)i - 1);
}

std::pair<int, unsigned int> INumber::highestLimb()
{
    for (int i = (int)_int.size() - 1; i >= 0; i--)
        if (_int[i] != 0)
            return (std::make_pair(i, _int[i]));
    for (size_t i = 0; i < _frac.size(); i++)
        if (_frac[i] != 0)
            return (std::make_pair(-(int)i - 1, _frac[i]));
    return (std::make_pair(0, 0u));
}

int INumber::compareMagnitude(INumber& other) const
{
    int highestThis = -1;
    for (int i = (int)_int.size() - 1; i >= 0; i--)
    {
        if (_int[i] != 0)
        {
            highestThis = i;
            break ;
        }
    }
    int highestOther = -1;
    for (int i = (int)other._int.size() - 1; i >= 0; i--)
    {
        if (other._int[i] != 0)
        {
            highestOther = i;
            break ;
        }
    }
    if (highestThis != highestOther)
        return (highestThis > highestOther ? 1 : -1);
    for (int i = highestThis; i >= 0; i--)
    {
        unsigned int va = _int[i];
        unsigned int vb = other._int[i];
        if (va != vb)
            return (va > vb ? 1 : -1);
    }
    size_t maxFrac = _frac.size() > other._frac.size() ? _frac.size() : other._frac.size();
    for (size_t i = 0; i < maxFrac; i++)
    {
        unsigned int va = (i < _frac.size()) ? _frac[i] : 0;
        unsigned int vb = (i < other._frac.size()) ? other._frac[i] : 0;
        if (va != vb)
            return (va > vb ? 1 : -1);
    }
    return (0);
}

void INumber::printBillions()
{
    std::cout << (_sign ? "positive\n" : "negative\n");
    for (int i = (int)_int.size() - 1; i >= 0; i--)
    {
        if (_int[i] != 0)
            std::cout << "index: " << i << " with value: " << _int[i] << "\n";
    }
    for (size_t i = 0; i < _frac.size(); i++)
    {
        if (_frac[i] != 0)
            std::cout << "index: " << -(int)i - 1 << " with value: " << _frac[i] << "\n";
    }
}

void INumber::printBillion(int index)
{
    bool exists = (index >= 0) ? ((size_t)index < _int.size()) : ((size_t)(-index - 1) < _frac.size());
    if (exists)
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
    std::cout << "Size of Billions: " << (_int.size() + _frac.size()) << "\n";
}

void INumber::printMemoryUsage()
{
    size_t limbs = _int.size() + _frac.size();
    size_t bytes = _int.capacity() * sizeof(unsigned int) + _frac.capacity() * sizeof(unsigned int) + sizeof(*this);
    size_t digits = limbs * 9;

    std::cout << "Limbs stored: " << limbs << " (" << digits << " decimal digits)\n";
    std::cout << "Real memory used: " << bytes << " bytes\n";
    if (digits)
        std::cout << "Density: " << (double)bytes / (double)digits << " bytes/digit "
                   << "(theoretical minimum with 32-bit limbs is 4/9 ~= 0.444)\n";
}

std::string INumber::toString()
{
    std::ostringstream oss;
    int highest = -1;

    for (int i = (int)_int.size() - 1; i >= 0; i--)
    {
        if (_int[i] != 0)
        {
            highest = i;
            break ;
        }
    }

    bool isZero = (highest < 0);
    if (isZero)
    {
        for (size_t i = 0; i < _frac.size(); i++)
        {
            if (_frac[i] != 0)
            {
                isZero = false;
                break ;
            }
        }
    }

    if (!_sign && !isZero)
        oss << "-";

    if (highest < 0)
        oss << "0";
    else
    {
        for (int i = highest; i >= 0; i--)
        {
            if (i == highest)
                oss << _int[i];
            else
            {
                char buf[16];
                snprintf(buf, sizeof(buf), "%09u", _int[i]);
                oss << buf;
            }
        }
    }

    if (!_frac.empty())
    {
        oss << ".";
        for (size_t i = 0; i < _frac.size(); i++)
        {
            char buf[16];
            snprintf(buf, sizeof(buf), "%09u", _frac[i]);
            oss << buf;
        }
    }
    return (oss.str());
}

void INumber::print()
{
    std::cout << toString() << "\n";
}

void INumber::saveToFile(std::string filename)
{
    std::ofstream file(filename.c_str());
    file << toString();
    file.close();
}

std::ostream& operator<<(std::ostream& os, INumber& nb)
{
    os << nb.toString();
    return (os);
}
