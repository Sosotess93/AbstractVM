//
// Command.hpp for Command in /home/diallo_n/alassane/abstractVM_2016/sources/parsing
// 
// Made by mamadou diallo
// Login   <diallo_n@epitech.net>
// 
// Started on  Sun Jul 23 15:08:42 2017 mamadou diallo
// Last update Sun Jul 23 15:09:49 2017 mamadou diallo
//

#ifndef COMMAND_HPP__
#define COMMAND_HPP__

#include <vector>
#include <iostream>

class           Command
{
  std::string   line;
  std::string   command;
  std::string   value;
  int           type;

public:
  Command();
  ~Command();
  std::string   getLine();
  std::string   getCommand();
  std::string   getValue();
  int           getType();

  void          setLine(std::string str);
  void          setCommand(std::string str);
  void          setType();
  int           setVal();

  int           compareType(std::string str);
};

#endif
