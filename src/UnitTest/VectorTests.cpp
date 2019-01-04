//-----------------------------------------------------------------------------
// Filename: VectorTests.cpp
// Project: UnitTest
// Author: Chris Ubben
// Creation Date: 2018/12/27
//-----------------------------------------------------------------------------

// Precompiled Headers
#include "pch.h"

using namespace PolygonalMath;

#pragma region Vec2Tests

#pragma region StaticMemberTests
TEST(Vec2Tests, Vec2IntZeroTest) {
    Vec2<int> zeroVec = Vec2<int>::Zero();
    EXPECT_EQ(zeroVec.x, 0);
    EXPECT_EQ(zeroVec.y, 0);
}
#pragma endregion StaticMemberTests

#pragma region ConstructorTests
TEST(Vec2Tests, Vec2IntDefaultConstructorTest) {
    Vec2<int> v1 = Vec2<int>();
    EXPECT_EQ(v1.x, 0);
    EXPECT_EQ(v1.y, 0);
}

TEST(Vec2Tests, Vec2IntComponentConstructorTest) {
    Vec2<int> v2 = Vec2<int>(1, 2);
    EXPECT_EQ(v2.x, 1);
    EXPECT_EQ(v2.y, 2);
}

TEST(Vec2Tests, Vec2IntInitializerListConstructorTest) {
    Vec2<int> v3{ 1, 2 };
    EXPECT_EQ(v3.x, 1);
    EXPECT_EQ(v3.y, 2);
}

TEST(Vec2Tests, Vec2IntCopyConstructorTest) {
    Vec2<int> v4 = Vec2<int>(1, 2);
    Vec2<int> v4_copy = Vec2<int>(v4);
    EXPECT_EQ(v4_copy.x, 1);
    EXPECT_EQ(v4_copy.y, 2);
    EXPECT_EQ(v4, v4_copy);
}

TEST(Vec2Tests, Vec2IntConversionConstructorTest) {
    std::array<int, 2> a1{ 1, 2 };
    Vec2<int> v5 = Vec2<int>(a1);
    EXPECT_EQ(v5.x, 1);
    EXPECT_EQ(v5.y, 2);
}
#pragma endregion ConstructorTests

#pragma endregion Vec2Tests
