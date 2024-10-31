#include "../headers/vector_cpp.h"

TEST(Vector_test, Init1) {
  Vector<int> v(3);
  EXPECT_EQ(v.size(), 3);
}

TEST(Vector_test, Init2) {
  Vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.at(2), 3);
  EXPECT_EQ(v.size(), 3);
}

TEST(Vector_test, Init3) {
  Vector<int> v(10, 1);
  EXPECT_EQ(v.at(2), 1);
  EXPECT_EQ(v.size(), 10);
  EXPECT_EQ(v.capacity(), 10);
}

TEST(Vector_test, copy1) {
  Vector<int> v1 = {1, 2, 7, 5, 4};
  Vector<int> v2(v1);
  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.at(2), v2.at(2));
}

TEST(Vector_test, copy2) {
  Vector<int> v1 = {1, 2, 7, 5, 4};
  Vector<int> v2;
  v2 = v1;
  EXPECT_EQ(v1.at(2), v2.at(2));
}

TEST(Vector_test, begin) {
  Vector<int> v1 = {12, 2, 7, 5, 4};
  auto it = v1.begin();
  EXPECT_EQ(*it, v1.at(0));
}

TEST(Vector_test, end) {
  Vector<int> v1 = {12, 2, 7, 5, 4};
  auto it = v1.end();
  EXPECT_EQ(*it, 4);
}

TEST(Vector_test, push) {
  Vector<int> v1;
  v1.push_back(12);
  v1.push_back(13);
  v1.push_back(14);
  EXPECT_EQ(v1.at(0), 12);
}

TEST(Vector_test, insert) {
  Vector<int> v1;
  v1.push_back(12);
  v1.push_back(13);
  v1.push_back(14);
  v1.push_back(15);
  v1.push_back(16);
  v1.push_back(17);
  v1.push_back(18);
  v1.push_back(19);
  v1.push_back(20);
  auto it = v1.insert((v1.begin() + 3), 22);
  auto result = v1.begin() + 3;
  EXPECT_EQ(*result, *it);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}