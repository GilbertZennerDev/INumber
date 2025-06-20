/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:22:46 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/20 15:59:24 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INumber.hpp"

int main()
{
    std::string nbr;

    //nbr = "-";
    
    INumber inumber = INumber();
    inumber.pushInput(3, true);

    inumber.printDigits();
    INumber inumber2 = INumber();
    inumber2.pushInput(4, true);
    
    inumber2.printDigits();
    inumber.add(inumber2);
    inumber.printDigits();

    return (0);
}