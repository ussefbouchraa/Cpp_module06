/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:41:28 by ybouchra          #+#    #+#             */
/*   Updated: 2024/03/15 08:22:38 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Base
{
    public:
        Base * generate(void);
        void identify(Base* p);
        void identify(Base& p);
        virtual ~Base();
};