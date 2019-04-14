//
// mainFactory.cpp for  in /home/elsamr_a/rendu/synthèse/abstractVM_2016/sources/sample
// 
// Made by Antoine El Samra
// Login   <elsamr_a@epitech.net>
// 
// Started on  Sat Jul 22 17:27:50 2017 Antoine El Samra
// Last update Sun Jul 23 15:47:14 2017 Antoine El Samra
//

#include "Factory.hpp"
#include "Types.hpp"

#include <stack>
#include <iostream>

/* Execute moi! Commende: 
g++ -I./includes sources/Factory.cpp sources/sample/mainFactory.cpp sources/Types/*
 */

int	main(void)
{
  Factory	F;
  eOperandType	type = FLOAT;
  std::string	value = "42.42";
  std::stack<IOperand*>	test;

  test.push(F.createOperand(type, value)); //créer l'Operand, puis le push;
  std::cout << "hello\n"; // pasqu'on est poli quand même!
  std::cout << "toString: " << test.top()->toString() << std::endl << "getType: " << test.top()->getType() << std::endl;
  /*  test[0] + test[0];  // ça marche pas encore ça :/
  test[0] - test[0];
  test[0] * test[0];
  test[0] / test[0];
  test[0] % test[0];*/

  Double	I("5");

  test.push(I + *(test.top()));
  test.push(I * *(test.top()));
  test.push(I - *(test.top()));
  test.push(I / *(test.top()));
  test.push(I % *(test.top())); // modulo n'existe pas pour un float, il faudra gérer cette err!
  test.push(I + *F.createOperand(INT8, "10"));
  while (test.size() > 0)
    {
      std::cout << "toString: " << test.top()->toString() << std::endl << "getType: " << test.top()->getType() << std::endl;
      test.pop();
    }
  return (0);
}
