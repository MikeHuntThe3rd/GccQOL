# === Compiler and Flags ===
CXX := g++
CXXFLAGS := -Wall -Wextra
LDFLAGS :=

# === Directories ===
SRC_DIR := src
INC_DIR := include
BUILD_DIR := build
LIBS_DIR := libs

# === Target ===
TARGET := app.exe

# === Detect project source files ===
SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard main.cpp)
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))

# === Detect valid libraries ===
LIB_DIRS := $(wildcard $(LIBS_DIR)/*)
LIB_BUILD_DIRS := $(foreach dir,$(LIB_DIRS),$(wildcard $(dir)/build))
VALID_LIBS := $(foreach dir,$(LIB_BUILD_DIRS),$(patsubst %/build,%,$(dir)))

# === Includes and linking ===
LIB_INCLUDES := $(foreach dir,$(VALID_LIBS),-I$(dir)/include)
LIB_LINK_DIRS := $(foreach dir,$(VALID_LIBS),-L$(dir)/build)
LIB_NAMES := $(foreach dir,$(notdir $(VALID_LIBS)),-l$(dir))

CXXFLAGS += -I$(INC_DIR) $(LIB_INCLUDES)
LDFLAGS += $(LIB_LINK_DIRS) $(LIB_NAMES)

# === Build Rules ===
.PHONY: all clean debug init

all: init $(TARGET)

# Step 1: Ensure folders and main.cpp exist
init:
	@if not exist "$(INC_DIR)" mkdir "$(INC_DIR)" && echo Created include/
	@if not exist "$(SRC_DIR)" mkdir "$(SRC_DIR)" && echo Created src/
	@if not exist "$(LIBS_DIR)" mkdir "$(LIBS_DIR)" && echo Created libs/
	@if not exist "main.cpp" type nul > main.cpp && echo Created empty main.cpp

# Step 2: Build the app
$(TARGET): $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@

# Compile main.cpp
$(BUILD_DIR)/%.o: %.cpp
	@if not exist "$(subst /,\,$(BUILD_DIR))" mkdir "$(subst /,\,$(BUILD_DIR))"
	$(CXX) $(CXXFLAGS) -c $< -o $(subst /,\,$@)

# Compile src/*.cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(subst /,\,$(BUILD_DIR))" mkdir "$(subst /,\,$(BUILD_DIR))"
	$(CXX) $(CXXFLAGS) -c $< -o $(subst /,\,$@)

# Clean
clean:
	@if exist "$(subst /,\,$(BUILD_DIR))" rmdir /s /q "$(subst /,\,$(BUILD_DIR))"
	@if exist "$(TARGET)" del /f /q "$(TARGET)"

# Debug
debug:
	@echo LIB_DIRS = $(LIB_DIRS)
	@echo VALID_LIBS = $(VALID_LIBS)
	@echo LIB_INCLUDES = $(LIB_INCLUDES)
	@echo LIB_LINK_DIRS = $(LIB_LINK_DIRS)
	@echo LIB_NAMES = $(LIB_NAMES)
	@echo OBJS = $(OBJS)
