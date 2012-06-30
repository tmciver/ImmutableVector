#pragma once

//#include "ImmutableVector.h"
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;

class ImmutableVectorTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE (ImmutableVectorTest);
  CPPUNIT_TEST (indexTest);
  CPPUNIT_TEST_SUITE_END();

 protected:
  void indexTest();
};
