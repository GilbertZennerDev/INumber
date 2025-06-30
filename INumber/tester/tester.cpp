/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:22:46 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/30 17:23:11 by gzenner          ###   ########.fr       */
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
    INumber nb(3.2);
    nb.multiplyScalar(3); //
    //nb.addValue(1, 0);
    nb.printBillions();
}

void testAddValue()
{
    INumber nb;
    nb.addValue(1000*1000*1000-1, 0);
    nb.printBillions();
    nb.addValue(1, 0);
    nb.printBillions();
}

void addingINbs()
{
    INumber nb(3.14);
    INumber nb2(0.04);
    INumber nb3;

    nb3 = nb + nb2;
    nb3.printBillions();
}

int main()
{
    //Circle();
    addingINbs();
    return (0);
}