#include "ImmutableVectorTest.h"
#include "ImmutableVector.h"

#include <stdint.h>
#include <stdexcept>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;

void ImmutableVectorTest::indexTest() {
  uint8_t data[] = {1, 2, 3, 4, 5};
  ImmutableVector<uint8_t> iv(data, sizeof(data));
  CPPUNIT_ASSERT(iv[0] == 1);
  CPPUNIT_ASSERT(iv[1] == 2);
  CPPUNIT_ASSERT(iv[2] == 3);
  CPPUNIT_ASSERT(iv[3] == 4);
  CPPUNIT_ASSERT(iv[4] == 5);
}

void ImmutableVectorTest::copyTest() {
  uint8_t data[] = {1, 2, 3, 4, 5};
  ImmutableVector<uint8_t> iv(data, sizeof(data));

  // make a copy
  ImmutableVector<uint8_t> iv2(iv);
  CPPUNIT_ASSERT(iv2.data() == iv.data());
}

/*
 * Ideally, this test would verify that the reference count in IVData was being
 * incremented and decremented appropriately but this would require adding the
 * ability to access this otherwise private data, which is something I don't
 * want to do. Suffice it to say that, at the time of writing this test, some
 * print debugging indicated that the reference count was indeeding being
 * updated in the correct way.
 */
void ImmutableVectorTest::assignmentTest() {
  uint8_t data[] = {1, 2, 3, 4, 5};
  ImmutableVector<uint8_t> iv1(data, sizeof(data));
  uint8_t data2[] = {6, 7, 8, 9, 10};
  ImmutableVector<uint8_t> iv2(data2, sizeof(data2));

  // do a copy assignment
  ImmutableVector<uint8_t> iv3 = iv1;

  // reassign iv3
  iv3 = iv2;
}

void ImmutableVectorTest::exceptionTest() {
  uint8_t data[] = {1, 2, 3, 4, 5};
  ImmutableVector<uint8_t> iv(data, sizeof(data));
  CPPUNIT_ASSERT_THROW(iv[5], out_of_range);
}

void ImmutableVectorTest::dataTest() {
  uint8_t data[] = {1, 2, 3, 4, 5};
  ImmutableVector<uint8_t> iv(data, sizeof(data));
  
  // get a pointer to the underlying data
  const uint8_t *theData = iv.data();

  // make sure that this data is the same as the data we passed in
  CPPUNIT_ASSERT(theData[0] == 1);
  CPPUNIT_ASSERT(theData[1] == 2);
  CPPUNIT_ASSERT(theData[2] == 3);
  CPPUNIT_ASSERT(theData[3] == 4);
  CPPUNIT_ASSERT(theData[4] == 5);
}
