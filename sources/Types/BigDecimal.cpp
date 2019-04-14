//
// BigDecimal.cpp for t in /home/elsamr_a/rendu/synthèse/abstractVM_2016/sources/Types
// 
// Made by Antoine El Samra
// Login   <elsamr_a@epitech.net>
// 
// Started on  Sun Jul 23 15:23:05 2017 Antoine El Samra
// Last update Wed Jul 26 13:11:11 2017 Antoine El Samra
//

#include "Types.hpp"
#include <sstream>

BigDecimal::BigDecimal(const std::string &value)
{
  try {
    std::stold(value);
  }
  catch (const std::out_of_range &orr) {
    throw(Exception("Invalide value"));
  }
  _strValue = value;
  _value = std::stold(value);
}

IOperand *	BigDecimal::operator+(const IOperand &rhs) const
{
  std::string	strNb = rhs.toString();
  BigDecimal *	N = new(BigDecimal)(this->_strValue);
  try {
    std::stold(strNb);
  }
  catch (const std::out_of_range &orr) {
    throw(Exception("Invalide value"));
  }
  N->setValue(this->_value + std::stold(strNb));
  std::ostringstream sss;
  sss << N->getValue();
  N->setStrValue(sss.str());
  return ((IOperand *)N);
}

IOperand *	BigDecimal::operator-(const IOperand &rhs) const
{
  std::string	strNb = rhs.toString();
  BigDecimal *	N = new(BigDecimal)(this->_strValue);
  try {
    std::stold(strNb);
  }
  catch (const std::out_of_range &orr) {
    throw(Exception("Invalide value"));
  }
  N->setValue(this->_value - std::stold(strNb));
  std::ostringstream sss;
  sss << N->getValue();
  N->setStrValue(sss.str());
  return ((IOperand *)N);
}

IOperand *	BigDecimal::operator*(const IOperand &rhs) const
{
  std::string	strNb = rhs.toString();
  BigDecimal *	N = new(BigDecimal)(this->_strValue);
  try {
    std::stold(strNb);
  }
  catch (const std::out_of_range &orr) {
    throw(Exception("Invalide value"));
  }
  N->setValue(this->_value * std::stold(strNb));
  std::ostringstream sss;
  sss << N->getValue();
  N->setStrValue(sss.str());
  return ((IOperand *)N);
}

IOperand *	BigDecimal::operator/(const IOperand &rhs) const
{
  std::string	strNb = rhs.toString();
  BigDecimal *	N = new(BigDecimal)(this->_strValue);
  try {
    std::stold(strNb);
  }
  catch (const std::out_of_range &orr) {
    throw(Exception("Invalide value"));
  }
  N->setValue(this->_value / std::stold(strNb));
  std::ostringstream sss;
  sss << N->getValue();
  N->setStrValue(sss.str());
  return ((IOperand *)N);
}

IOperand *	BigDecimal::operator%(const IOperand &rhs) const
{
  throw(Exception("Invalide value"));
  return ((IOperand *)this);
}
