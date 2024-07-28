CC := clang
CFLAGS := \
	-Wall -Wextra -pedantic \
	-std=c17
RM := rm -rf

C_FILES := $(wildcard *.c src/*.c)
C_OBJ_FILES := $(C_FILES:.c=.o)
C_LIBS :=

.PHONY: all
all: build

.PHONY: build
build: target/containers-from-scratch
target/containers-from-scratch: $(C_OBJ_FILES)
	@mkdir -p target
	$(CC) $(CFLAGS) $^ -o $@ $(C_LIBS)

.PHONY: clean
clean:
	$(RM) target/
	$(RM) $(C_OBJ_FILES)
