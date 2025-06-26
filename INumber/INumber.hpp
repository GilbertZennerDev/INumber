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
        void addBillion(unsigned int value, int index); // adds 1 Billion with given value at given index
        void overwriteBillion(unsigned int value, int index); // adds 1 Billion with given value at given index

        // Scalar Operations
        void multiplyScalar(int scalar);
        void divideScalar(int scalar);

        // GETTERS
        unsigned int getValue(int index);
        Billion* getBillion(int index);

        // SETTERS
        void setValue(unsigned int newvalue, int index);

        // DEBUG AND INFO
        void printBillions();
        void printBillion(int);
        void printMsg(std::string prefix, std::string msg);
};