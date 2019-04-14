//
// command.cpp for command in /home/diallo_n/alassane/abstractVM_2016/sources/parsing
//
// Made by mamadou diallo
// Login   <diallo_n@epitech.net>
//
// Started on  Sun Jul 23 14:18:56 2017 mamadou diallo
// Last update Wed Jul 26 16:39:58 2017 sofiane
//

#include "IOperand.hpp"
#include "Parsing.hpp"
#include "Command.hpp"

Command::Command()
{
  line = "";
  command = "";
  value = "";
  type = -1;
}

Command::~Command()
{
}

std::string	Command::getLine()
{
  return (line);
}

std::string	Command::getCommand()
{
  return (command);
}

std::string	Command::getValue()
{
  return (value);
}

int		Command::getType()
{
  return (type);
}

void		Command::setLine(std::string str)
{
  line += str;
}

void		Command::setCommand(std::string str)
{
  command += str;
}

int		Command::setVal()
{
  int   i;
  int	a;
  int	b;
  int	nb;

  i = 0;
  a = 0;
  nb = 0;
  b = 0;
  while (verif_char(line[i]) == 0)
    i++;
  while (verif_char(line[i]) == -1)
    i++;
  while (line[i] != '(' && line[i] != '\0')
    i++;
  i++;
  while (line[i] != ')' && line[i] != '\0')
    {
      if (a == 0 && line[i] == '-')
	{
	  value += line[i];
	  i++;
	  a++;
	}
      if (line[i] == '.')
	{
	  if (verif_num(line[i + 1]) == 0 && verif_num(line[i - 1]) == 0 && nb == 0)
	    nb++;
	  else
	    return (-1);
	}
      else if (verif_num(line[i]) ==  -1)
	return (-1);
      value += line[i];
      i++;
      b++;
    }
  if (line[i] != ')' || b == 0)
    return (-1);
  else if (line[i + 1] != '\0')
    return (-1);
  return (0);
}

int             Command::compareType(std::string str)
{
  std::string   type[6] = {TYPE};
  int           i;

  i = 0;
  while (i != 6)
    {
      if (str == type[i])
	return (i);
      i++;
    }
  return (-1);
}

void             Command::setType()
{
  std::string   t;
  int   i;

  i = 0;
  while (verif_char(line[i]) == 0)
    i++;
  while (verif_char(line[i]) == -1)
    i++;
  while (line[i] != '(' && line[i] != '\0')
    {
      t += line[i];
      i++;
    }
  if (line[i] != '(')
    type = -1;
  else
    type = compareType(t);
}
