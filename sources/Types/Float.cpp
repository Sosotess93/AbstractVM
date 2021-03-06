//
// Float.cpp for lol in /home/elsamr_a/rendu/synthèse/abstractVM_2016/sources/Types
//
// Made by Antoine El Samra
// Login   <elsamr_a@epitech.net>
//
// Started on  Sun Jul 23 15:13:01 2017 Antoine El Samra
// Last update Wed Jul 26 12:48:47 2017 Antoine El Samra
//

#include "Types.hpp"
#include <sstream>

Float::Float(const std::string &value)
{
  try {
    std::stof(value);
  }
  catch (const std::out_of_range &orr) {
    throw(Exception("Invalide value"));
  }
  _strValue = value;
  _value = std::stof(value);
}

IOperand *	Float::operator+(const IOperand &rhs) const
{
  std::string	strNb = rhs.toString();
  if (rhs.getType() <= getType())
    {
      Float *	N = new(Float)(this->_strValue);
      try {
	std::stof(strNb);
      }
      catch (const std::out_of_range &orr) {
	throw(Exception("Invalide value"));
      }
      N->setValue(this->_value + std::stof(strNb));
      std::ostringstream sss;
      sss << N->getValue();
      N->setStrValue(sss.str());
      return ((IOperand *)N);
    }
  switch (rhs.getType()) {
  case INT8: {
    Int8	*a = new(Int8)(strNb);
    a->setValue(a->getValue() + (this->_value));
    a->setStrValue(std::to_string(a->getValue()));
    return ((IOperand *)a);
  }
  case INT16: {
    Int16	*b = new(Int16)(strNb);
    b->setValue(b->getValue() + (this->_value));
    b->setStrValue(std::to_string(b->getValue()));
    return ((IOperand *)b);
  }
  case INT32: {
    Int32	*c = new(Int32)(strNb);
    c->setValue(c->getValue() + (this->_value));
    c->setStrValue(std::to_string(c->getValue()));
    return ((IOperand *)c);
  }
  case FLOAT: {
    Float	*d = new(Float)(strNb);
    d->setValue(d->getValue() + (this->_value));
    std::ostringstream ss;
    ss << d->getValue();
    d->setStrValue(ss.str());
    return ((IOperand *)d);
  }
  case DOUBLE: {
    Double	*e = new(Double)(strNb);
    e->setValue(e->getValue() + (this->_value));
    std::ostringstream ss;
    ss << e->getValue();
    e->setStrValue(ss.str());
    e->setStrValue(std::to_string(e->getValue()));
    return ((IOperand *)e);
  }
  case BIGDECIMAL:{
    BigDecimal	*f = new(BigDecimal)(strNb);
    f->setValue(f->getValue() + (this->_value));
    std::ostringstream ss;
    ss << f->getValue();
    f->setStrValue(ss.str());
    f->setStrValue(std::to_string(f->getValue()));
    return ((IOperand *)f);
  }
  default: return ((IOperand *)this);
  }
}

IOperand *	Float::operator-(const IOperand &rhs) const
{
  std::string	strNb = rhs.toString();
  if (rhs.getType() <= getType())
    {
      Float *	N = new(Float)(this->_strValue);
      try {
	std::stof(strNb);
      }
      catch (const std::out_of_range &orr) {
	throw(Exception("Invalide value"));
      }
      N->setValue(this->_value - std::stof(strNb));
      std::ostringstream sss;
      sss << N->getValue();
      N->setStrValue(sss.str());
      return ((IOperand *)N);
    }
  switch (rhs.getType()) {
  case INT8: {
    Int8	*a = new(Int8)(strNb);
    a->setValue((this->_value) - a->getValue());
    a->setStrValue(std::to_string(a->getValue()));
    return ((IOperand *)a);
  }
  case INT16: {
    Int16	*b = new(Int16)(strNb);
    b->setValue((this->_value) - b->getValue());
    b->setStrValue(std::to_string(b->getValue()));
    return ((IOperand *)b);
  }
  case INT32: {
    Int32	*c = new(Int32)(strNb);
    c->setValue((this->_value) - c->getValue());
    c->setStrValue(std::to_string(c->getValue()));
    return ((IOperand *)c);
  }
  case FLOAT: {
    Float	*d = new(Float)(strNb);
    d->setValue((this->_value) - d->getValue());
    std::ostringstream ss;
    ss << d->getValue();
    d->setStrValue(ss.str());
    return ((IOperand *)d);
  }
  case DOUBLE: {
    Double	*e = new(Double)(strNb);
    e->setValue((this->_value) - e->getValue());
    std::ostringstream ss;
    ss << e->getValue();
    e->setStrValue(ss.str());
    e->setStrValue(std::to_string(e->getValue()));
    return ((IOperand *)e);
  }
  case BIGDECIMAL:{
    BigDecimal	*f = new(BigDecimal)(strNb);
    f->setValue((this->_value) - f->getValue());
    std::ostringstream ss;
    ss << f->getValue();
    f->setStrValue(ss.str());
    f->setStrValue(std::to_string(f->getValue()));
    return ((IOperand *)f);
  }
  default: return ((IOperand *)this);
  }
}

IOperand *	Float::operator*(const IOperand &rhs) const
{
  std::string	strNb = rhs.toString();
  if (rhs.getType() <= getType())
    {
      Float *	N = new(Float)(this->_strValue);
      try {
	std::stof(strNb);
      }
      catch (const std::out_of_range &orr) {
	throw(Exception("Invalide value"));
      }
      N->setValue(this->_value * std::stof(strNb));
      std::ostringstream sss;
      sss << N->getValue();
      N->setStrValue(sss.str());
      return ((IOperand *)N);
    }
  switch (rhs.getType()) {
  case INT8: {
    Int8	*a = new(Int8)(strNb);
    a->setValue((this->_value) * a->getValue());
    a->setStrValue(std::to_string(a->getValue()));
    return ((IOperand *)a);
  }
  case INT16: {
    Int16	*b = new(Int16)(strNb);
    b->setValue((this->_value) * b->getValue());
    b->setStrValue(std::to_string(b->getValue()));
    return ((IOperand *)b);
  }
  case INT32: {
    Int32	*c = new(Int32)(strNb);
    c->setValue((this->_value) * c->getValue());
    c->setStrValue(std::to_string(c->getValue()));
    return ((IOperand *)c);
  }
  case FLOAT: {
    Float	*d = new(Float)(strNb);
    d->setValue((this->_value) * d->getValue());
    std::ostringstream ss;
    ss << d->getValue();
    d->setStrValue(ss.str());
    return ((IOperand *)d);
  }
  case DOUBLE: {
    Double	*e = new(Double)(strNb);
    e->setValue((this->_value) * e->getValue());
    std::ostringstream ss;
    ss << e->getValue();
    e->setStrValue(ss.str());
    e->setStrValue(std::to_string(e->getValue()));
    return ((IOperand *)e);
  }
  case BIGDECIMAL:{
    BigDecimal	*f = new(BigDecimal)(strNb);
    f->setValue((this->_value) * f->getValue());
    std::ostringstream ss;
    ss << f->getValue();
    f->setStrValue(ss.str());
    f->setStrValue(std::to_string(f->getValue()));
    return ((IOperand *)f);
  }
  default: return ((IOperand *)this);
  }
}

IOperand *	Float::operator/(const IOperand &rhs) const
{
  std::string	strNb = rhs.toString();
  if (rhs.getType() <= getType())
    {
      Float *	N = new(Float)(this->_strValue);
      try {
	std::stof(strNb);
      }
      catch (const std::out_of_range &orr) {
	throw(Exception("Invalide value"));
      }
      N->setValue(this->_value / std::stof(strNb));
      std::ostringstream sss;
      sss << N->getValue();
      N->setStrValue(sss.str());
      return ((IOperand *)N);
    }
  switch (rhs.getType()) {
  case INT8: {
    Int8	*a = new(Int8)(strNb);
    a->setValue((this->_value) / a->getValue());
    a->setStrValue(std::to_string(a->getValue()));
    return ((IOperand *)a);
  }
  case INT16: {
    Int16	*b = new(Int16)(strNb);
    b->setValue((this->_value) / b->getValue());
    b->setStrValue(std::to_string(b->getValue()));
    return ((IOperand *)b);
  }
  case INT32: {
    Int32	*c = new(Int32)(strNb);
    c->setValue((this->_value) / c->getValue());
    c->setStrValue(std::to_string(c->getValue()));
    return ((IOperand *)c);
  }
  case FLOAT: {
    Float	*d = new(Float)(strNb);
    d->setValue((this->_value) / d->getValue());
    std::ostringstream ss;
    ss << d->getValue();
    d->setStrValue(ss.str());
    return ((IOperand *)d);
  }
  case DOUBLE: {
    Double	*e = new(Double)(strNb);
    e->setValue((this->_value) / e->getValue());
    std::ostringstream ss;
    ss << e->getValue();
    e->setStrValue(ss.str());
    e->setStrValue(std::to_string(e->getValue()));
    return ((IOperand *)e);
  }
  case BIGDECIMAL:{
    BigDecimal	*f = new(BigDecimal)(strNb);
    f->setValue((this->_value) / f->getValue());
    std::ostringstream ss;
    ss << f->getValue();
    f->setStrValue(ss.str());
    f->setStrValue(std::to_string(f->getValue()));
    return ((IOperand *)f);
  }
  default: return ((IOperand *)this);
  }
}

IOperand *	Float::operator%(const IOperand &rhs) const
{
  throw(Exception("Invalide value"));
  return ((IOperand *)this);
}
