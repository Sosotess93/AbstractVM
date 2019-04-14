//
// Factory.hpp for fac in /home/elsamr_a/rendu/synthèse/abstractVM_2016
//
// Made by Antoine El Samra
// Login   <elsamr_a@epitech.net>
//
// Started on  Fri Jul 21 15:56:52 2017 Antoine El Samra
// Last update Sat Jul 22 18:49:46 2017 sofiane
//

#ifndef FACTORY_HPP_
# define FACTORY_HPP_

# include "IOperand.hpp"
#include <cstdlib>
# include <map>

class Factory
{
private:
  IOperand	*createInt8(const std::string& value);
  IOperand	*createInt16(const std::string& value);
  IOperand	*createInt32(const std::string& value);
  IOperand	*createFloat(const std::string& value);
  IOperand	*createDouble(const std::string& value);
  IOperand	*createBigDecimal(const std::string& value);

  typedef IOperand *(Factory::*func)(const std::string &value);

public:
  Factory();
  virtual ~Factory() {};
  static IOperand	*createOperand(eOperandType type, const std::string& value);
};

#endif /* FACTORY_HPP_ */
