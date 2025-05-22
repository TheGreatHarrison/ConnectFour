# Makefile for Connect 4

# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -g -I$(INCDIR)

# Source and header files
SRCDIR = src
INCDIR = inc
BUILDDIR = build
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/Board.cpp $(SRCDIR)/Game.cpp $(SRCDIR)/ConnectFour.cpp
HEADERS = $(INCDIR)/Board.h $(INCDIR)/Game.h $(INCDIR)/ConnectFour.h
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)  #  Important:  Object files in build/
TARGET = ConnectFour

# Default target
all: $(BUILDDIR)/$(TARGET)

# Create the build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Compile object files
$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/Game.h | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/Board.o: $(SRCDIR)/Board.cpp $(INCDIR)/Board.h | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/Game.o: $(SRCDIR)/Game.cpp $(INCDIR)/Game.h | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/ConnectFour.o: $(SRCDIR)/ConnectFour.cpp $(INCDIR)/ConnectFour.h | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the object files to create the executable
$(BUILDDIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Clean target to remove object files and the executable
clean:
	rm -rf $(BUILDDIR)/*

info:
	$(CXX) --version
	
# Phony targets (not actual files)
.PHONY: all clean