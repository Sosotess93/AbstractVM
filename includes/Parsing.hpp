//
// Parsing.hpp for Parsing in /home/diallo_n/alassane/abstractVM_2016/sources/parsing
// 
// Made by mamadou diallo
// Login   <diallo_n@epitech.net>
// 
// Started on  Sun Jul 23 13:14:18 2017 mamadou diallo
// Last update Wed Jul 26 11:55:29 2017 mamadou diallo
//

#ifndef PARSING_HPP__
#define PARSINg_HPP__

#include <iostream>
#include <vector>

#include "Command.hpp"

class			Parsing
{
  std::string		line;
  std::string		command;
  std::vector<Command>	vec;
  int			nb;
  
public:
			Parsing();
  virtual		~Parsing();
  
  int			compareType(std::string str);
  int			searchArg();
  int			absFile(char **av);
  int			parsing();
  int			verifCommand();
  std::string		transform(std::string av);
  std::vector<Command>	getVector();
  
  void			setCommand(char c);  
};

std::string	epur_str(std::string str);
int		verif_num(char c);
int		verif_char(char c);
int		nbr_of_word(std::string &str);
int		loop(std::vector<Command> v);

#endif
