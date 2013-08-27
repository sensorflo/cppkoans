CPPFLAGS += 
CXXFLAGS += -g -Wall -Wextra
INC_DIR = ../../src
SRC_DIR = ../../src

all: cppkoans

clean:
	rm -f cppkoans *.o

cppkoans.o: $(SRC_DIR)/cppkoans.cpp
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) $(CXXFLAGS) -c $(SRC_DIR)/cppkoans.cpp

cppkoans: cppkoans.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@