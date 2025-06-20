/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IPrimes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:44:36 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/20 17:31:58 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IPrimes.hpp"

IPrimes::IPrimes()
{
    
}

IPrimes::IPrimes(unsigned long long number): number(number)
{
    collectAllPrimes();
    getPrimes();
    displayPrimes();
}

IPrimes::~IPrimes()
{
    primes.clear();
}

bool IPrimes::IsPrime(unsigned long long nb)
{
    for(unsigned long long i=2; i <= nb / i; i++)
    {
        if (nb % i == 0)
        {
            return (false);
        }
    }
    return (true);   
}

void IPrimes::collectAllPrimes()
{
    for(unsigned long long nb = 2; nb <= number / nb + 1; nb++)
    {
        if (IsPrime(nb))
        {
            std::cout << "debug collect prime:" << nb << "\n";
            allPrimes.push_back(nb);
        }
    }
}

void IPrimes::getPrimes()
{
    unsigned long long nb = number;
    for(std::deque<unsigned long long>::iterator it = allPrimes.begin(); it != allPrimes.end(); it++)
    {
        while (nb % *it == 0)
        {
            nb /= *it;
            primes.push_back(*it);
        }
    }
}

void IPrimes::displayPrimes()
{
    for(std::deque<unsigned long long>::iterator it = primes.begin(); it != primes.end(); it++)
    {
        std::cout<<"Prime:" << *it << "\n";
    }
}