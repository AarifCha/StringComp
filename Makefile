CXX = g++
CXXFLAGS = -std=c++11 -Wall
SOURCES = Matrix.cpp Testing.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = Testing

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
