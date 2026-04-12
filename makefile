TARGET = programa
CXX = g++
CXXFLAGS = -Wall -std=c++17

SRCS = nodo.cpp lista.cpp main.cpp
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)