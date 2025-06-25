# Compiler settings
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11 -Iinclude
TARGET := run.exe

# Library configuration
LIB_DIR := libs
LDFLAGS := -L$(LIB_DIR)
LDLIBS := $(patsubst lib%.a,-l%,$(wildcard $(LIB_DIR)/lib*.a))  # Static libs
LDLIBS += $(patsubst lib%.dll.a,-l%,$(wildcard $(LIB_DIR)/lib*.dll.a))  # DLL import libs
LDLIBS += $(patsubst %.lib,-l%,$(wildcard $(LIB_DIR)/*.lib))  # Windows static libs

# Folder structure
SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj

# Auto-discover files
SRCS := main.cpp $(wildcard $(SRC_DIR)/*.cpp)
HEADERS := $(wildcard $(INCLUDE_DIR)/*.h)
OBJS := $(patsubst %.cpp,$(OBJ_DIR)/%.obj,$(notdir $(SRCS)))

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJ_DIR)/%.obj: %.cpp $(HEADERS)
	@if not exist "$(subst /,\,$(@D))" mkdir "$(subst /,\,$(@D))"
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.obj: $(SRC_DIR)/%.cpp $(HEADERS)
	@if not exist "$(subst /,\,$(@D))" mkdir "$(subst /,\,$(@D))"
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	@if exist "$(subst /,\,$(OBJ_DIR))" rmdir /S /Q "$(subst /,\,$(OBJ_DIR))"
	@if exist "$(TARGET)" del "$(subst /,\,$(TARGET))"

-include $(OBJS:.obj=.d)

.PHONY: all clean