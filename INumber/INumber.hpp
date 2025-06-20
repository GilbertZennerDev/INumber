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

#include <deque>
#include <iostream>

class INumber
{
    private:
        int comma_pos;
        bool sign;
        std::deque<char> digits;
        std::deque<char> filled;
    public:
        INumber();
        INumber(std::string nbr);
        INumber(INumber const& copy);
        INumber& operator=(INumber const& copy);
        ~INumber();  

        void setFilled(std::deque<char>& newfilled);
        std::deque<char>& getDigits();

        void FillWith0(INumber& target, size_t num_size);

        void pushInput(size_t limit, bool back);
        
        void push_back(char nbr);
        void push_front(char nbr);

        void push_back_filled(char nbr);
        void push_front_filled(char nbr);

        void MakeFilled(INumber& otherINumber, size_t num_size);
        
        void handleAddOverflow(int *result, int *rest);
        
        int getInt(size_t index);
        size_t getSize();
        
        void add(INumber& otherINumber);
        
        void add(std::string newnbr);
        void multiply(std::string newnbr);

        void getNumSize(size_t *num_size, INumber& otherINumber);
        
        void printDigits();
        void printDebug(std::string prefix, std::string msg);
};