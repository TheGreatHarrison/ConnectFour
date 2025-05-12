 Makefile for Connect 4

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g  # Use C++11, enable all warnings, include debug symbols

# Source and header files
SRCDIR = src
INCDIR = include
BUILDDIR = build
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/Board.cpp $(SRCDIR)/Game.cpp
HEADERS = $(INCDIR)/Board.h $(INCDIR)/Game.h
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)  #  Important:  Object files in build/
TARGET = ConnectFour

# Default target
all: $(BUILDDIR)/$(TARGET)

# Create the build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Compile object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h | $(BUILDDIR) #Dependency on .h and build dir
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the object files to create the executable
$(BUILDDIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Clean target to remove object files and the executable
clean:
	rm -rf $(BUILDDIR)/*

# Phony targets (not actual files)
.PHONY: all clean
