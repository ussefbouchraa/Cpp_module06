/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouchra <ybouchra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:57:58 by ybouchra          #+#    #+#             */
/*   Updated: 2024/03/15 04:04:11 by ybouchra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int is_int(std::string inp)
{
        int i = 0;
    
    while(inp[i] == '-' || inp[i] == '+')
        i++;
    if(!inp[i])
        return(0);
    while(inp[i])
    {
        if(!isdigit(inp[i]))
            return(0);
        i++;
    }
    return(1);
}

int is_double(std::string inp)
{
        int i = 0;
    
    while(inp[i] == '-' || inp[i] == '+')
        i++;
    if(!inp[i])
        return(0);
    while(inp[i])
    {
        if(inp[i] != '.' && !isdigit(inp[i]) )
            return(0);
        i++;
    }
    return(1);
}

int is_float(std::string inp)
{
        int i = 0;
    
    while(inp[i] == '-' || inp[i] == '+')
        i++;
    if(!inp[i])
        return(0);
    while(inp[i])
    {
        if((inp[i] != '.' && inp[i] != 'f' ) && !isdigit(inp[i]) )
            return(0);
        i++;
    }
    return(1);
}

int is_exist(std::string inp, char x)
{
    int i = -1;
    int cp = 0;
    if(inp.empty() || !inp.at(0))
        return(0);
    while(inp[++i])
    {
        if(inp[i] == x)
            cp++;
    }
    if(cp == 1)
        return(1);
    return(0);  
}


e_types get_type(std::string inp)
{
     if(isalpha(inp.at(0)) && inp.size() == 1 )
            return(_char);
        else if(is_int(inp))
            return(_int);     
        else if( (is_double(inp) && is_exist(inp, '.') ))
            return(_double);
        else if( (is_float(inp) && is_exist(inp, '.')  && is_exist(inp, 'f')) )
            return(_float);
        else if( inp == "inf"  || inp == "+inf" || inp == "-inf" || inp == "nan")    
            return(_pseudo_d);
        else if(inp == "inff" || inp == "+inff" || inp == "-inff" || inp == "nanf")
            return(_pseudo_f);
        else
            return(_other);
}

void Char_toOther(char _char)
{
    std::cout <<"char: "<< _char << std::endl;
    std::cout << "int: "   << static_cast<int>(_char) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(_char) <<'f'<< std::endl;
    std::cout << "double: "<< std::fixed << std::setprecision(2) << static_cast<double>(_char) << std::endl;
    

}
void Int_toOther(int _int)
{
    if(std::isprint(_int))
        std::cout <<"char: "<< static_cast<char>(_int) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: "   << _int << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_int) <<'f'<< std::endl;
    std::cout << "double: "<< std::fixed << std::setprecision(1) << static_cast<double>(_int) << std::endl;

}

void Float_toOther(float _float)
{
    if(std::isprint(static_cast<char>(_float)))
        std::cout <<"char: "<< static_cast<char>(_float) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
        

    std::cout <<"int: "<< static_cast<int>(_float) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << (_float) <<'f'<< std::endl;
    std::cout << "double: "<< std::fixed << std::setprecision(1) << static_cast<double>(_float)<< std::endl;

}

void Double_toOther(double _double)
{
    
    if(std::isprint(static_cast<char>(_double)))
        std::cout <<"char: "<< static_cast<char>(_double) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout <<"int: "<< static_cast<int>(_double) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(_double) <<'f'<< std::endl;
    std::cout << "double: "<< std::fixed << std::setprecision(1) << (_double)<< std::endl;

}
void PseudoLiteral_f(std::string literal)
{
    std::cout << "char: "  << "impossible" << std::endl;
    std::cout << "int: "   << "impossible" << std::endl;
    
    std::cout << "float: " << literal << std::endl;
    literal.resize(literal.size() - 1);
    std::cout << "double: "<< literal << std::endl;
}

void PseudoLiteral_d(std::string literal)
{
    std::cout << "char: "  << "impossible" << std::endl;
    std::cout << "int: "   << "impossible" << std::endl;
    
    std::cout << "float: " << literal <<'f'<<std::endl;
    std::cout << "double: "<< literal << std::endl;
}
void  ScalarConverter::convert(const std::string literal){
        
    try{
        
        e_types choice;
        choice = get_type(literal);
       
       switch (choice)
       {
            case _char :
                    std::cout << "*******is_char********\n";
                    Char_toOther(literal.at(0));
                break;
            case _int :
                    std::cout << "*********is_Int*******\n";
                    Int_toOther(std::stoi(literal));
                break;
            case _float :
                    std::cout << "*********is_Float******\n";
                    Float_toOther(std::stof(literal));
                break;
            case _double :
                    std::cout << "*********is_Double******\n";
                    Double_toOther(std::stod(literal));
                break;
            case _pseudo_f :
                    std::cout << "*********is_PseudoLiteral******\n";
                    PseudoLiteral_f(literal);
                break;
            case _pseudo_d :
                    std::cout << "*********is_PseudoLiteral******\n";
                    PseudoLiteral_d(literal);
                break;
            case _other :
                std::cout << "what the fucking type is that !!\n";
                break;
       }
    }
    catch(std::exception &ex)
    {
        std::cout << "err: " << ex.what() << std::endl;
    }
}

