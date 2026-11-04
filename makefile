# jellyfish
# BUILD SYSTEM

# NOTE
# This is a makefile written for me (schmalzl) building the jellyfish compiler and runtime on my machine.
# Since I use a Mac for development, this makefile might not work for Windows or Linux development environments.
# If you want to compile this project for yourself, make sure to use your compilers specified in #compilers.

# compilers
CXX = g++
MAC_CXX = clang++
WIN_CXX = x86_64-w64-mingw32-g++
LINUX_CXX = x86_64-linux-musl-g++

# debug build flags
CXXFLAGS = -std=c++20 -O2 -Wall -Wextra -Wpedantic -Wshadow -Wformat=2
LDFLAGS =
# release build flags
RELEASE_FLAGS = -std=c++20 -O3 -DNDEBUG -flto \
                -ffunction-sections -fdata-sections \
                -Wall -Wextra -Wpedantic

MAC_LDFLAGS = -flto -Wl,-dead_strip
WIN_LDFLAGS = -flto -Wl,--gc-sections
LINUX_LDFLAGS = -flto -Wl,--gc-sections

# directories
SRC_DIR = src
RT_DIR = runtime
BIN_DIR = bin
RELEASE_DIR = release

# executables
JF = $(BIN_DIR)/jellyfishc
RT = $(BIN_DIR)/rt

# Source files (recursive)
JF_SOURCES = $(shell find $(SRC_DIR) -type f \( -name "*.cpp" -o -name "*.cc" -o -name "*.cxx" \))
RT_SOURCES = $(shell find $(RT_DIR) -type f \( -name "*.cpp" -o -name "*.cc" -o -name "*.cxx" \))

# dev
.PHONY: all clean mac win linux release release-mac release-win release-linux

all: $(JF) $(RT)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(JF): $(JF_SOURCES) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(JF_SOURCES) -o $(JF) $(LDFLAGS)

$(RT): $(RT_SOURCES) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(RT_SOURCES) -o $(RT) $(LDFLAGS)

# macos release
mac: release-mac

release-mac:
	mkdir -p $(RELEASE_DIR)/mac
	$(MAC_CXX) $(RELEASE_FLAGS) $(JF_SOURCES) -o $(RELEASE_DIR)/mac/jf $(MAC_LDFLAGS)
	$(MAC_CXX) $(RELEASE_FLAGS) $(RT_SOURCES) -o $(RELEASE_DIR)/mac/rt $(MAC_LDFLAGS)

# windows release

win: release-win

release-win:
	mkdir -p $(RELEASE_DIR)/win
	$(WIN_CXX) $(RELEASE_FLAGS) $(JF_SOURCES) -o $(RELEASE_DIR)/win/jf.exe $(WIN_LDFLAGS)
	$(WIN_CXX) $(RELEASE_FLAGS) $(RT_SOURCES) -o $(RELEASE_DIR)/win/rt.exe $(WIN_LDFLAGS)

# linux release

linux: release-linux

release-linux:
	mkdir -p $(RELEASE_DIR)/linux
	$(LINUX_CXX) $(RELEASE_FLAGS) $(JF_SOURCES) -o $(RELEASE_DIR)/linux/jf $(LINUX_LDFLAGS)
	$(LINUX_CXX) $(RELEASE_FLAGS) $(RT_SOURCES) -o $(RELEASE_DIR)/linux/rt $(LINUX_LDFLAGS)

# all platforms

release: mac win linux

# clean

clean:
	rm -rf $(BIN_DIR) $(RELEASE_DIR)
