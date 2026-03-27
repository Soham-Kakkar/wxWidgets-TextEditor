# Compiler and flags
CXX = g++
CXXFLAGS = `wx-config --cxxflags`
LDFLAGS = `wx-config --libs` -xrc

# Directories
SRC_DIR = src
BUILD_DIR = build
RES_DIR = $(SRC_DIR)/resources

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
EXEC = $(BUILD_DIR)/MyWxApp

all: release

# Target for debugging build
debug: $(SRC_FILES)
	$(CXX) -DDEBUG $(CXXFLAGS) $(SRC_FILES) -o $(EXEC) $(LDFLAGS)

# Target for release build
release: $(SRC_FILES)
	sh wxrc.sh      
	sh get_deps.sh  
	$(CXX) -O2 $(CXXFLAGS) $(SRC_FILES) -o $(EXEC) $(LDFLAGS)

# Clean up executable and generated files
clean:
	rm -f $(EXEC)
	rm -f $(RES_DIR)/*.hpp $(RES_DIR)/*.h