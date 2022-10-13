# sets the compiler to gcc and includes the flags -Wall -g and -lm in the compilation
CC=gcc
CFLAGS=-g
LFLAGS=-lm
TARGET=out

# automatically finds the source files
C_SRCS := \
  $(wildcard *.c) \
  $(wildcard src/*.c) \
  $(wildcard src/**/*.c)

# automatically finds the header files
HDRS := \
  $(wildcard *.h) \
  $(wildcard src/*.h) \
  $(wildcard src/**/*.h)

# creates the object files and places them in /bin so the main directory doesn't get cluttered
OBJS := $(patsubst %.c, bin/%.o, $(wildcard *.c))
OBJS += $(filter %.o, $(patsubst src/%.c, bin/%.o, $(C_SRCS)))

# sets the make all command
all: build
	@echo "All Done"

# this is the build target, it compiles the program
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

# creates the /bin directory if necessary
bin/%.o: %.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# same as the last one but it checks the src directory instead
bin/%.o: src/%.c $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# command to remove all files created by compilation
clean:
	rm -f $(TARGET)
	rm -rf bin

# command to run the program
run: build
	./$(TARGET)

# command to print the list of automatically found sources, headers, and object files
which:
	@echo "FOUND SOURCES: ${C_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "TARGET OBJS: ${OBJS}"