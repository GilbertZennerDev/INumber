/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IPrimes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:38:55 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/20 17:14:29 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>

class IPrimes
{
    private:
        size_t number;
        std::deque<size_t> primes;
        std::deque<size_t> allPrimes;
    public:
        IPrimes();
        IPrimes(size_t);
        ~IPrimes();

        bool IsPrime(size_t nb);
        void getPrimes();
        void collectAllPrimes();
        void displayPrimes();
};