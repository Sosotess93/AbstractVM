//
// main.cpp for main in /home/diallo_n/alassane/abstractVM_2016
// 
// Made by mamadou diallo
// Login   <diallo_n@epitech.net>
// 
// Started on  Fri Jul 21 15:24:06 2017 mamadou diallo
// Last update Wed Jul 26 12:00:58 2017 mamadou diallo
//

#include <iostream>
#include <fstream>
#include <vector>

#include "IOperand.hpp"
#include "Exception.hpp"
#include "Parsing.hpp"
#include "Command.hpp"

Parsing::Parsing()
{
  nb = 0;
}

Parsing::~Parsing()
{
}

void		Parsing::setCommand(char c)
{
  command += c;
}

std::vector<Command>	Parsing::getVector()
{
  return (vec);
}

std::string     Parsing::transform(std::string av)
{
  std::string   new_str;
  int           i;
  int           a;

  i = 0;
  while (av[i] != '\0' && av[i] != ';')
    {
      a = i;
      if (av[a] == ' ')
	{
	  while (av[a] == ' ')
	    a++;
	  if (av[a] == ';')
	    return (new_str);
	}
      new_str += av[i];
      i++;
    }
  return (new_str);
}

int		Parsing::verifCommand()
{
  std::string	command1[15] = {COMMAND};
  std::string	command2[4] = {COMMANDV};
  int		i;
  int		v;
  int		nb;

  i = 0;
  v = 0;
  nb = 0;
  if (command == ";")
    return (3);
  while (i != 15)
    {
      if (command1[i] == command)
	nb = 1;
      else if (v < 4)
	{
	  if (command2[v] == command)
	    nb = 2;
	  v++;
	}
      i++;
    }
  if (nb == 0)
    throw(Exception("Invalid command"));
  return (nb);
}

int		Parsing::parsing()
{
  int		a;
  int		i;

  a = 0;
  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] != ' ' && line[i] != '\t')
	{
	  while (line[i] != ' ' && line[i] != '\0' && line[i] != '\t')
	    {
	      setCommand(line[i]);
	      i++;
	    }
	  if (a == 0)
	    if (verifCommand() != 84)
	      searchArg();
	  command.clear();
	  a++;
	}
      while ((line[i] == ' ' || line[i] == '\t'))
      	i++;
    }
  return (0);
}

int             Parsing::searchArg()
{
  Command       com;

  com.setLine(line);
  com.setCommand(command);
  if (command == ";")
    return (0);
  else
    {
      if (verifCommand() == nbr_of_word(line))
	{
	  if (nbr_of_word(line) == 2)
	    {
	      com.setType();
	      if (com.getType() == -1)
		throw(Exception("Invalid value"));
	      if (com.setVal() == -1)
		throw(Exception("Invalid value"));
	    }
	  nb = 1;
	  vec.push_back(com);
	}
      else
	throw(Exception("Bad number of arguments"));
    }
  return (0);
}

int		Parsing::absFile(char **av)
{
  std::ifstream	flux;
  int		continuer = 1;

  if (av[1] != NULL)
    {
      flux.open(av[1], std::ios::in);
      if (!flux.is_open())
	throw (Exception("Invalid file"));
    }
  while (continuer)
    {
      if (!flux.is_open())
	{
	  std::getline(std::cin, line, '\n');
	  if (std::cin.eof() == 1)
	    throw(Exception("Error input"));
	  if (line != ";;" )
	    {
	      line = transform(epur_str(line));
	      parsing();
	    }
	  else
	    continuer = 0;
	}
      else if (std::getline(flux, line, '\n'))
	{
	  line = transform(epur_str(line));
	  parsing();
	}
      else
	continuer = 0;
    }
  if (nb == 0)
    throw(Exception("Any command"));
  loop(vec);
  return (0);
}
