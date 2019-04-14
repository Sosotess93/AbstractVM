//
// main.cpp for main in /home/elsamr_a/rendu/synthèse/abstractVM_2016/sources
// 
// Made by Antoine El Samra
// Login   <elsamr_a@epitech.net>
// 
// Started on  Sun Jul 23 17:03:12 2017 Antoine El Samra
// Last update Sun Jul 23 17:11:18 2017 Antoine El Samra
//

#include "Parsing.hpp"
#include "Exception.hpp"

int	main(int ac, char **av)
{
  Parsing	parseur;
  
  try
    {
      if (ac < 3)
	parseur.absFile(av);
      else
	throw(Exception("Invalid argument"));
    }
  catch (Exception const &e)
    {
      std::cerr << e.what() << std::endl;
      return (84);
    }
  return (0);
}
