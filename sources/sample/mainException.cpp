//
// main.cpp for  in /home/sofiane/Documents/abstractVM_2016/sources
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Fri Jul 21 17:45:24 2017 sofiane
// Last update Fri Jul 21 19:47:03 2017 sofiane
//

#include "Exception.hpp"

int	division(int a, int b)
{
  if (b == 0)
    throw (Exception("Erreur division par zéro")); //Message
  else
    return (a / b);
}

int	main()
{
  int	a;
  int	b;

  std::cout << "Valeur pour a : ";
  std::cin >> a;
  std::cout << "Valeur pour b : ";
  std::cin >> b;
  try
    {
      std::cout << a << " / " << b << " = " << division(a,b) << std::endl;
    }
  catch (Exception const& e)
    {
      std::cerr << "Erreur : " << e.what() << std::endl; //La fonction what sert à afficher le message d'erreur que vous mettez avec le throw(Exception("MSG")):
    }
  return (0);
}
