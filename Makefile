CPPFLAGS = -Iinclude/
LIBS = -lcppunit
OBJS = Tester.o ImmutableVectorTest.o
VPATH = src:include:test

test : tester
	./tester

tester : $(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

Tester.o : Tester.cpp ImmutableVectorTest.o ImmutableVector.h
ImmutableVectorTest.o : ImmutableVectorTest.cpp ImmutableVectorTest.h ImmutableVector.h

clean :
	rm tester $(OBJS)

clean-emacs :
	find -type f -name '*~' -delete
