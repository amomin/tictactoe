TARGET = tictactoe

COMPILER=g++ -std=c++11 -g

OBJDIR=obj
SRCDIR=src
INCDIR=inc
BINDIR=bin

SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

VPATH = $(SRCDIR) $(INCDIR)

default: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJ)
	$(COMPILER) -o $@ $^

$(OBJ): $(OBJDIR)/%.o : %.cpp
	$(COMPILER) -c $< -o $@ -I $(INCDIR)


.PHONY: clean
clean:
	rm bin/*
	rm obj/*
