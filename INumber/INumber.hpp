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
#include <fstream>
#include <string>
#include "Billion/Billion.hpp"

#define BILLION 1000*1000*1000
#define HUNDREDMILLIONS 100*1000*1000

class Billion;

class INumber
{
    private:
        // sign and billions map
        bool _sign;
        std::map<int , Billion *> _billions;
    public:
        // Coplien Form plus other Constructors
        INumber();
        INumber(int);
        INumber(int nb, int lower_limit, int upper_limit);
        INumber(double);
        INumber(std::string filename);
        INumber(std::string filename, unsigned int linenumber);
        INumber(INumber const& copy);
        ~INumber();

        // Arithmetic Operations with other INumber
        INumber& operator=(INumber const& copy);
        INumber& operator+(INumber& copy);
        INumber& operator-(INumber& copy);
        INumber& operator*(INumber& copy);
        double divideINumber(INumber& copy);

        // Tools
        void addBillion(unsigned int value, int index); // adds 1 Billion with given value at given index if the Billion is not yet set
        void overwriteBillion(unsigned int value, int index); // adds 1 Billion with given value at given index

        // Scalar Operations
        void multiplyScalar(int scalar);
        void divideScalar(int scalar);

        // GETTERS
        unsigned int getValue(int index);
        Billion* getBillion(int index);

        // SETTERS
        void setValue(unsigned int newvalue, int index);
        void addValue(unsigned int addvalue, int index);

        // DEBUG AND INFO
        void printBillions();
        void printBillion(int);
        static void printMsg(std::string prefix, std::string msg);
        void printBillionsSize();
};