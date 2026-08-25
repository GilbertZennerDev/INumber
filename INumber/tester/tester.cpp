/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:22:46 by gzenner           #+#    #+#             */
/*   Updated: 2025/08/25 00:00:00 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INumber.hpp"
#include <iostream>

static void section(std::string name)
{
    std::cout << "\n--- " << name << " ---\n";
}

void testConstructors()
{
    INumber nb;
    INumber nb2(nb);

    INumber nb3(3);
    INumber nb4(nb3);

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
    INumber nb(3.2);
    nb.multiplyScalar(3);
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

void runRegressionSuite()
{
    section("addition");
    {
        INumber a(123456789);
        INumber b(987654321);
        INumber c = a + b;
        std::cout << "123456789 + 987654321 = " << c << " (expect 1111111110)\n";
    }

    section("addition across billions (carry)");
    {
        INumber a(999999999);
        INumber b(1);
        INumber c = a + b;
        std::cout << "999999999 + 1 = " << c << " (expect 1000000000)\n";
    }

    section("decimals");
    {
        INumber a(3.14);
        INumber b(0.04);
        INumber c = a + b;
        std::cout << "3.14 + 0.04 = " << c << " (expect 3.18)\n";
    }

    section("subtraction");
    {
        INumber a(1000000000);
        INumber b(1);
        INumber c = a - b;
        std::cout << "1000000000 - 1 = " << c << " (expect 999999999)\n";
    }

    section("subtraction going negative");
    {
        INumber a(5);
        INumber b(10);
        INumber c = a - b;
        std::cout << "5 - 10 = " << c << " (expect -5)\n";
    }

    section("multiplication");
    {
        INumber a(123456789);
        INumber b(987654321);
        INumber c = a * b;
        std::cout << "123456789 * 987654321 = " << c << " (expect 121932631112635269)\n";
    }

    section("multiplyScalar with big overflow chain");
    {
        INumber a(0.999999999);
        a.multiplyScalar(999);
        std::cout << "0.999999999 * 999 = " << a << " (expect 998.999999001)\n";
    }

    section("divideScalar");
    {
        INumber a(1000000000);
        a.divideScalar(4);
        std::cout << "1000000000 / 4 = " << a << " (expect 250000000)\n";
    }

    section("negative scalar flips sign");
    {
        INumber a(42);
        a.multiplyScalar(-1);
        std::cout << "42 * -1 = " << a << " (expect -42)\n";
    }

    section("save/load roundtrip (huge number via string constructor)");
    {
        INumber a("../numberfiles/big_test_input.txt");
        a.saveToFile("../numberfiles/roundtrip_test.txt");
        INumber b("../numberfiles/roundtrip_test.txt");
        std::cout << "loaded original: " << a << "\n";
        std::cout << "saved + reloaded: " << b << "\n";
    }

    section("pi.txt file");
    {
        INumber pi("../numberfiles/pi.txt");
        std::cout << "pi from file (first 60 chars): " << pi.toString().substr(0, 60) << "...\n";
        pi.printMemoryUsage();
    }
}

int main()
{
    runRegressionSuite();
    return (0);
}
