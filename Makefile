CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBFLAGS= 
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
EXEC= app



all: $(EXEC)


$(EXEC): $(OBJ)
	$(CC) $(LIBFLAGS) $^ -o $@  -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<

.depends:
	g++ -MM $(SRC) > .depends

-include .depends

clean:
	rm -f $(OBJ) $(EXEC) *.*~
