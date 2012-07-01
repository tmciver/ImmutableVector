CPPFLAGS = -Iinclude/
LIBS = -lcppunit
OBJS = Tester.o ImmutableVectorTest.o
VPATH = src:include:test

tester : $(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

Tester.o : Tester.cpp ImmutableVector.h
ImmutableVectorTest.o : ImmutableVectorTest.cpp ImmutableVectorTest.h ImmutableVector.h

clean :
	rm tester $(OBJS)

clean-emacs :
	find -type f -name '*~' -delete
