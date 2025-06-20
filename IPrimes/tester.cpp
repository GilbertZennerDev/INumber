/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:40:20 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/20 17:21:08 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IPrimes.hpp"

int main()
{
    IPrimes ip;
    for(size_t i=2; i < 5; i++)
    {
        if (ip.IsPrime(i))
            std::cout << i << " is prime? " << ip.IsPrime(i) << "\n";
    }
    IPrimes ip2 = IPrimes(2*3*5*7*11*13*17*2);
        
    return (0);
}