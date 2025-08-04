CC = gcc
CFLAGS = -g -Wall -Iinclude
LIBS = -lraylib -lm -lpthread -ldl -lX11

SRC_DIR = src
INCLUDE_DIR = include
SRCS := $(shell find $(SRC_DIR) -name '*.c')
LIB_SRCS := $(shell find $(INCLUDE_DIR) -name '*.c' ! -name 'clay_renderer_raylib.c')
ALL_SRCS := $(SRCS) $(LIB_SRCS)
OBJS := $(patsubst %.c,build/%.o,$(subst src/,src/,$(ALL_SRCS)))
OBJS := $(patsubst include/%,build/include/%,$(OBJS))
TARGET = build/uvmod

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(dir $(TARGET))
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/*
