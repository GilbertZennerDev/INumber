/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INumber.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:19:16 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/20 15:55:00 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <exception>
#include "Billion/Billion.hpp"

class Billion;

class INumber
{
    private:
        bool _sign;
        std::map<int , Billion *> _billions;
    public:
        INumber();
        INumber(INumber const& copy);
        INumber& operator=(INumber const& copy);
        ~INumber();
        void addBillion(unsigned int value, int index);

        void addINumber(INumber& copy);
        unsigned int getValue(int index);
        void setValue(unsigned int newvalue, int index);
};