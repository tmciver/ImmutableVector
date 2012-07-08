#pragma once

#include <stdexcept>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class ImmutableVectorTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(ImmutableVectorTest);
  CPPUNIT_TEST(indexTest);
  CPPUNIT_TEST(copyTest);
  CPPUNIT_TEST(exceptionTest);
  CPPUNIT_TEST(dataTest);
  CPPUNIT_TEST_SUITE_END();

 protected:
  void indexTest();
  void copyTest();
  void exceptionTest();
  void dataTest();
};
