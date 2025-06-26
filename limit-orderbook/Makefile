CXX = clang++
CXXFLAGS = -g -fsanitize=address -fno-omit-frame-pointer -Werror -std=c++17
TARGET = main.out
SRC = ./*.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) -Wall -std=c++17

clean:
	rm $(TARGET)