//
// Exception.hpp for  in /home/sofiane/Documents/abstractVM_2016/includes
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Fri Jul 21 19:00:24 2017 sofiane
// Last update Fri Jul 21 19:37:13 2017 sofiane
//

#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

typedef std::string String;

class	Exception : public std::exception
{
protected:
  std::string	_error;

public:
  Exception(String const &error) throw();
  virtual ~Exception(void) throw();
  virtual const char *what(void) const throw();
};

#endif /* !EXCEPTION_HPP */
