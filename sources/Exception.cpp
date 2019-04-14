//
// Exception.cpp for  in /home/sofiane/Documents/abstractVM_2016
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Fri Jul 21 19:11:34 2017 sofiane
// Last update Fri Jul 21 19:41:28 2017 sofiane
//

#include "Exception.hpp"

Exception::Exception(String const &error) throw()
{
  this->_error = error;
}

Exception::~Exception() throw()
{
}

const char	*Exception::what() const throw()
{
  return (this->_error.c_str());
}
