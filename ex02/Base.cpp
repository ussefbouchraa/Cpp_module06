/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:43:58 by ybouchra          #+#    #+#             */
/*   Updated: 2024/03/15 12:10:09 by ybouchra         ###   ########.fr       */
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
    switch (getRandomInt())
    {
    case 1 :
        return(std::cout << "instanciate A\n", new(A));
    case 2 :
        return(std::cout << "instanciate B\n", new(B));
    case 3 :
        return(std::cout << "instanciate C\n", new(C));
    }
    return(NULL);
    
}

void Base::identify(Base* p)
{

    A *type1 = dynamic_cast<A*>(p);
    B *type2 = dynamic_cast<B*>(p);
    C *type3 = dynamic_cast<C*>(p);

    if(type1)
        std::cout << "The Base Class Point Of Direved Class : A\n";
    else if(type2)
        std::cout << "The Base Class Point Of Direved Class : B\n";
    else if(type3)
        std::cout << "The Base Class Point Of Direved Class : C\n";
}

void Base::identify(Base& p)
{
    try{
        A &type1 = dynamic_cast<A&>(p);
        std::cout <<"The Base Class Point Of Direved Class : A\n";
        (void)&type1;
    }
    catch(std::exception &ex){
        std::cerr << "Dynamic cast failed: " << ex.what() << std::endl;
    }
    try{
        B &type2 = dynamic_cast<B&>(p);
        std::cout << "The Base Class Point Of Direved Class : B\n";
        (void)&type2;
    }
    catch(std::exception &ex){
    std::cerr << "Dynamic cast failed: " << ex.what() << std::endl;
    }
    try{
        C &type3 = dynamic_cast<C&>(p);
        std::cout << "The Base Class Point Of Direved Class : C\n";
        (void)&type3;
    }
    catch(std::exception &ex){
        std::cerr << "Dynamic cast failed: " << ex.what() << std::endl;
    }

}
Base::~Base()
{
    // std::cout << "~Destructor Called\n";
}