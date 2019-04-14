//
// Factory.cpp for hello in /home/elsamr_a/rendu/synthèse/abstractVM_2016
// 
// Made by Antoine El Samra
// Login   <elsamr_a@epitech.net>
// 
// Started on  Fri Jul 21 16:34:00 2017 Antoine El Samra
// Last update Sun Jul 23 17:37:10 2017 Antoine El Samra
//

#include "Factory.hpp"
#include "Types.hpp"
#include <iostream>

Factory::Factory()
{
}

IOperand *	Factory::createInt8(const std::string& value)
{
  Int8 * V = new(Int8)(value);

  return ((IOperand *)V);
}

IOperand *	Factory::createInt16(const std::string& value)
{
  Int16 * V = new(Int16)(value);

  return ((IOperand *)V);
}

IOperand *	Factory::createInt32(const std::string& value)
{
  Int32 * V = new(Int32)(value);

  return ((IOperand *)V);
}

IOperand *	Factory::createFloat(const std::string& value)
{
  Float * V = new(Float)(value);

  return ((IOperand *)V);
}

IOperand *	Factory::createDouble(const std::string& value)
{
  Double * V = new(Double)(value);

  return ((IOperand *)V);  
}

IOperand *	Factory::createBigDecimal(const std::string& value)
{
  BigDecimal * V = new(BigDecimal)(value);

  return ((IOperand *)V);
}

IOperand *	Factory::createOperand(eOperandType type, const std::string& value)
{
  Factory	tmp;
  static std::map<eOperandType, func> map;
  std::string	v;

  v = value;
  if (type == -1)
    {
      type = INT8;
      v = "1";
    }
  map[INT8] = &Factory::createInt8;
  map[INT16] = &Factory::createInt16;
  map[INT32] = &Factory::createInt32;
  map[FLOAT] = &Factory::createFloat;
  map[DOUBLE] = &Factory::createDouble;
  map[BIGDECIMAL] = &Factory::createBigDecimal;
  return ((tmp.*map[type])(v));
}
