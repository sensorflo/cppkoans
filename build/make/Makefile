# directory containing gtest include folder
GTEST_INC_DIR = /usr/include
# directory containing gtest's library (libgtest.a)
GTEST_LIB_DIR = /usr/lib

CPPFLAGS += 
CXXFLAGS += -g -Wall -Wextra
INC_DIR = ../../src
SRC_DIR = ../../src
INCLUDES = ${INC_DIR}/cppkoans.h ${INC_DIR}/koangtestprinter.h


all: cppkoans run

.PHONY: clean

clean:
	rm -f cppkoans *.o

cppkoans.o: $(SRC_DIR)/cppkoans.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/cppkoans.cpp

koangtestprinter.o: $(SRC_DIR)/koangtestprinter.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koangtestprinter.cpp

pathtoenlightenment.o: $(SRC_DIR)/koans/pathtoenlightenment.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koans/pathtoenlightenment.cpp


asserts.o: $(SRC_DIR)/koans/asserts.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koans/asserts.cpp
arrays.o: $(SRC_DIR)/koans/arrays.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koans/arrays.cpp
strings.o: $(SRC_DIR)/koans/strings.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koans/strings.cpp

# It is important that pathtoenlightenment.o comes before the list of the koan
# .o's, see comment in pathtoenlightenment.cpp
cppkoans: cppkoans.o koangtestprinter.o pathtoenlightenment.o asserts.o arrays.o strings.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -pthread ${GTEST_LIB_DIR}/libgtest.a  -o $@

run:
	@echo "make: autorun of cppkoans:"
	@./cppkoans