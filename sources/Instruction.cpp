//
// Instruction.cpp for  in /home/sofiane/Documents/abstractVM_2016/sources
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Sat Jul 22 00:42:57 2017 sofiane
// Last update Wed Jul 26 15:53:33 2017 sofiane
//

#include "Instruction.hpp"

Instruction::Instruction()
{
}

Instruction::~Instruction()
{
}

void	Instruction::push(IOperand *pile)
{
  this->_pile.push(pile);
  return;
}

void	Instruction::pop(IOperand *pile)
{
  if (this->_pile.empty())
    throw (Exception("Pop instruction on an empty stack"));
  this->_pile.pop();
  return;
}

void	Instruction::clear(IOperand *pile)
{
  // if (this->_pile.empty())
  //   throw (Exception("Clear instruction on an empty stack"));
  while (!this->_pile.empty())
    {
      this->_pile.pop();
    }
  (void)pile;
    return;
}

void	Instruction::dump(IOperand *pile)
{
  std::stack<IOperand *> print;

  print = this->_pile;
  if (_pile.empty())
    return;//    throw (Exception("Dump instruction on empty stack"));
  while (!print.empty())
    {
      std::cout << print.top()->toString() << std::endl;
      print.pop();
    }
  (void)pile;
  return;
}

void	Instruction::swap(IOperand *pile)
{
  IOperand *tmp;
  IOperand *tmp2;

  if (this->_pile.size() < 2)
    throw (Exception("the stack strictly has less than two values during the execution of an arithmetical instruction."));
  else
    {
      tmp = this->_pile.top();
      this->_pile.pop();
      tmp2 = this->_pile.top();
      this->_pile.pop();
      this->_pile.push(tmp);
      this->_pile.push(tmp2);
    }
  (void)pile;
  return;
}

void	Instruction::dup(IOperand *pile)
{
  IOperand *tmp;

  if (this->_pile.size() < 1)
    throw (Exception("the stack strictly has less than two values during the execution of an arithmetical instruction."));
  else
    {
      tmp = this->_pile.top();
      this->_pile.push(tmp);
    }
  (void)pile;
  return;
}

void	Instruction::assert(IOperand *pile)
{
  std::stack<IOperand *> print;
  print = this->_pile;
  if (!this->_pile.empty())
    {
      if (print.top()->toString() != pile->toString() || print.top()->getType() != pile->getType())
	throw (Exception("an assert instruction is not verified"));
    }
  else
    throw (Exception("Dump instruction on empty stack"));
  return;
}

void	Instruction::add(IOperand *pile)
{
  (void)pile;
  IOperand	*add1;
  IOperand	*add2;

  if (_pile.size() < 2)
    throw (Exception("Add on stack with less than two values"));
  if (!this->_pile.empty())
    {
      add1 = this->_pile.top();
      this->_pile.pop();
      add2 = this->_pile.top();
      this->_pile.pop();
      IOperand *r = *add1 + *add2;
      this->_pile.push(r);
    }
  // else
  //   throw (Exception("the stack strictly has less than two values during the execution of an arithmetical instruction."));
  return;
}

void	Instruction::sub(IOperand *pile)
{
  (void)pile;
  IOperand	*add1;
  IOperand	*add2;

  if (_pile.size() < 2)
    throw (Exception("Add on stack with less than two values"));
  if (!this->_pile.empty())
    {
      add1 = this->_pile.top();
      //      std::cout << add1->toString() << std::endl;
      this->_pile.pop();
      add2 = this->_pile.top();
      // std::cout << add2->toString() << std::endl;
      this->_pile.pop();
      IOperand *r = (*add2) - (*add1);
      //std::cout << r->toString() << std::endl;
      this->_pile.push(r);
    }
  return;
}

void	Instruction::mul(IOperand *pile)
{
  (void)pile;
  IOperand	*add1;
  IOperand	*add2;

  if (_pile.size() < 2)
    throw (Exception("Add on stack with less than two values"));
  if (!this->_pile.empty())
    {
      add1 = this->_pile.top();
      //      std::cout << add1->toString() << std::endl;
      this->_pile.pop();
      add2 = this->_pile.top();
      //std::cout << add2->toString() << std::endl;
      this->_pile.pop();
      IOperand *r = (*add1) * (*add2);
      //std::cout << r->toString() << std::endl;
      this->_pile.push(r);
    }
  return;
}

void	Instruction::div(IOperand *pile)
{
  (void)pile;
  IOperand      *add1;
  IOperand      *add2;

  if (_pile.size() < 2)
    throw (Exception("Div on stack with less than two values"));
  if (!this->_pile.empty())
    {
      add1 = this->_pile.top();
      this->_pile.pop();
      add2 = this->_pile.top();
      this->_pile.pop();
      if (add1->toString() != "0")
	{
	  //	  std::cout << "Je divise par : " << add1->toString() << std::endl;
	  IOperand *r = *add2 / *add1;
	  this->_pile.push(r);
	}
	else
	  throw(Exception("Division by 0."));
    }
    return;
}

void	Instruction::mod(IOperand *pile)
{
  (void)pile;
  IOperand      *add1;
  IOperand      *add2;

  if (_pile.size() < 2)
    throw (Exception("Div on stack with less than two values"));
  if (!this->_pile.empty())
    {
      add1 = this->_pile.top();
      this->_pile.pop();
      add2 = this->_pile.top();
      this->_pile.pop();
      if (add1->toString() == "0")
	throw(Exception("Modulo by 0."));
      else
	{
	  //	  std::cout << "Je divise par : " << add1->toString() << std::endl;
	  IOperand *r = *add2 % *add1;
	  this->_pile.push(r);
	}
    }
  return;
}

void	Instruction::load(IOperand *pile)
{
  (void)pile;
  return;
}

void	Instruction::store(IOperand *pile)
{
  if (this->_pile.empty())
    throw (Exception("Store instruction on an empty stack"));
  this->_pile.pop();
  return;
}

void	Instruction::print(IOperand *pile)
{
  std::string str;

  if (this->_pile.empty())
    throw (Exception("Print instruction on an empty stack"));
  else
    {
      if (this->_pile.top()->getType() == INT8)
	{
	  str =  std::stoi(_pile.top()->toString());
	  std::cout << str << std::endl;
	}
      else
	{
	  throw (Exception("Error : The type is not a INT8"));
	}
    }
  return;
}

void	Instruction::exit(IOperand *pile)
{
  (void)pile;
  return;
}
