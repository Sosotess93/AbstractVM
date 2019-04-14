//
// IOpreand.hpp for h in /home/elsamr_a/rendu/synthèse/abstractVM_2016
// 
// Made by Antoine El Samra
// Login   <elsamr_a@epitech.net>
// 
// Started on  Fri Jul 21 15:42:26 2017 Antoine El Samra
// Last update Sun Jul 23 17:08:15 2017 Antoine El Samra
//

#ifndef IOPERAND_HPP_
# define IOPERAND_HPP_

# include <string>

# define COMMAND "comments", "pop", "clear", "dup", "swap", "dump", "swap", "dump", "add", "sub", "mul", "div", "mod", "print", "exit"

# define COMMANDV "push", "assert", "load", "store"

# define TYPE "int8", "int16", "int32", "float", "double", "bigdecimal"

enum eOperandType
  {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE,
    BIGDECIMAL,
    DEFAULT
  };

class IOperand
{
public:
  virtual std::string toString() const = 0; // string that represents the instance
  virtual eOperandType getType() const = 0; // returns the type of instance

  virtual IOperand*	operator+(const IOperand &rhs) const = 0; //sum
  virtual IOperand*	operator-(const IOperand &rhs) const = 0; //difference
  virtual IOperand*	operator*(const IOperand &rhs) const = 0; //product
  virtual IOperand*	operator/(const IOperand &rhs) const = 0; //quotient
  virtual IOperand*	operator%(const IOperand &rhs) const = 0; //modulo

  virtual	~IOperand() {};
};

int     search_arg(std::string line, std::string command);
int	verif_command(std::string str);

#endif /* !IOPERAND_HPP_ */
