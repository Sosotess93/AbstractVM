//
// fonctions_ptr.cpp for  in /home/elsamr_a/rendu/synthèse/abstractVM_2016/sources
//
// Made by Antoine El Samra
// Login   <elsamr_a@epitech.net>
//
// Started on  Sun Jul 23 16:10:14 2017 Antoine El Samra
// Last update Wed Jul 26 14:30:27 2017 Antoine El Samra
//

#include "Instruction.hpp"
#include "Exception.hpp"
#include "Command.hpp"

typedef void(Instruction::*fonc)(IOperand *);

std::map<std::string, fonc>	 init_map()
{
  std::map<std::string, fonc> map;

  map["push"] = &Instruction::push;
  map["pop"] = &Instruction::pop;
  map["clear"] = &Instruction::clear;
  map["dup"] = &Instruction::dup;
  map["swap"] = &Instruction::swap;
  map["dump"] = &Instruction::dump;
  map["assert"] = &Instruction::assert;
  map["add"] = &Instruction::add;
  map["sub"] = &Instruction::sub;
  map["mul"] = &Instruction::mul;
  map["div"] = &Instruction::div;
  map["mod"] = &Instruction::mod;
  map["load"] = &Instruction::load;
  map["store"] = &Instruction::store;
  map["print"] = &Instruction::print;
  map["exit"] = &Instruction::exit;
  return (map);
}

int	loop(std::vector<Command> v)
{
  Instruction	I;
  Factory	F;
  unsigned int	i;

  std::map<std::string, fonc> map = init_map();

  for (i = 0; i < v.size(); i++)
    {
      if (v[i].getCommand() == "exit")
	break;
      (I.*map[v[i].getCommand()])(F.createOperand((eOperandType)v[i].getType(), v[i].getValue()));
    }
  if (i == v.size())
    throw(Exception("Exit command not found"));
  return (0);
}
