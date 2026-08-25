/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INumber.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:19:16 by gzenner           #+#    #+#             */
/*   Updated: 2025/08/25 00:00:00 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <utility>
#include <iostream>
#include <exception>
#include <fstream>
#include <string>

#define BILLION (1000*1000*1000)

// Storage layout: two contiguous limb arrays, base 1,000,000,000 (9 decimal
// digits per 4-byte limb). _int[i] holds the limb at index i (units and up,
// growing towards more significant digits). _frac[i] holds the limb at
// index -(i+1) (growing towards more precision after the decimal point).
// No per-limb heap allocation and no tree/map bookkeeping: the only memory
// spent beyond the raw digits is the two vectors' own (amortized O(1)) growth
// slack, so precision is bounded only by available RAM.
class INumber
{
    private:
        bool _sign;
        std::vector<unsigned int> _int;
        std::vector<unsigned int> _frac;

        void addMagnitude(INumber& src); // this += |src|
        void subMagnitude(INumber& src); // this -= |src|, requires |this| >= |src|
        std::pair<int, unsigned int> highestLimb(); // {index, value} of the most significant nonzero limb

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

        // Comparison (compares absolute value / magnitude only)
        int compareMagnitude(INumber& other) const;

        // Tools (kept for API compatibility: places a limb at an index unless already set)
        void addBillion(unsigned int value, int index);
        void overwriteBillion(unsigned int value, int index);

        // Scalar Operations
        void multiplyScalar(int scalar);
        void divideScalar(int scalar);

        // GETTERS
        unsigned int getValue(int index) const;
        bool getSign() const;

        // SETTERS
        void setValue(unsigned int newvalue, int index);
        void addValue(unsigned int addvalue, int index);
        void subValue(unsigned int subvalue, int index);
        void setSign(bool sign);

        // DEBUG AND INFO
        void printBillions();
        void printBillion(int);
        static void printMsg(std::string prefix, std::string msg);
        void printBillionsSize();
        void printMemoryUsage(); // shows real bytes/digit achieved by this layout

        // Output / Persistence
        std::string toString();
        void print();
        void saveToFile(std::string filename);
};

std::ostream& operator<<(std::ostream& os, INumber& nb);
