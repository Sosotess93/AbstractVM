//
// mainInstrution.cpp for  in /home/sofiane/Documents/abstractVM_2016/sources/sample
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Sat Jul 22 18:23:50 2017 sofiane
// Last update Sun Jul 23 17:47:28 2017 sofiane
//

#include "Instruction.hpp"
#include "Exception.hpp"
#include "Factory.hpp"
#include "Types.hpp"

int		main(void)
{
  Factory	F;
  Factory	tmp;
  eOperandType	type = INT8;
  std::string	value = "42";
  std::stack<IOperand*> test;
  Instruction	I;

  try {
    I.push(F.createOperand(type, value)); // PUSH
    value = "43";
    I.push(F.createOperand(type, value)); // PUSH
    I.dump();
    I.add();
    I.dump();
    //    I.assert(F.createOperand(type, value)); // Fonction qui vérifie//  I.swap();
    //I.clear(); //Fonction qui sert à vider la stack
    //    I.pop(); //Fonction qui supprime le dernier élément de la stack
    //I.dump(); //Fonction qui affiche la stack
  }
  catch (Exception const &e)
    {
      std::cerr << e.what() << std::endl;
      return (84);
    }

  return (0);
}
