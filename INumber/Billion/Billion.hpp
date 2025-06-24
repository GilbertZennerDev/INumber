/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Billion.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:42:17 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/24 16:43:55 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Billion
{
    private:
        unsigned int _value;
        int _index;
    public:
        Billion();
        Billion(unsigned int, int);
        Billion(Billion const& copy);
        Billion& operator=(Billion const& copy);
        ~Billion();

        int getIndex();
        unsigned int getValue();
        void setValue(unsigned int);
};