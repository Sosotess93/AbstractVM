##
## Makefile for  in /home/sofiane/Documents/abstractVM_2016
## 
## Made by sofiane
## Login   <sofiane@epitech.net>
## 
## Started on  Fri Jul 21 17:30:15 2017 sofiane
## Last update Mon Jul 24 02:10:38 2017 sofiane
##

SOURCES	=	sources/
TYPES	=	sources/Types/
PARSING =	sources/Parsing/

NAME	=	abstractVM

SRC	=	$(SOURCES)main.cpp \
		$(SOURCES)Instruction.cpp \
		$(SOURCES)Factory.cpp \
		$(SOURCES)Exception.cpp \
		$(SOURCES)fonctions_ptr.cpp \
		$(TYPES)BigDecimal.cpp \
		$(TYPES)Double.cpp \
		$(TYPES)Float.cpp \
		$(TYPES)Int16.cpp \
		$(TYPES)Int32.cpp \
		$(TYPES)Int8.cpp \
		$(PARSING)Verif.cpp \
		$(PARSING)Command.cpp \
		$(PARSING)Parsing.cpp \

RM	=	rm -rf

OBJ	=	$(SRC:.cpp=.o)

INCLUDE	=	-I./includes/

CPPFLAGS =	-I./includes -std=c++11 -Wall -Werror

CC	=	g++

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(INCLUDE) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
