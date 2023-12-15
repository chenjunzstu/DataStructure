TARGET = main
SOURCES = main.c \
LinearList.c \
stack.c \
queue.c

CXX = gcc
CXXFLAGS = -Og -g
LDFLAGS = -lm

BUILD_DIR = build
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(SOURCES)))

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET): $(OBJECTS) Makefile
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

$(BUILD_DIR):
	mkdir -p $@		

clean:
	-rm -fR $(BUILD_DIR)
