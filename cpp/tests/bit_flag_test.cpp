#include "utils/bit_flag.h"

#include "gtest/gtest.h"

TEST(TestBitFlag, Test1)
{
    using Flag_default = BitFlag<uint8_t>;
    ASSERT_EQ(Flag_default(), 0b0000'0001);
    ASSERT_EQ(Flag_default::Next(), 0b0000'0010);
    ASSERT_EQ(Flag_default::Next::Next(), 0b0000'0100);
    ASSERT_EQ(Flag_default::Next::Next::Next(), 0b0000'1000);

    using Flag_set = BitFlag<uint8_t, 0>;
    ASSERT_EQ(Flag_set(), 0b0000'0001);
    ASSERT_EQ(Flag_set::Next(), 0b0000'0010);
    ASSERT_EQ(Flag_set::Next::Next(), 0b0000'0100);
    ASSERT_EQ(Flag_set::Next::Next::Next(), 0b0000'1000);

    using Flag1 = BitFlag<uint8_t,0>;
    using Flag2 = BitFlag<uint8_t,1>;
    using Flag3 = BitFlag<uint8_t,2>;
    using Flag4 = BitFlag<uint8_t,3>;
    using Flag5 = BitFlag<uint8_t,4>;
    using Flag6 = BitFlag<uint8_t,5>;
    using Flag7 = BitFlag<uint8_t,6>;
    using Flag8 = BitFlag<uint8_t,7>;
    ASSERT_EQ(Flag1(), 0b0000'0001);
    ASSERT_EQ(Flag2(), 0b0000'0010);
    ASSERT_EQ(Flag3(), 0b0000'0100);
    ASSERT_EQ(Flag4(), 0b0000'1000);
    ASSERT_EQ(Flag5(), 0b0001'0000);
    ASSERT_EQ(Flag6(), 0b0010'0000);
    ASSERT_EQ(Flag7(), 0b0100'0000);
    ASSERT_EQ(Flag8(), 0b1000'0000);
    /*
        using Flag9 = BitFlag<uint8_t,8>;
        ASSERT_DEATH(Flag9(), ".*"); // compilation error
    */
}