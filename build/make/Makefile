# directory containing gtest include folder
GTEST_INC_DIR = /usr/include
# directory containing gtest's library (libgtest.a)
GTEST_LIB_DIR = /usr/lib

CPPFLAGS += 
CXXFLAGS += -g -Wall -Wextra
INC_DIR = ../../src
SRC_DIR = ../../src

all: cppkoans run

.PHONY: clean

clean:
	rm -f cppkoans *.o

cppkoans.o: $(SRC_DIR)/cppkoans.cpp
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/cppkoans.cpp

asserts.o: $(SRC_DIR)/koans/asserts.cpp
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koans/asserts.cpp

cppkoans: cppkoans.o asserts.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -pthread ${GTEST_LIB_DIR}/libgtest.a  -o $@

run:
	./cppkoans