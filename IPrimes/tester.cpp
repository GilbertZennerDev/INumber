/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:40:20 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/20 17:32:24 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IPrimes.hpp"

int main()
{
    IPrimes ip;
    for(unsigned long long i = 2; i < 5; i++)
    {
        if (ip.IsPrime(i))
            std::cout << i << " is prime? " << ip.IsPrime(i) << "\n";
    }
    IPrimes ip2 = IPrimes(2*3*5*7*11*13*17*2*3*5*7*11*13);

    //IPrimes ip3 = IPrimes(9999999999999);
        
    return (0);
}