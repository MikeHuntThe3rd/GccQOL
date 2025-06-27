# === Configuration ===
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -Iinclude
AR := ar
ARFLAGS := rcs

# === Directories ===
SRC_DIR := src
INC_DIR := include
OBJ_DIR := build
ROOT_DIR := $(notdir $(CURDIR))
LIB_NAME := $(OBJ_DIR)/lib$(ROOT_DIR).a

# === Source and Object Files ===
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# === Default target ===
.PHONY: all clean

all: $(LIB_NAME)
#create files
init:
	@if not exist "$(INC_DIR)" (mkdir "$(INC_DIR)" && echo Created $(INC_DIR))
	@if not exist "$(SRC_DIR)" (mkdir "$(SRC_DIR)" && echo Created $(SRC_DIR))
	@if not exist "$(INC_DIR)/$(ROOT_DIR).h" ( \
		echo #ifndef MYLIB_H >> "$(INC_DIR)/$(ROOT_DIR).h" && \
		echo #define MYLIB_H >> "$(INC_DIR)/$(ROOT_DIR).h" && \
		echo #endif >> "$(INC_DIR)/$(ROOT_DIR).h" && \
		echo Created $(INC_DIR)/$(ROOT_DIR).h \
	)
# Create the static library
$(LIB_NAME): $(OBJS)
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
	$(AR) $(ARFLAGS) $@ $^

# Compile source to object
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule (Windows-compatible)
clean:
	if exist $(OBJ_DIR) rmdir /S /Q $(OBJ_DIR)
	if exist $(LIB_NAME) del $(LIB_NAME)
