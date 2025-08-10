# Windows-compatible Makefile for SFML with MinGW
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -Iinclude -Ilibs/include
LDFLAGS := -Llibs/lib -lsfml-graphics -lsfml-window -lsfml-system

# For debug builds, add -g and use debug libraries
# LDFLAGS := -Llibs/lib -lsfml-graphics-d -lsfml-window-d -lsfml-system-d

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
TARGET := $(BIN_DIR)/app.exe

SRCS := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard main.cpp)
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)"
	$(CXX) $^ $(LDFLAGS) -o $@
	@if exist "libs\bin\*.dll" copy "libs\bin\*.dll" "$(BIN_DIR)" > nul

$(BUILD_DIR)/%.o: %.cpp
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if exist "$(BUILD_DIR)" rmdir /s /q "$(BUILD_DIR)"
	@if exist "$(TARGET)" del /q "$(TARGET)"
	@if exist "$(BIN_DIR)\*.dll" del /q "$(BIN_DIR)\*.dll"

run: all
	$(TARGET)
