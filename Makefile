# ===== Basic compiler setup =====
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# ===== Directory structure =====
SRC_DIR = src
BIN_DIR = bin

# ===== Ensure bin exists =====
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# ===== Rule: build each test =====
# Example: make dynamic_array/test
# Compiles src/dynamic_array/test.cpp + src/dynamic_array/dynamic_array.cpp -> bin/dynamic_array
%/test: | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/$*/test.cpp $(SRC_DIR)/$*/$*.cpp -o $(BIN_DIR)/$*
	@echo "Built $@ → Run it with ./bin/$*"

# ===== Clean =====
clean:
	rm -rf $(BIN_DIR)/*

.PHONY: clean
