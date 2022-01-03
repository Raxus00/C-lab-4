CPP:= g++
CPPFLAGS := -Werror -Wpedantic -Wall -Wextra -std=c++17

ifeq ($(OS),Windows_NT)
	BIN := bin\\
	BUILD := build\\
	SOURCE := source\\
	INCLUDE := include\\
	DEL:= del

	EXECUTABLE := Assignment4.exe
else
	BIN := bin/
	BUILD := build/
	SOURCE := source/
	INCLUDE := include/
	DEL:= rm

	EXECUTABLE := Assignment4
endif

all: $(BUILD)Main.o $(BUILD)PersonData.o
	$(CPP) $(CPPFLAGS) $(BUILD)Main.o $(BUILD)PersonData.o -o $(BIN)$(EXECUTABLE)

$(BUILD)Main.o: $(SOURCE)Main.cpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)Main.cpp -I $(INCLUDE) -o $(BUILD)Main.o

$(BUILD)PersonData.o: $(SOURCE)PersonData.cpp $(INCLUDE)PersonData.hpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)PersonData.cpp -I $(INCLUDE) -o $(BUILD)PersonData.o

clean:
	$(DEL) $(BUILD)Main.o
	$(DEL) $(BUILD)PersonData.o
	$(DEL) $(BIN) $(EXECUTABLE)