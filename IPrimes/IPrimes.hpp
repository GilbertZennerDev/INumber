/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IPrimes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:38:55 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/20 17:31:58 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>

class IPrimes
{
    private:
        unsigned long long number;
        std::deque<unsigned long long> primes;
        std::deque<unsigned long long> allPrimes;
    public:
        IPrimes();
        IPrimes(unsigned long long);
        ~IPrimes();

        bool IsPrime(unsigned long long nb);
        void getPrimes();
        void collectAllPrimes();
        void displayPrimes();
};