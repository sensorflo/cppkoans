GTEST_DIR = ../../gtest
INC_DIR = ../../src
SRC_DIR = ../../src
INCLUDES = ${INC_DIR}/cppkoans.h ${INC_DIR}/koangtestprinter.h
# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread


all: cppkoans run

.PHONY: clean

clean:
	rm -f cppkoans *.o gtest.a


# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

cppkoans.o: $(SRC_DIR)/cppkoans.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/cppkoans.cpp

koangtestprinter.o: $(SRC_DIR)/koangtestprinter.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koangtestprinter.cpp

pathtoenlightenment.o: $(SRC_DIR)/pathtoenlightenment.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/pathtoenlightenment.cpp


introduction.o: $(SRC_DIR)/koans/introduction.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koans/introduction.cpp
booleans.o: $(SRC_DIR)/koans/booleans.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koans/booleans.cpp
characters.o: $(SRC_DIR)/koans/characters.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koans/characters.cpp
integer_types.o: $(SRC_DIR)/koans/integer_types.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koans/integer_types.cpp
pointers.o: $(SRC_DIR)/koans/pointers.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koans/pointers.cpp
arrays.o: $(SRC_DIR)/koans/arrays.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koans/arrays.cpp
strings.o: $(SRC_DIR)/koans/strings.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $(SRC_DIR)/koans/strings.cpp

cppkoans: cppkoans.o koangtestprinter.o pathtoenlightenment.o introduction.o characters.o integer_types.o booleans.o pointers.o arrays.o strings.o gtest.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

run:
	@echo "make: autorun of cppkoans:"
	@./cppkoans