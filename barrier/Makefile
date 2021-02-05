CXX = g++
CXXFLAGS = -g -pthread -std=c++17 -D_XOPEN_SOURCE

ifeq ($(OS),Windows_NT)   
    detected_OS := Windows
else
    detected_OS := $(shell uname)
endif
# Print out the detected OS
$(info Detected OS is: $(detected_OS))

# Default to regular Linux library
LIBTHREAD = libthread.o

# Use Mac library if on Mac
ifeq ($(detected_OS),Darwin)  # Important to not have a space after the comma
    LIBTHREAD = libthread_macos.o
endif

LDFLAGS = -ldl $(LIBTHREAD)

# Executable. Cpp file must match this.
EXEC = barrier
EXEC2 = barrier_reuse

# Simple example where we can set a breakpoint, do prints, and basics
$(EXEC): $(LIBTHREAD) $(EXEC).cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(EXEC).cpp -o $(EXEC)

reuse: $(LIBTHREAD) $(EXEC2).cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(EXEC2).cpp -o $(EXEC2)

clean:
	rm $(EXEC) $(EXEC2)

.PHONY: clean

