/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 04:41:20 by ybouchra          #+#    #+#             */
/*   Updated: 2024/03/15 07:00:01 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data _Data;

    
    uintptr_t uip = Serializer::serialize(&_Data);
    Data* ptr = Serializer::deserialize(uip);

   std::cout << &_Data << std::endl;
   std::cout << uip << std::endl;
   std::cout << ptr << std::endl;

   if(ptr == &_Data)
    std::cout << "They Are The Same\n";
   else
    std::cout << "They Are Not The Same\n";
}