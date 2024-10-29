#include "../headers/vector_cpp.h"

TEST(Vector_test, Init1) {
  Vector<int> v(3);
  EXPECT_EQ(v.size(), 3);
}

TEST(Vector_test, Init2) {
  Vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.size(), 3);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}