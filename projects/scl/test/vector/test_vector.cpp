#include "vector.hpp"
#include <gtest/gtest.h>

using namespace AAntonian;

TEST(VectorTest, DefaultConstructor) {
    Vector<int> vec;
    EXPECT_EQ(vec.size(), 0);
}

TEST(VectorTest, PushBackAndSize) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec.size(), 3);
}

TEST(VectorTest, HasItem) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_TRUE(vec.has_item(2));
    EXPECT_FALSE(vec.has_item(4));
}

TEST(VectorTest, Insert) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.insert(1, 5);
    EXPECT_EQ(vec.size(), 4);
    vec.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 5 2 3 ");
}

TEST(VectorTest, Print) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    testing::internal::CaptureStdout();
    vec.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3 ");
}

TEST(VectorTest, RemoveFirst) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_TRUE(vec.remove_first(2));
    EXPECT_EQ(vec.size(), 2);
    EXPECT_FALSE(vec.has_item(2));
}