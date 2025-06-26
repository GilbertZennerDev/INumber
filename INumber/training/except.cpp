/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzenner <gzenner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:54:08 by gzenner           #+#    #+#             */
/*   Updated: 2025/06/26 11:23:48 by gzenner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <fstream>
#include <iostream>

int main()
{
    try
    {
        int age = 10;
        if (age < 18)
        {
            throw(age);
        }
    }
    catch (...)
    {
        std::cout << "Showing error message with num\n";// " << age << "\n";
    }
    return (0);
}