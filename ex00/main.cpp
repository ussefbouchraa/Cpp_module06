/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:12:17 by ybouchra          #+#    #+#             */
/*   Updated: 2024/03/14 01:16:04 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{

    if(ac == 2 && *av)
    {
        std::string literal;
        literal = static_cast<std::string>(av[1]);
        
        ScalarConverter::convert(literal);
    }
    else
        std::cout << "err: Syntax_Error !! One Param ." << std::endl;
}