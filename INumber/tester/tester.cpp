/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:22:46 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/27 17:09:53 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INumber.hpp"

void testConstructors()
{
    INumber nb;
    //nb.printBillions();

    INumber nb2(nb);
    //nb2.printBillions();

    INumber nb3(3);
    INumber nb4(nb3);
    //nb3.printBillions();
    //nb4.printBillions();

    INumber nb5(3.14);
    INumber nb6(nb5);
    nb5.printBillions();
    nb6.printBillions();
    
    nb5.printBillionsSize();
    nb6.printBillionsSize();

    INumber nb7(3, -10, 10);
    INumber nb8(nb7);
    
    nb7.printBillionsSize();
    nb8.printBillionsSize();
}

void Circle()
{
    //INumber nb("../numberfiles/pi_small.txt");
    INumber nb(3.141592);
    nb.multiplyScalar(8);
    //nb.addValue(1, 0);
    nb.printBillions();
}

int main()
{
    Circle();
    return (0);
}