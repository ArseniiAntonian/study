#include <gtest/gtest.h>
#include "long_number.hpp"

TEST(get_digits_number, check_positive) {
AAntonian::LongNumber x("12345");
EXPECT_EQ(5, x.get_digits_number())
<< "Неправильно подсчитано количество разрядов в числе " << x;
}

TEST(get_digits_number, check_negative) {
AAntonian::LongNumber x("-1");
EXPECT_EQ(1, x.get_digits_number())
<< "Неправильно подсчитано количество разрядов в числе " << x;
}

class EqualityFixture : public testing::Test {
public:
    AAntonian::LongNumber one_v1 = AAntonian::LongNumber("1");
    AAntonian::LongNumber one_v2 = AAntonian::LongNumber("1");
    AAntonian::LongNumber seven = AAntonian::LongNumber("7");
    AAntonian::LongNumber eleven = AAntonian::LongNumber("11");
    AAntonian::LongNumber twelve = AAntonian::LongNumber("12");
    AAntonian::LongNumber negative_one = AAntonian::LongNumber("-1");
    AAntonian::LongNumber hundred = AAntonian::LongNumber("1000");
    AAntonian::LongNumber num_1 = AAntonian::LongNumber("143043646467550005435000");
    AAntonian::LongNumber num_2 = AAntonian::LongNumber("143043646467550005435000000");
    AAntonian::LongNumber num_3 = AAntonian::LongNumber("143043646467267836806260550005435000");
};

TEST_F(EqualityFixture, equal) {
ASSERT_TRUE(one_v1 == one_v2) << "Проверка " << one_v1 << " == " << one_v2;
}

TEST_F(EqualityFixture, not_equal) {
ASSERT_FALSE(one_v1 == twelve) << "Проверка " << one_v1 << " == " << twelve;
}

TEST_F(EqualityFixture, not_equal_negative_var) {
ASSERT_FALSE(one_v1 == negative_one)
<< "Проверка " << one_v1 << " == " << negative_one;
}

TEST_F(EqualityFixture, less) {
EXPECT_LT(one_v1 , twelve) << "Проверка " << one_v1 << " < " << twelve;
}

TEST_F(EqualityFixture, great) {
EXPECT_GT(twelve, one_v1) << "Проверка " << twelve << " > " << one_v1;
}

TEST_F(EqualityFixture, sum) {
AAntonian::LongNumber result = one_v1 + eleven;
EXPECT_EQ(result , twelve) << "Проверка " << one_v1 << " + " << eleven << " = " << twelve;
}

TEST_F(EqualityFixture, diff) {
AAntonian::LongNumber result = twelve - one_v1;
EXPECT_EQ(result , eleven) << "Проверка " << twelve << " - " << eleven << " = " << eleven;
}

TEST_F(EqualityFixture, multiplie) {
AAntonian::LongNumber result = hundred * num_1;
EXPECT_EQ(result , num_2) << "Проверка " << hundred << " * " << num_1 << " = " << num_2;
}

TEST_F(EqualityFixture, module) {
AAntonian::LongNumber result = num_3 % eleven;
EXPECT_EQ(result , seven) << "Проверка " << num_3 << " - " << eleven << " = " << seven;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}