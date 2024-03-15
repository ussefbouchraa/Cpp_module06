/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:57:55 by ybouchra          #+#    #+#             */
/*   Updated: 2024/03/15 03:34:15 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <ctype.h>

enum e_types
{
    _char,
    _int,
    _float,
    _double,
    _pseudo_f,
    _pseudo_d,
    _other
};

class ScalarConverter{
    public:
        void static convert(const std::string literal);  
};

