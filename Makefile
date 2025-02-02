CXX = g++
CXXFLAGS = -std=c++23 -I./include
LDFLAGS = -lftxui-component -lftxui-dom -lftxui-screen

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/*.cpp) cmd/main.cpp
OBJECTS = $(SOURCES:%.cpp=$(BUILD_DIR)/%.o)

TARGET = run

.PHONY: all clean

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

# Add dependency files
-include $(OBJECTS:.o=.d)

# Create dependency files
$(BUILD_DIR)/%.d: %.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -MM -MT "$(@:.d=.o) $@" $< > $@


