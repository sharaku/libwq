# Makefile

.PHONY: all clean

CC       =g++
CFLAGS   =-Wall -ansi -pedantic -g -Wno-variadic-macros
TARGET   =libwq.pid-unittest

SRC      =gtest_pid.cpp

HEADERS  =
INCLUDES =-I/usr/local/include/ -I../../../../include/
LDFLAGS  =-L/usr/local/lib/ -L../../
LIBS     =-pthread -lgtest -lgtest_main

all: $(TARGET) test

$(TARGET): $(SRC) $(HEADERS) Makefile
	$(CC) -o $@ $(CFLAGS) $(SRC) $(INCLUDES) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)

test: $(TARGET)
	./$(TARGET) --gtest_output=xml:gtest_result.pid.linux-x86.xml
