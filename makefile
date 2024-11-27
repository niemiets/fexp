CPPFLAGS :=
CFLAGS := 
LDFLAGS := -lncurses -DNCURSES_STATIC
LDLIBS :=

SRC_DIR := ./src
OBJ_DIR := ./obj
BUILD_DIR := ./build

EXE := $(BUILD_DIR)/main

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

.PHONY: default all clean

default: all

all: $(EXE)

$(EXE): $(OBJS) | $(BUILD_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BUILD_DIR) $(OBJ_DIR)

-include $(OBJS:.o=.d)