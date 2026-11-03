CXX = g++
CXXFLAGS = -std=c++20 -O2 -Wall -Wextra -Wpedantic
LDFLAGS =

SRC_DIR = src
RT_DIR = runtime
BIN_DIR = bin

JF = $(BIN_DIR)/jf.exe
RT = $(BIN_DIR)/rt.exe

JF_SOURCES = $(shell find $(SRC_DIR) -type f \( -name "*.cpp" -o -name "*.cc" -o -name "*.cxx" \))
RT_SOURCES = $(shell find $(RT_DIR) -type f \( -name "*.cpp" -o -name "*.cc" -o -name "*.cxx" \))

.PHONY: all clean

all: $(JF) $(RT)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(JF): $(JF_SOURCES) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(JF_SOURCES) -o $(JF) $(LDFLAGS)

$(RT): $(RT_SOURCES) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(RT_SOURCES) -o $(RT) $(LDFLAGS)

clean:
	rm -rf $(BIN_DIR)
