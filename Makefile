CC = gcc
CXX = g++

CXXFLAGS = -c -g -Wall -Wextra -pedantic
CCFLAGS = -c
LDFLAGS = 

CPP_SRC = \
	main.cpp \
	iohelper.cpp

CPP_SRC_OBJS = $(CPP_SRC:.cpp=.o)

CC_SRC = 
CC_SRC_OBJS = $(CC_SRC:.c=.o)

EXECUTABLE = main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(CPP_SRC_OBJS) $(CC_SRC_OBJS)
	$(CXX) $(CPP_SRC_OBJS) $(CC_SRC_OBJS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

.c.o:
	$(CC) $(CCFLAGS) $< -o $@


clean:
		rm -rf $(CPP_SRC_OBJS) $(CC_SRC_OBJS) $(EXECUTABLE)
