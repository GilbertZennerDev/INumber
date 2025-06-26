/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:22:46 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/26 17:39:30 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INumber.hpp"

int main()
{
    //std::string nbr;

    //nbr = "-";
    
    /*INumber nb;
    nb.addBillion(1, 0);
    nb.addBillion(2, 1);

    INumber nb2;
    nb2.addBillion(13, 0);
    
    nb + nb2;

    INumber nb3 = INumber(123443212);
    INumber nb4(nb);

    INumber nb5 = nb;

    //nb.multiplyScalar(2);
    //nb.printBillions();*/

    //INumber nb7("numberfiles/number.txt", 0);
    //nb6.multiplyScalar(2);
    //nb6.printBillions();

    //INumber nb7("numberfiles/pi_small.txt");
    /*nb7.printBillions();
    nb7.addBillion(1, 0);
    nb7.printMsg("a","b");*/

    //INumber nb7(3.123456789);
    //nb8.printBillions();

    /*nb7.printBillion(0);
    nb7.printBillion(-1);
    nb7.printBillion(-2);
    nb7.printBillion(-1000);
    nb7.printBillion(-10000);*/

    INumber nb = INumber();
    nb.addBillion(1, 10);
    INumber nb2 = INumber();
    nb2.addBillion(1, -20);
    //nb.printBillions();
    //nb2.printBillions();
    //nb * nb2;
    double div = nb.divideINumber(nb2);
    std::cout << "div = " << div << "\n";

    //nb.printBillions();
    
    return (0);
}