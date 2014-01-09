GTEST_DIR = ../../gtest
INC_DIR = ../../src
SRC_DIR = ../../src
INCLUDES = $(wildcard ${INC_DIR}/*.h)
# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread -pedantic-errors -std=c++11

SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/koans/*.cpp)
OBJS := $(patsubst %.cpp, %.o, $(subst $(SRC_DIR)/, , $(SRCS)))

.PHONY: all
all: cppkoans run

.PHONY: clean
clean:
	rm -f cppkoans *.o koans/*.o gtest.a


# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

%.o: $(SRC_DIR)/%.cpp ${INCLUDES}
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $< -o $@

koans/%.o: $(SRC_DIR)/koans/%.cpp ${INCLUDES} koans/
	$(CXX) $(CPPFLAGS) -I$(INC_DIR) -isystem ${GTEST_INC_DIR} $(CXXFLAGS) -c $< -o $@

koans/:
	mkdir koans

.PHONY: cppkoans
cppkoans: $(OBJS) gtest.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

.PHONY: run
run:
	@echo "make: autorun of cppkoans:"
	@./cppkoans

test-compileable:
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c tmp.cpp >tmp.log 2>&1

