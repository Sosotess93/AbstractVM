//
// verif.cpp for verif in /home/diallo_n/alassane/abstractVM_2016/sources/parsing
// 
// Made by mamadou diallo
// Login   <diallo_n@epitech.net>
// 
// Started on  Sun Jul 23 13:44:03 2017 mamadou diallo
// Last update Wed Jul 26 10:37:00 2017 mamadou diallo
//

#include <iostream>

std::string    epur_str(std::string str)
{
  std::string  new_str;
  int   i;
  int   j;

  j = 0;
  i = 0;
  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' || str[i] != '\t')
	{
	  new_str += str[i];
	  j++;
	}
      else if ((str[i] == ' ' || str[i] == '\t') &&
	       (str[i + 1] != ' ' || str[i + 1] != '\t'))
	{
	  new_str += ' ';
	  j++;
	}
      i++;
    }
  return (new_str);
}


int     verif_num(char c)
{
  if (c >= '0' && c <= '9')
    return (0);
  else
    return (-1);
}

int     verif_char(char c)
{
  if (c == ';')
    return (1);
  if (c != ' ' && c != '\n' &&
      c != '\t' && c != '\0' &&
      c > 32)
    return (0);
  else
    return (-1);
}

int     nbr_of_word(std::string &str)
{
  int   i;
  int   a;

  i = 0;
  a = 0;
  while (str[i] != '\0')
    {
      if (verif_char(str[i]) == 1)
	{
	  str[i] = '\0';
	  i--;
	  while (str[i] == ' ')
	    {
	      str[i] = '\0';
	      i--;
	    }
	}
      if (verif_char(str[i]) == 0)
	{
	  a = a + 1;
	  while (verif_char(str[i]) == 0)
	    i = i + 1;
	}
      else if (str[i] != '\0')
	i = i + 1;
    }
  return (a);
}
