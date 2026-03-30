# Compiler and flags
CXX = g++
CXXFLAGS = $(shell wx-config --cxxflags)
LDFLAGS = $(shell wx-config --libs)

# Directories
SRC_DIR = src
BUILD_DIR_DEBUG = build/debug
BUILD_DIR_RELEASE = build/release
OBJ_DIR_DEBUG = $(BUILD_DIR_DEBUG)/obj
OBJ_DIR_RELEASE = $(BUILD_DIR_RELEASE)/obj
RES_DIR = $(SRC_DIR)/resources

EXEC_DEBUG = $(BUILD_DIR_DEBUG)/MyWxApp
EXEC_RELEASE = $(BUILD_DIR_RELEASE)/MyWxApp

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_DEBUG_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR_DEBUG)/%.o,$(SRC_FILES))
OBJ_RELEASE_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR_RELEASE)/%.o,$(SRC_FILES))

# XRC files
XRC_FILES = $(wildcard $(RES_DIR)/*.xrc)
XRC_HEADERS = $(XRC_FILES:.xrc=.hpp)

# Default target
all: debug

# Ensure directories exist
$(BUILD_DIR_DEBUG):
	mkdir -p $(BUILD_DIR_DEBUG)

$(BUILD_DIR_RELEASE):
	mkdir -p $(BUILD_DIR_RELEASE)

# Ensure object directories exist
$(OBJ_DIR_DEBUG):
	mkdir -p $(OBJ_DIR_DEBUG)

$(OBJ_DIR_RELEASE):
	mkdir -p $(OBJ_DIR_RELEASE)

# Compile source files to object files
$(OBJ_DIR_DEBUG)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR_DEBUG)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR_RELEASE)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR_RELEASE)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile XRC to headers
$(RES_DIR)/%.hpp: $(RES_DIR)/%.xrc
	@echo "Compiling XRC: $<"
	wxrc $< -c -o $@

# Link executable
$(EXEC_DEBUG): $(OBJ_DEBUG_FILES) | $(BUILD_DIR_DEBUG)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(EXEC_RELEASE): $(OBJ_RELEASE_FILES) | $(BUILD_DIR_RELEASE)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: $(EXEC_DEBUG)

# Release build (with embedded XRC)
release: CXXFLAGS += -O2
release: $(XRC_HEADERS) $(EXEC_RELEASE)

# Clean
clean:
	rm -rf $(BUILD_DIR_DEBUG) $(BUILD_DIR_RELEASE)
	rm -f $(RES_DIR)/*.hpp

# Phony targets
.PHONY: all release debug clean