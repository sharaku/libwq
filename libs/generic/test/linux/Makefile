# Makefile

.PHONY: all clean

CC       =g++
CFLAGS   =-Wall -ansi -pedantic -g
TARGET   =libwq.generic-unittest

SRC      =gtest_list.cpp
SRC      +=gtest_plist.cpp
SRC      +=gtest_slab.cpp
SRC      +=gtest_hashtable.cpp

HEADERS  =
INCLUDES =-I/usr/local/include/ -I../../../../include/
LDFLAGS  =-L/usr/local/lib/ -L../../
LIBS     =-pthread -lgtest -lgtest_main -lwq.generic.linux.x86

all: $(TARGET) test

$(TARGET): $(SRC) $(HEADERS) Makefile
	$(CC) -o $@ $(CFLAGS) $(SRC) $(INCLUDES) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)

test: $(TARGET)
	./$(TARGET) --gtest_output=xml:gtest_result.generic.linux-x86.xml
