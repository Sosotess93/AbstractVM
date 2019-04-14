//
// Instruction.hpp for  in /home/sofiane/Documents/abstractVM_2016/includes
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Fri Jul 21 23:34:22 2017 sofiane
// Last update Wed Jul 26 23:36:18 2017 sofiane
//

#ifndef INSTRUCTION_H
# define INSTRUCTION_H

#include "Factory.hpp"
#include "Exception.hpp"

class	Instruction : Factory
{
public:
  std::stack<IOperand *>	_pile;
  Instruction();
  virtual ~Instruction();
  void				push(IOperand *);
  void				pop(IOperand *);
  void				dump(IOperand *);
  void				clear(IOperand *);
  void				swap(IOperand *);
  void				dup(IOperand *);
  void				assert(IOperand *);
  void				add(IOperand *);
  void				sub(IOperand *);
  void				mul(IOperand *);
  void				div(IOperand *);
  void				mod(IOperand *);
  void				load(IOperand *);
  void				store(IOperand *);
  void				print(IOperand *);
  void				exit(IOperand *);
};

#endif /* !INSTRUCTION_H */
