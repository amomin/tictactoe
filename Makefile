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

# Can put this in a script to run if it were complicated
etags:
	find . -type f -regex '.*.\(h\|cpp\)' | etags -

.PHONY: clean
clean:
	rm obj/*
	rm bin/*
