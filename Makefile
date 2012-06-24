CPPFLAGS = -Iinclude/

build : ImmutableVector.o

ImmutableVector.o : src/ImmutableVector.cpp
	$(CXX) -c $(CPPFLAGS) $< -o $@