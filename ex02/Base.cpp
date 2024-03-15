/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:43:58 by ybouchra          #+#    #+#             */
/*   Updated: 2024/03/15 09:17:49 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int getRandomInt() {
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    return ( 1 + std::rand() % 3);
}

Base* Base::generate(void)
{
    Base *base = NULL;
    
    switch (getRandomInt())
    {
    case 1 :
        std::cout << "instanciate A\n";
        base = new(A);
        break;
    case 2 :
        std::cout << "instanciate B\n";
        base = new(B);
        break;
    case 3 :
        std::cout << "instanciate C\n";
        base = new(C);
        break;
    }
    return(base);
    
}
Base::~Base()
{
    std::cout << "destructor called\n";
}