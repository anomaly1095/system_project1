# Flags for compilation
MAIN_FLAGS = -Wno-implicit-function-declaration

# Flags for linking (includes OpenSSL)
FINAL_FLAGS = -g -lssl -lcrypto

# Define source directory
SRC = src

# Define build directory (change 'bin' if needed)
BIN = bin

# Default target
all: final

# Build the final executable
final: main.o _strings_.o
	@echo "Linking final app"
	gcc -o $(BIN)/final $(BIN)/main.o $(BIN)/_strings_.o $(FINAL_FLAGS)
	@chmod +x $(BIN)/final
	@echo "done"

# Compile main.c
main.o: $(SRC)/main.c
	@echo "Compiling main file"
	gcc $(MAIN_FLAGS) -c $(SRC)/main.c -o $(BIN)/main.o -g

# Compile _strings_.c
_strings_.o: $(SRC)/_strings_.c
	@echo "Compiling _strings_ file"
	gcc -c $(SRC)/_strings_.c -o $(BIN)/_strings_.o 

# Clean up object files
clean:
	@echo "Cleaning up .o files"
	rm -f $(BIN)/*.o