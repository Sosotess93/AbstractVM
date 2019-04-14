//
// Types.hpp for y in /home/elsamr_a/rendu/synthèse/abstractVM_2016/includes
// 
// Made by Antoine El Samra
// Login   <elsamr_a@epitech.net>
// 
// Started on  Fri Jul 21 17:24:12 2017 Antoine El Samra
// Last update Wed Jul 26 13:09:01 2017 Antoine El Samra
//

#ifndef TYPES_HPP_
# define TYPES_HPP_

# include "IOperand.hpp"
# include "Exception.hpp"
# include <stdexcept>

class		Int8: IOperand
{
protected:
  int8_t	_value;
  std::string	_strValue;
public:
  Int8(const std::string &value);
  ~Int8() {};
  int8_t	getValue() const {return (_value);};
  void		setValue(int8_t v) {_value = v;};
  void		setStrValue(std::string v) {_strValue = v;};

  std::string	toString() const {return (_strValue);};
  eOperandType	getType() const {return ((eOperandType)(INT8));};

  IOperand*	operator+(const IOperand &rhs) const;
  IOperand*	operator-(const IOperand &rhs) const;
  IOperand*	operator*(const IOperand &rhs) const;
  IOperand*	operator/(const IOperand &rhs) const;
  IOperand*	operator%(const IOperand &rhs) const;
};

class	Int16: IOperand
{
protected:
  int16_t	_value;
  std::string	_strValue;
public:
  Int16(const std::string & value);
  ~Int16() {};
  int16_t	getValue() const {return (_value);};
  void		setValue(int16_t v) {_value = v;};
  void		setStrValue(std::string v) {_strValue = v;};

  std::string	toString() const {return (_strValue);};
  eOperandType	getType() const {return ((eOperandType)(INT16));};

  IOperand*	operator+(const IOperand &rhs) const;
  IOperand*	operator-(const IOperand &rhs) const;
  IOperand*	operator*(const IOperand &rhs) const;
  IOperand*	operator/(const IOperand &rhs) const;
  IOperand*	operator%(const IOperand &rhs) const;
};

class	Int32: IOperand
{
protected:
  int32_t	_value;
  std::string	_strValue;
public:
  Int32(const std::string& value);
  ~Int32() {};
  int32_t	getValue() const {return (_value);};
  void		setValue(int32_t v) {_value = v;};
  void		setStrValue(std::string v) {_strValue = v;};

  std::string	toString() const {return (_strValue);};
  eOperandType	getType() const {return ((eOperandType)(INT32));};

  IOperand*	operator+(const IOperand &rhs) const;
  IOperand*	operator-(const IOperand &rhs) const;
  IOperand*	operator*(const IOperand &rhs) const;
  IOperand*	operator/(const IOperand &rhs) const;
  IOperand*	operator%(const IOperand &rhs) const;
};

class	Float: IOperand
{
protected:
  float		_value;
  std::string	_strValue;
public:
  Float(const std::string &value);
  ~Float() {};
  float		getValue() const {return (_value);};
  void		setValue(float v) {_value = v;};
  void		setStrValue(std::string v) {_strValue = v;};

  std::string	toString() const {return (_strValue);};
  eOperandType	getType() const {return ((eOperandType)(FLOAT));};

  IOperand*	operator+(const IOperand &rhs) const;
  IOperand*	operator-(const IOperand &rhs) const;
  IOperand*	operator*(const IOperand &rhs) const;
  IOperand*	operator/(const IOperand &rhs) const;
  IOperand*	operator%(const IOperand &rhs) const;
};

class	Double: IOperand
{
protected:
  double	_value;
  std::string	_strValue;
public:
  Double(const std::string &value);
  ~Double() {};
  double	getValue() const {return (_value);};
  void		setValue(double v) {_value = v;};
  void		setStrValue(std::string v) {_strValue = v;};

  std::string	toString() const {return (_strValue);};
  eOperandType	getType() const {return ((eOperandType)(DOUBLE));};

  IOperand*	operator+(const IOperand &rhs) const;
  IOperand*	operator-(const IOperand &rhs) const;
  IOperand*	operator*(const IOperand &rhs) const;
  IOperand*	operator/(const IOperand &rhs) const;
  IOperand*	operator%(const IOperand &rhs) const;
};

class	BigDecimal: IOperand
{
protected:
  long double	_value;
  std::string	_strValue;
public:
  BigDecimal(const std::string &value);
  ~BigDecimal() {};
  long double	getValue() const {return (_value);};
  void		setValue(long double v) {_value = v;};
  void		setStrValue(std::string v) {_strValue = v;};

  std::string	toString() const {return (_strValue);};
  eOperandType	getType() const {return ((eOperandType)(BIGDECIMAL));};

  IOperand*	operator+(const IOperand &rhs) const;
  IOperand*	operator-(const IOperand &rhs) const;
  IOperand*	operator*(const IOperand &rhs) const;
  IOperand*	operator/(const IOperand &rhs) const;
  IOperand*	operator%(const IOperand &rhs) const;
};

#endif /* !TYPES_HPP_ */
