#include "ImmutableVectorTest.h"
#include "ImmutableVector.h"

#include <stdint.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;

void ImmutableVectorTest::indexTest() {
  uint8_t data[] = {1, 2, 3, 4, 5};
  ImmutableVector<uint8_t> iv(data, sizeof(data));
  //  cout << endl << "iv.size() = " << iv.size() << endl << "iv[5] = " << (int)iv[5] << endl;
  CPPUNIT_ASSERT(iv[0] == 1);
  CPPUNIT_ASSERT(iv[1] == 2);
  CPPUNIT_ASSERT(iv[2] == 3);
  CPPUNIT_ASSERT(iv[3] == 4);
  CPPUNIT_ASSERT(iv[4] == 5);
}
