#Author: Justin Tromp
#01/10/2019
#.PHONY and code below that point in this makefile is referenced through:
#Title: makefile
#Author: Harlan James (TA at OSU)
#Date: 01/10/2019
#Code Version:
#Availability: Oregon State University (Canvas)

#Project name
PROJECT = Project_2

#Compiler
#C=g++                                  #Use for C
CXX=g++

#Options to be passed/compiler flags
#CFLAGS=-pedantic -std=gnu++11 -Wall    #Use for C
LDFLAGS=-lboost_date_time
CXXFLAGS=-pedantic
CXXFLAGS+=-std=gnu++11
CXXFLAGS+=-Wall
#CXXFLAGS+=-03

#Source files
SOURCES=main.cpp Animal.cpp InputValidation.cpp Penguin.cpp Tiger.cpp Turtle.cpp UserAnimal.cpp Zoo.cpp

#Header files
HEADERS=Animal.hpp InputValidation.hpp Penguin.hpp Tiger.hpp Turtle.hpp UserAnimal.hpp Zoo.hpp

#Objects
OBJECTS=$(SOURCES:.cpp=.o)

#Output Binary
BINARY=$(PROJECT).bin

#Valgrind Options
VALGRIND= --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes

#Executable name
EXECUTABLE=Project_2


.PHONY: default debug clean zip

default: clean $(BINARY) debug


debug: $(BINARY)
	@valgrind $(VALGRIND) ./$(BINARY)

$(BINARY): $(OBJECTS)
	@echo "CXX	$@"
	@$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	@echo "CXX	$^"
	@$(CXX) $(CXXFLAGS) -c $^

zip:
	zip $(PROJECT).zip *.cpp *.hpp makefile *.pdf *.txt

clean: $(CLEAN)
	@echo "RM	*.o"
	@echo "RM	$(BINARY)"
	@rm -f *.o $(BINARY)